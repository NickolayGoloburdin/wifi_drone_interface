#include "commands_sender.h"


// Qt
#include <QtMath>
#include <QDebug>
#include <QThread>
#include <cstring>
#include <QFile>


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
void CommandsSender::mission_request_handler(mavlink_mission_request_t mission_req, int id){
    if (mission_req.seq >50 ){return;}
      mavlink_message_t message;
    //wait_mission_message();
      waypoints[mission_req.seq].target_system = id;
      mavlink_msg_mission_item_int_encode(m_communicator->systemId(), m_communicator->componentId(), &message, &waypoints[mission_req.seq]);
      m_communicator->sendMessageOnChannel(message, id);
      count_++;

}
void CommandsSender::command_ack_handler(){

}
void CommandsSender::mission_ack_handler(int type){

}
void CommandsSender::send_arm(){
    set_guided_mode();
    mavlink_command_long_t set_mode = {0};
    set_mode.target_component = target_component_id_all_;
    set_mode.command = MAV_CMD_COMPONENT_ARM_DISARM; // 176
    set_mode.confirmation = 0;
    set_mode.param1 = 1;
    mavlink_message_t message;
    for (auto itr : m_communicator->m_chosenChannels.keys()){
      set_mode.target_system = m_communicator->m_chosenChannels.value(itr);
      mavlink_msg_command_long_encode(m_communicator->systemId(), m_communicator->componentId(), &message,
                                      &set_mode);
      m_communicator->sendMessage(message, itr);
    }
}
void CommandsSender::send_disarm(){
    set_guided_mode();
    mavlink_command_long_t set_mode = {0};
    set_mode.target_component = target_component_id_all_;
    set_mode.command = MAV_CMD_COMPONENT_ARM_DISARM; // 176
    set_mode.confirmation = 0;
    set_mode.param1 = 0;
    mavlink_message_t message;
    for (auto itr : m_communicator->m_chosenChannels.keys()){

      set_mode.target_system = m_communicator->m_chosenChannels.value(itr);

      mavlink_msg_command_long_encode(m_communicator->systemId(), m_communicator->componentId(), &message,
                                      &set_mode);
       m_communicator->sendMessage(message, itr);
    }

}
void CommandsSender::req_log_list(){

    mavlink_log_request_list_t req = {0};
    req.start = 0;
    req.end = 0xffff;

    req.target_component = target_component_id_autopilot_;
    mavlink_message_t message;
    for (auto itr : m_communicator->m_chosenChannels.keys()){
        req.target_system = m_communicator->m_chosenChannels.value(itr);
        mavlink_msg_log_request_list_encode(m_communicator->systemId(), m_communicator->componentId(), &message,
                                    &req);
        m_communicator->sendMessage(message, itr);
}
}
void CommandsSender::req_log(int number){
    mavlink_log_request_data_t req = {0};

    req.target_component = target_component_id_autopilot_;
    req.id = number;
    mavlink_message_t message;
    for (auto itr : m_communicator->m_chosenChannels.keys()){
        req.target_system = m_communicator->m_chosenChannels.value(itr);
        mavlink_msg_log_request_data_encode(m_communicator->systemId(), m_communicator->componentId(), &message,
                                    &req);
        m_communicator->sendMessage(message, itr);
    }
}
void CommandsSender::form_send_fly_mission(int x, int y, int x_land, int y_land,float height_takeoff,float height_point,float height_land, bool drop,bool db){

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

      mavlink_mission_item_int_t waypoint1 = {0};
      waypoint1.command = MAV_CMD_NAV_WAYPOINT;
      if (drop == true){waypoint1.param1 = 100;}
      else{waypoint1.param1 = 2;}
      waypoint1.z = height_takeoff;
      waypoint1.x = x;
      waypoint1.y = y;
      waypoint1.autocontinue = 1;
      waypoint1.frame = MAV_FRAME_GLOBAL_RELATIVE_ALT;
      waypoint1.seq = 2;
      waypoint1.target_system = target_system_id_;
      waypoint1.target_component = target_component_id_autopilot_;
      waypoints.push_back(waypoint1);

      mavlink_mission_item_int_t waypoint = {0};
      waypoint.command = MAV_CMD_NAV_WAYPOINT;
      if (drop == true){waypoint.param1 = 150;}
      else{waypoint.param1 = 2;}
      waypoint.z = height_point;
      waypoint.x = x;
      waypoint.y = y;
      waypoint.autocontinue = 1;
      waypoint.frame = MAV_FRAME_GLOBAL_RELATIVE_ALT;
      waypoint.seq = 3;
      waypoint.target_system = target_system_id_;
      waypoint.target_component = target_component_id_autopilot_;
      waypoints.push_back(waypoint);


      mavlink_mission_item_int_t camera = {0};
      camera.command = MAV_CMD_DO_DIGICAM_CONTROL;
      camera.x = 1;
      camera.autocontinue = 1;
      camera.frame = MAV_FRAME_MISSION;
      camera.seq = 4;
      camera.target_system = target_system_id_;
      camera.target_component = target_component_id_autopilot_;
      waypoints.push_back(camera);


      mavlink_mission_item_int_t wp = {0};
      wp.command = MAV_CMD_NAV_WAYPOINT;
      wp.z = height_takeoff;
      wp.x = x;
      wp.y = y;
      wp.autocontinue = 1;
      wp.frame = MAV_FRAME_GLOBAL_RELATIVE_ALT;
      wp.seq = 5;
      wp.target_system = target_system_id_;
      wp.target_component = target_component_id_autopilot_;
      waypoints.push_back(wp);


      mavlink_mission_item_int_t land = {0};
      land.command = MAV_CMD_NAV_LAND;
      land.frame = MAV_FRAME_GLOBAL_RELATIVE_ALT;
      land.x = x_land;
      land.y = y_land;
      land.z = height_land;
      land.autocontinue = 1;
      land.seq = 6;
      land.target_system = target_system_id_;
      land.target_component = target_component_id_autopilot_;
      waypoints.push_back(land);
      sender_count_ = waypoints.size();
      if (db) emit dbSignal(waypoints);
      upload_fly_mission();
    }

