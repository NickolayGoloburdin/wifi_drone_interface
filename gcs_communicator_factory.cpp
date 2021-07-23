
#include "gcs_communicator_factory.h"// Internal
#include "mavlink_communicator.h"
#include "mainwindow.h"
#include "heartbeat_handler.h"
#include "attitude_handler.h"
#include "status_handler.h"
#include "commands_sender.h"
#include "ack_handler.h"
#include "gps_handler.h"
#include "battery_handler.h"
#include "log_handler.h"
#include <QApplication>
#include <QThread>

using namespace domain;

GcsCommunicatorFactory::GcsCommunicatorFactory()
{}

MavLinkCommunicator* GcsCommunicatorFactory::create()
{
    MavLinkCommunicator* communicator = new MavLinkCommunicator(255, 0);
    MainWindow* window = new MainWindow();
    window->show();
    //new domain::HeartbeatHandler(MAV_TYPE_GCS, communicator);
    domain::HeartbeatHandler* connection = new domain::HeartbeatHandler(254,communicator);
    domain::StatusHandler* status = new domain::StatusHandler(communicator);
    domain::CommandsSender* sender = new domain::CommandsSender(communicator);
    domain::AckHandler* ack = new domain::AckHandler(communicator);
    domain::GPSHandler* gps = new domain::GPSHandler(communicator);
    domain::LogHandler* log = new domain::LogHandler(communicator);
    domain::BatteryHandler* battery = new domain::BatteryHandler(communicator);
    QObject::connect(connection, &HeartbeatHandler::HeartbeatSignal, window, &MainWindow::update_connection);
    QObject::connect(ack, &AckHandler::missionSignal, sender, &CommandsSender::mission_request_handler);
    QObject::connect(window, &MainWindow::logListReqSignal, sender, &CommandsSender::req_log_list);
    QObject::connect(ack, &AckHandler::missionackSignal, sender, &CommandsSender::mission_ack_handler);
    QObject::connect(log, &LogHandler::logEntrySignal, window, &MainWindow::update_log_list);
    QObject::connect(gps, &GPSHandler::gpsSignal, window, &MainWindow::update_sattelites);
    QObject::connect(battery, &BatteryHandler::BatterySignal, window, &MainWindow::update_battery);
    QObject::connect(status, &StatusHandler::statusSignal, window, &MainWindow::update_status);
    QObject::connect(window, &MainWindow::armSignal, sender, &CommandsSender::send_arm);
    QObject::connect(window, &MainWindow::disarmSignal, sender, &CommandsSender::send_disarm);
    QObject::connect(window, &MainWindow::missionSignal, sender, &CommandsSender::form_send_fly_mission);
    QObject::connect(window, &MainWindow::startSignal, sender, &CommandsSender::start_mission);


    return communicator;
}
