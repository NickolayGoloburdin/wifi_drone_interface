#include "heartbeat_handler.h"

// MAVLink
#include <ardupilotmega/mavlink.h>

// Qt
#include <QDebug>

// Internal
#include "mavlink_communicator.h"

using namespace domain;

HeartbeatHandler::HeartbeatHandler(uint8_t type, MavLinkCommunicator* communicator):
    AbstractHandler(communicator), m_type(type)
{
    this->startTimer(10000); // 0.1 Hz
}
void HeartbeatHandler::timerEvent(QTimerEvent* event)
{
    Q_UNUSED(event)

    mavlink_message_t message;
    mavlink_heartbeat_t heartbeat;
    heartbeat.type = m_type;

    mavlink_msg_heartbeat_encode(m_communicator->systemId(),
                                 m_communicator->componentId(),
                                 &message, &heartbeat);

    m_communicator->sendMessageOnAllLinks(message);

    mavlink_command_long_t request_battery = {0};
    request_battery.target_component = 1;
    request_battery.command = MAV_CMD_REQUEST_MESSAGE; // 176
    request_battery.confirmation = 1;
    request_battery.param1 = MAVLINK_MSG_ID_BATTERY_STATUS;
    for (auto a : m_communicator->m_linkChannels.keys()) {
        request_battery.target_system = m_communicator->m_linkChannels.value(a);
        mavlink_msg_command_long_encode(m_communicator->systemId(), m_communicator->componentId(), &message, &request_battery);
        m_communicator->sendMessage(message, a);
    }
    mavlink_command_long_t request_sattelites = {0};
    request_sattelites.target_system = 1;
    request_sattelites.target_component = 1;
    request_sattelites.command = MAV_CMD_REQUEST_MESSAGE; // 176
    request_sattelites.confirmation = 1;
    request_sattelites.param1 = MAVLINK_MSG_ID_GPS_RAW_INT;
    for (auto a : m_communicator->m_linkChannels.keys()) {
        request_sattelites.target_system = m_communicator->m_linkChannels.value(a);
        mavlink_msg_command_long_encode(m_communicator->systemId(), m_communicator->componentId(), &message, &request_sattelites);
        m_communicator->sendMessage(message, a);
    }

}

void HeartbeatHandler::processMessage(const mavlink_message_t& message)
{
    if (message.msgid != MAVLINK_MSG_ID_HEARTBEAT) return;

    emit HeartbeatSignal(QString::number(message.sysid), true);
}