void CommandsSender::upload_fly_mission(){
    mavlink_mission_clear_all_t a = {0};
      a.target_component = target_component_id_all_;
      a.target_system = target_system_id_;
      mavlink_message_t message;
      mavlink_msg_mission_clear_all_encode(m_communicator->systemId(), m_communicator->componentId(), &message, &a);
      m_communicator->sendMessageOnAllLinks(message);
      //wait_ack_mission_message();
      mavlink_mission_count_t count = {0};
      count.count = waypoints.size();
      count.target_component = target_component_id_autopilot_;

      for (auto itr : m_communicator->m_chosenChannels.keys()){
          count.target_system = m_communicator->m_chosenChannels.value(itr);

      mavlink_msg_mission_count_encode(m_communicator->systemId(), m_communicator->componentId(), &message,
                                         &count);
      m_communicator->sendMessage(message, itr);}


      }

void CommandsSender::start_mission(){

    set_guided_mode();
    send_arm();
    mavlink_command_long_t start = {0};

    start.target_component = target_component_id_autopilot_;
    start.command = MAV_CMD_MISSION_START; // 176
    start.confirmation = 1;
    mavlink_message_t message;
    for (auto itr : m_communicator->m_chosenChannels.keys()){
        start.target_system = m_communicator->m_chosenChannels.value(itr);
        mavlink_msg_command_long_encode(m_communicator->systemId(), m_communicator->componentId(), &message, &start);
        m_communicator->sendMessage(message, itr);
    }
}

