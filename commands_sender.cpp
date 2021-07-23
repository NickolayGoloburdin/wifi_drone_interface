#include "commands_sender.h"


// Qt
#include <QtMath>
#include <QDebug>
#include <QThread>

using namespace domain;
CommandsSender::CommandsSender(MavLinkCommunicator* communicator):
    QObject(communicator),
    m_communicator(communicator){
    Q_ASSERT(communicator);
}
void CommandsSender::wait_ack_message(){
    while (command_ack_ == false) {
        QThread::msleep(8);
      }
      command_ack_ = false;
}
void CommandsSender::wait_mission_message() {
    while (mission_req_ == false) {
      QThread::msleep(8);
    }
    mission_req_ = false;
 }
void CommandsSender::wait_ack_mission_message(){
    while (mission_ack_ == false) {
      QThread::msleep(8);
    }
    mission_ack_ = false;
}
void CommandsSender::mission_request_handler(mavlink_mission_request_t mission_req){
    if (mission_req.seq >50 ){return;}
      mavlink_message_t message;
    //wait_mission_message();
      mavlink_msg_mission_item_int_encode(system_id_, component_id_, &message, &waypoints[mission_req.seq]);
      m_communicator->sendMessageOnAllLinks(message);
      count_++;
    //  if (count_ == 3){
      //int b=1;
      //}

}
void CommandsSender::command_ack_handler(){

}
void CommandsSender::mission_ack_handler(int type){

}
void CommandsSender::send_arm(){

    mavlink_command_long_t set_mode = {0};
      set_mode.target_system = target_system_id_;
      set_mode.target_component = target_component_id_all_;
      set_mode.command = MAV_CMD_COMPONENT_ARM_DISARM; // 176
      set_mode.confirmation = 0;
      set_mode.param1 = 1;
      mavlink_message_t message;
      mavlink_msg_command_long_encode(system_id_, component_id_, &message,
                                      &set_mode);
      m_communicator->sendMessageOnAllLinks(message);
}
void CommandsSender::send_disarm(){
    mavlink_command_long_t set_mode = {0};
      set_mode.target_system = target_system_id_;
      set_mode.target_component = target_component_id_all_;
      set_mode.command = MAV_CMD_COMPONENT_ARM_DISARM; // 176
      set_mode.confirmation = 0;
      set_mode.param1 = 0;
      mavlink_message_t message;
      mavlink_msg_command_long_encode(system_id_, component_id_, &message,
                                      &set_mode);
      m_communicator->sendMessageOnAllLinks(message);

}
void CommandsSender::form_send_fly_mission(int x, int y, int x_land, int y_land,float height_takeoff,float height_point,float height_land){

      waypoints.clear();
      mavlink_mission_item_int_t set_home = {0};
      set_home.command = MAV_CMD_NAV_TAKEOFF;
      set_home.param1 = 0;
      set_home.autocontinue = 1;
      set_home.frame = MAV_FRAME_GLOBAL_RELATIVE_ALT;
      set_home.seq = 0;
      set_home.target_system = target_system_id_;
      set_home.target_component = target_component_id_autopilot_;
      waypoints.push_back(set_home);

      mavlink_mission_item_int_t takeoff = {0};
      takeoff.command = MAV_CMD_NAV_TAKEOFF;
      takeoff.z = height_takeoff;
      takeoff.autocontinue = 1;
      takeoff.frame = MAV_FRAME_GLOBAL_RELATIVE_ALT;
      takeoff.seq = 1;
      takeoff.target_system = target_system_id_;
      takeoff.target_component = target_component_id_autopilot_;
      waypoints.push_back(takeoff);

      mavlink_mission_item_int_t waypoint = {0};
      waypoint.command = MAV_CMD_NAV_WAYPOINT;
      waypoint.param1 = 0;
      waypoint.z = height_point;
      waypoint.x = x;
      waypoint.y = y;
      waypoint.autocontinue = 1;
      waypoint.frame = MAV_FRAME_GLOBAL_RELATIVE_ALT;
      waypoint.seq = 2;
      waypoint.target_system = target_system_id_;
      waypoint.target_component = target_component_id_autopilot_;
      waypoints.push_back(waypoint);


      mavlink_mission_item_int_t camera = {0};
      camera.command = MAV_CMD_DO_DIGICAM_CONTROL;
      camera.x = 1;
      camera.autocontinue = 1;
      camera.frame = MAV_FRAME_MISSION;
      camera.seq = 3;
      camera.target_system = target_system_id_;
      camera.target_component = target_component_id_autopilot_;
      waypoints.push_back(camera);


      mavlink_mission_item_int_t land = {0};
      land.command = MAV_CMD_NAV_LAND;
      land.frame = MAV_FRAME_GLOBAL_RELATIVE_ALT;
      land.x = x_land;
      land.y = y_land;
      land.z = height_land;
      land.autocontinue = 1;
      land.seq = 4;
      land.target_system = target_system_id_;
      land.target_component = target_component_id_autopilot_;
      waypoints.push_back(land);
      sender_count_ = waypoints.size();
      upload_fly_mission();

    }

void CommandsSender::upload_fly_mission(){
    mavlink_mission_clear_all_t a = {0};
      a.target_component = target_component_id_all_;
      a.target_system = target_system_id_;
      mavlink_message_t message;
      mavlink_msg_mission_clear_all_encode(system_id_, 255, &message, &a);
      m_communicator->sendMessageOnAllLinks(message);
      //wait_ack_mission_message();
      mavlink_mission_count_t count = {0};
      count.count = waypoints.size();
      count.target_component = target_component_id_autopilot_;
      count.target_system = target_system_id_;
      mavlink_msg_mission_count_encode(system_id_, component_id_, &message,
                                         &count);
      m_communicator->sendMessageOnAllLinks(message);


      }

void CommandsSender::start_mission(){

    set_guided_mode();
    send_arm();
    mavlink_command_long_t start = {0};
    start.target_system = target_system_id_;
    start.target_component = target_component_id_autopilot_;
    start.command = MAV_CMD_MISSION_START; // 176
    start.confirmation = 1;
    mavlink_message_t message;
    mavlink_msg_command_long_encode(system_id_, component_id_, &message, &start);
     m_communicator->sendMessageOnAllLinks(message);
}

void CommandsSender::set_guided_mode() {

  mavlink_set_mode_t set_mode = {0};
  mavlink_message_t msg;

  set_mode.base_mode = 1;
  set_mode.custom_mode = 4;
  set_mode.target_system = target_system_id_;

  mavlink_msg_set_mode_encode(1, component_id_, &msg, &set_mode);
   m_communicator->sendMessageOnAllLinks(msg);

}


