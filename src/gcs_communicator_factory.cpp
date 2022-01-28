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
{}

std::tuple<MavLinkCommunicator *, InfoCommunicator *> GcsCommunicatorFactory::create()
{
    MavLinkCommunicator *communicator = new MavLinkCommunicator(254, 190);
    InfoCommunicator *infcommun = new InfoCommunicator();
    //SQLCommunicator *sqlcommunicator = new SQLCommunicator(QString("37.18.110.142"), QString("copter_logs"), QString("rdsuser"), QString("9X"));
    QQmlApplicationEngine *engine = new QQmlApplicationEngine(nullptr);
    domain::CommandsSender *sender = new domain::CommandsSender(communicator);
    Delegate *model = new Delegate("setting.json", engine);
    model->run();

    engine->rootContext()->setContextProperty("communicator", communicator);
    engine->rootContext()->setContextProperty("commandSender", sender);

    for (int i = 0; i < model->m_drone.drones_.size() ; i++) {

        auto link = new domain::TcpLink(model->m_drone.drones_.at(i).ip_,model->m_drone.drones_.at(i).port_, model->m_drone.drones_.at(i).uuid_);
        model->addLink(link);
        communicator->addLink(link);
        link->up();

    }

    domain::AckHandler *ack = new domain::AckHandler(communicator);
    engine->rootContext()->setContextProperty("AckHandler", ack);

    engine->load(QUrl(QLatin1String("qrc:/qml_mainwindow.qml")));
    QObject::connect(sender, &CommandsSender::linkPointerSignal, model, &Delegate::addDrone);
    domain::InfoMessageHandler *pointinfo = new domain::InfoMessageHandler(infcommun);
    domain::HeartbeatHandler *connection = new domain::HeartbeatHandler(254, communicator);
    domain::StatusHandler *status = new domain::StatusHandler(communicator);
    QObject::connect(status, &StatusHandler::statusSignal, model, &Delegate::setStatus);
    domain::MissionHandler * missionhandler = new domain::MissionHandler(communicator);
    QObject::connect(missionhandler, &MissionHandler::synchronizeSignal,sender, &CommandsSender::set_synchronize);
    QObject::connect(sender, &CommandsSender::missionDataSignal,missionhandler, &MissionHandler::missionDataRecieved);
    QObject::connect(sender, &CommandsSender::linkRmPointerSignal,model, &Delegate::removeDrone);
    domain::GPSHandler *gps = new domain::GPSHandler(communicator);
    QObject::connect(gps, &GPSHandler::gpsSignal,model, &Delegate::setGps);

    domain::LogHandler *log = new domain::LogHandler(communicator);

    domain::BatteryHandler *battery = new domain::BatteryHandler(communicator);
    QObject::connect(connection, &HeartbeatHandler::HeartbeatSignal, model, &Delegate::setHeartbeat);
    //QObject::connect(ack, &AckHandler::missionSignal, sender, &CommandsSender::mission_request_handler);
    QObject::connect(battery, &BatteryHandler::BatterySignal, model, &Delegate::setvoltage);

    return std::make_tuple(communicator, infcommun);
}
