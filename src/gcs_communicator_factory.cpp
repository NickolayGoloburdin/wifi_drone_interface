#include "gcs_communicator_factory.h"
#include "mavlink_communicator.h"
#include "info_communicator.h"
#include "sql_communicator.h"
//#include "dronewindow.h"
//#include "ui_dronelist.h"
#include "heartbeat_handler.h"
#include "attitude_handler.h"
#include "status_handler.h"
#include "commands_sender.h"
#include "ack_handler.h"
#include "gps_handler.h"
#include "battery_handler.h"
#include "log_handler.h"
#include "info_message_handler.h"
#include "sql_communicator.h"
#include <QQmlApplicationEngine>
#include "delegate.h"
#include "drone.h"
#include "tcp_link.h"
#include "mission_handler.h"
#include <QQmlContext>
#include <QThread>
using namespace domain;

GcsCommunicatorFactory::GcsCommunicatorFactory()
{  }

std::tuple<MavLinkCommunicator *, InfoCommunicator *> GcsCommunicatorFactory::create()
{
    MavLinkCommunicator *communicator = new MavLinkCommunicator(254, 190);
    InfoCommunicator *infcommun = new InfoCommunicator();
    SQLCommunicator *sqlcommunicator = new SQLCommunicator(QString("37.18.110.142"), QString("copter_logs"), QString("rdsuser"), QString("9X7QhbDzBQYpmnBBsB7ZMjb"));
    QQmlApplicationEngine *engine = new QQmlApplicationEngine(nullptr);
    domain::CommandsSender *sender = new domain::CommandsSender(communicator);
    Delegate *model = new Delegate("setting.json", engine);
    model->run();



    engine->rootContext()->setContextProperty("communicator", communicator);
    engine->rootContext()->setContextProperty("commandSender", sender);

    for (int i = 0; i < model->m_drone.drones_.size() ; i++) {

        auto link = new domain::TcpLink(model->m_drone.drones_.at(i).ip_, 5760);
        communicator->addLink(link, model->m_drone.drones_.at(i).uuid_);
        link->up();

    }

    domain::AckHandler *ack = new domain::AckHandler(communicator);
    engine->rootContext()->setContextProperty("AckHandler", ack);

    engine->load(QUrl(QLatin1String("qrc:/qml_mainwindow.qml")));

    domain::InfoMessageHandler *pointinfo = new domain::InfoMessageHandler(infcommun);
    domain::HeartbeatHandler *connection = new domain::HeartbeatHandler(254, communicator);
    domain::StatusHandler *status = new domain::StatusHandler(communicator);
    QObject::connect(status, &StatusHandler::statusSignal, model, &Delegate::setStatus);
    domain::MissionHandler * missionhandler = new domain::MissionHandler(communicator);
    QObject::connect(sender, &CommandsSender::missionDataSignal,missionhandler, &MissionHandler::missionDataRecieved);

    domain::GPSHandler *gps = new domain::GPSHandler(communicator);
    domain::LogHandler *log = new domain::LogHandler(communicator);

    domain::BatteryHandler *battery = new domain::BatteryHandler(communicator);
    QObject::connect(connection, &HeartbeatHandler::HeartbeatSignal, model, &Delegate::setHeartbeat);
    //QObject::connect(ack, &AckHandler::missionSignal, sender, &CommandsSender::mission_request_handler);
    QObject::connect(battery, &BatteryHandler::BatterySignal, model, &Delegate::setvoltage);


    //    QObject::connect(pointinfo, &InfoMessageHandler::CoordinatesSignal, list->ui->drone, &DroneWindow::update_coordinates);

    //    QObject::connect(list->ui->drone, &DroneWindow::logListReqSignal, sender, &CommandsSender::req_log_list);
    //    QObject::connect(ack, &AckHandler::missionackSignal, sender, &CommandsSender::mission_ack_handler);
    //    QObject::connect(log, &LogHandler::logEntrySignal, window, &DroneWindow::update_log_list);
    //    QObject::connect(gps, &GPSHandler::gpsSignal, list->ui->drone, &DroneWindow::update_sattelites);
    //    QObject::connect(battery, &BatteryHandler::BatterySignal, list->ui->drone, &DroneWindow::update_battery);
    //    QObject::connect(status, &StatusHandler::statusSignal, list->ui->drone, &DroneWindow::update_status);
    //    QObject::connect(list->ui->drone, &DroneWindow::armSignal, sender, &CommandsSender::send_arm);
    //    QObject::connect(list->ui->drone, &DroneWindow::takeoffMissionSignal, sender, &CommandsSender::send_takeoff_mission);
    //    QObject::connect(list->ui->drone, &DroneWindow::logReqSignal, sender, &CommandsSender::req_log);
    //    QObject::connect(list->ui->drone, &DroneWindow::disarmSignal, sender, &CommandsSender::send_disarm);
    //    QObject::connect(list->ui->drone, &DroneWindow::missionSignal, sender, &CommandsSender::form_send_fly_mission);
    //    QObject::connect(list->ui->drone, &DroneWindow::startSignal, sender, &CommandsSender::start_mission);
    //    QObject::connect(list->ui->drone, &DroneWindow::takeoffSpeedSignal, sender, &CommandsSender::set_takeoff_speed);
    //    QObject::connect(list->ui->drone, &DroneWindow::landSpeedSignal, sender, &CommandsSender::set_land_speed);
    //    QObject::connect(list->ui->drone, &DroneWindow::RTLSignal, sender, &CommandsSender::send_rtl_cmd);
    //    QObject::connect(list->ui->drone, &DroneWindow::AutoModeSignal, sender, &CommandsSender::set_auto_mode);
    //    QObject::connect(list->ui->drone, &DroneWindow::LoiterModeSignal, sender, &CommandsSender::set_loiter_mode);
    //    QObject::connect(list->ui->drone, &DroneWindow::LoiterTimeModeSignal, sender, &CommandsSender::loiter_time_wait);
    //    QObject::connect(sender, &CommandsSender::dbSignal, sqlcommunicator, &SQLCommunicator::send_mission);
    //    QObject::connect(sqlcommunicator, &SQLCommunicator::sqlStatus, list->ui->drone, &DroneWindow::update_status);
    //    QObject::connect(pointinfo, &InfoMessageHandler::StartSignal, list->ui->drone, &DroneWindow::on_Start_clicked);



    return std::make_tuple(communicator, infcommun);
}
