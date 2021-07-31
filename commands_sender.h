#ifndef COMMANDS_SENDER_H
#define COMMANDS_SENDER_H
#include <QObject>
#include "mavlink_communicator.h"
#include "abstract_handler.h"
#include <QVector>
namespace domain
{
    class MavLinkCommunicator;
    class CommandsSender: public QObject
    {
        Q_OBJECT

    public:
        explicit CommandsSender(MavLinkCommunicator* communicator);

        bool command_ack_ = false;
        bool mission_req_ = false;
        bool mission_ack_ = false;
        int sender_count_ = 0;
        int count_ = 0;
        void wait_mission_message();
        void wait_ack_message();
        void wait_ack_mission_message();
        QVector<mavlink_mission_item_int_t> waypoints;
    public slots:
        void send_arm();
        void send_disarm();
        void start_mission();
        void form_send_fly_mission(int x, int y, int x_land, int y_land, float height_takeoff,float height_point,float height_land, bool drop);
        void set_guided_mode();
        void mission_request_handler(mavlink_mission_request_t mission_req);
        void command_ack_handler();
        void mission_ack_handler(int type);
        void req_log_list();
        void req_log(int number);
        void set_takeoff_speed(float speed);
        void set_land_speed(float speed);
        void set_fly_speed(float speed);
    signals:
        void dbSignal(QVector<mavlink_mission_item_int_t>& mission);


    protected:
        MavLinkCommunicator* const m_communicator;
        void upload_fly_mission();


    private:
        int target_component_id_all_ = 0;
        int target_component_id_autopilot_ = 1;
        int system_id_ = 254;
        int target_system_id_ = 1;
        int component_id_ = 1;
    };
}
#endif // COMMANDS_SENDER_H
