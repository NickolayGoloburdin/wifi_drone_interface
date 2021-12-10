#ifndef COMMANDS_SENDER_H
#define COMMANDS_SENDER_H
#include <QObject>
#include "mavlink_communicator.h"
#include "abstract_handler.h"
#include <QVector>
#include <QString>
#include <QMap>
#include <QSet>

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
        Q_INVOKABLE void send_arm();
        void set_synchronize(int id, int seq);
        Q_INVOKABLE void enable_disable_sync(bool state);
        void synchronizing();
        Q_INVOKABLE void send_disarm();
        Q_INVOKABLE void send_takeoff_mission(float meters = 5, float time = 10.0);
        Q_INVOKABLE void start_mission();
        void form_send_fly_mission(int x, int y, int x_land, int y_land, float height_takeoff, float height_point, float height_land, bool drop, bool db);
        Q_INVOKABLE void set_guided_mode();
        Q_INVOKABLE void set_auto_mode();
        Q_INVOKABLE void set_loiter_mode();
        void loiter_time_wait(float seconds);
        void mission_request_handler(mavlink_mission_request_t mission_req, int id);
        void command_ack_handler();
        void mission_ack_handler(int type);
        Q_INVOKABLE void req_log_list();
        void req_log(int number);
        void set_takeoff_speed(float speed);
        Q_INVOKABLE void set_land_speed(float speed);
        Q_INVOKABLE void set_fly_speed(float speed);
        Q_INVOKABLE void send_rtl_cmd();
        Q_INVOKABLE void form_mission_from_file(QString url);
        Q_INVOKABLE void upload_fly_mission();
    signals:
        void dbSignal(QVector<mavlink_mission_item_int_t>& mission);
        void missionDataSignal(QVector<mavlink_mission_item_int_t>* waypoints);

    protected:
        MavLinkCommunicator* const m_communicator;
        QMap<int, int> drone_waypoint_reaching_;


    private:
        int target_component_id_all_ = 0;
        int target_component_id_autopilot_ = 1;
        int system_id_ = 254;
        int target_system_id_ = 1;
        int component_id_ = 1;
        bool sync_state = false;

};
}
#endif // COMMANDS_SENDER_H