void CommandsSender::set_guided_mode() {

  mavlink_set_mode_t set_mode = {0};
  mavlink_message_t msg;

  set_mode.base_mode = 1;
  set_mode.custom_mode = 4;

    for (auto itr : m_communicator->m_chosenChannels.keys()){
        set_mode.target_system = m_communicator->m_chosenChannels.value(itr);
        mavlink_msg_set_mode_encode(m_communicator->systemId(), m_communicator->componentId(), &msg, &set_mode);
        m_communicator->sendMessage(msg, itr);
    }

}
void CommandsSender::set_auto_mode() {

  mavlink_set_mode_t set_mode = {0};
  mavlink_message_t msg;

  set_mode.base_mode = 1;
  set_mode.custom_mode = 3;

  for (auto itr : m_communicator->m_chosenChannels.keys()){
      set_mode.target_system = m_communicator->m_chosenChannels.value(itr);
      mavlink_msg_set_mode_encode(m_communicator->systemId(), m_communicator->componentId(), &msg, &set_mode);
      m_communicator->sendMessage(msg, itr);
  }

}
void CommandsSender::set_loiter_mode() {

  mavlink_set_mode_t set_mode = {0};
  mavlink_message_t msg;

  set_mode.base_mode = 1;
  set_mode.custom_mode = 5;

  for (auto itr : m_communicator->m_chosenChannels.keys()){
      set_mode.target_system = m_communicator->m_chosenChannels.value(itr);
      mavlink_msg_set_mode_encode(m_communicator->systemId(), m_communicator->componentId(), &msg, &set_mode);
      m_communicator->sendMessage(msg, itr);
  }

}
void CommandsSender::set_takeoff_speed(float speed){
    mavlink_param_set_t param = {0};
    param.target_component = target_component_id_autopilot_;
    param.param_type = MAV_PARAM_TYPE_INT8;
    strcpy(param.param_id,"WPNAV_SPEED_UP");
    param.param_value = speed;
    mavlink_message_t msg;
    for (auto itr : m_communicator->m_chosenChannels.keys()){
        param.target_system = m_communicator->m_chosenChannels.value(itr);
        mavlink_msg_param_set_encode(m_communicator->systemId(), m_communicator->componentId(), &msg, &param);
        m_communicator->sendMessage(msg, itr);
    }

}
void CommandsSender::set_land_speed(float speed){
   mavlink_param_set_t param = {0};

    param.target_component = target_component_id_autopilot_;
    param.param_type = MAV_PARAM_TYPE_INT8;
    strcpy(param.param_id,"LAND_SPEED");
    param.param_value = speed;
    mavlink_message_t msg;
    for (auto itr : m_communicator->m_chosenChannels.keys()){
        param.target_system = m_communicator->m_chosenChannels.value(itr);
        mavlink_msg_param_set_encode(m_communicator->systemId(), m_communicator->componentId(), &msg, &param);
        m_communicator->sendMessage(msg, itr);
    }

}
void CommandsSender::set_fly_speed(float speed){
   mavlink_param_set_t param = {0};

    param.target_component = target_component_id_autopilot_;
    param.param_type = MAV_PARAM_TYPE_INT8;
    strcpy(param.param_id,"WPNAV_SPEED");
    param.param_value = speed;
    mavlink_message_t msg;
    for (auto itr : m_communicator->m_chosenChannels.keys()){
        param.target_system = m_communicator->m_chosenChannels.value(itr);

        mavlink_msg_param_set_encode(m_communicator->systemId(), m_communicator->componentId(), &msg, &param);
        m_communicator->sendMessage(msg, itr);
    }

}

void CommandsSender::send_rtl_cmd(){
    set_guided_mode();
    mavlink_command_long_t start = {0};

    start.target_component = target_component_id_autopilot_;
    start.command = MAV_CMD_NAV_RETURN_TO_LAUNCH; // 176
    start.confirmation = 1;
    mavlink_message_t message;
    for (auto itr : m_communicator->m_chosenChannels.keys()){
        start.target_system = m_communicator->m_chosenChannels.value(itr);;
        mavlink_msg_command_long_encode(m_communicator->systemId(), m_communicator->componentId(), &message, &start);
        m_communicator->sendMessage(message, itr);
    }
}
void CommandsSender::send_takeoff_mission(float meters, float time){
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
    takeoff.z = meters;
    takeoff.autocontinue = 1;
    takeoff.frame = MAV_FRAME_GLOBAL_RELATIVE_ALT;
    takeoff.seq = 1;
    takeoff.target_system = target_system_id_;
    takeoff.target_component = target_component_id_autopilot_;
    waypoints.push_back(takeoff);

    mavlink_mission_item_int_t waypoint = {0};
    waypoint.command = MAV_CMD_NAV_WAYPOINT;
    waypoint.param1 = time;
    waypoint.z = meters;
    waypoint.x = 0;
    waypoint.y = 0;
    waypoint.autocontinue = 1;
    waypoint.frame = MAV_FRAME_GLOBAL_RELATIVE_ALT;
    waypoint.seq = 2;
    waypoint.target_system = target_system_id_;
    waypoint.target_component = target_component_id_autopilot_;
    waypoints.push_back(waypoint);

    mavlink_mission_item_int_t land = {0};
    land.command = MAV_CMD_NAV_RETURN_TO_LAUNCH;
    land.frame = MAV_FRAME_GLOBAL_RELATIVE_ALT;
    land.autocontinue = 1;
    land.seq = 3;
    land.target_system = target_system_id_;
    land.target_component = target_component_id_autopilot_;
    waypoints.push_back(land);
    sender_count_ = waypoints.size();

    upload_fly_mission();


}
void CommandsSender::loiter_time_wait(float seconds){
    set_guided_mode();
    mavlink_command_long_t start = {0};
    start.target_system = target_system_id_;
    start.target_component = target_component_id_autopilot_;
    start.command = MAV_CMD_NAV_LOITER_TIME; // 176
    start.confirmation = 1;
    start.param1 = seconds;
    mavlink_message_t message;
    for (auto itr : m_communicator->m_chosenChannels.keys()){
        start.target_system = m_communicator->m_chosenChannels.value(itr);
        mavlink_msg_command_long_encode(m_communicator->systemId(), m_communicator->componentId(), &message, &start);
        m_communicator->sendMessage(message, itr);

     }
}




