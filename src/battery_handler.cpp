#include "battery_handler.h"

// MAVLink
#include <ardupilotmega/mavlink.h>
#include "mavlink_communicator.h"
// Qt
#include <QtMath>
#include <QDebug>

using namespace domain;

BatteryHandler::BatteryHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator)
{
    this->startTimer(4000); // 0.25 Hz
}

void BatteryHandler::timerEvent(QTimerEvent *event)
{
    mavlink_message_t message;
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
}

void BatteryHandler::processMessage(const mavlink_message_t& message)
{
    if (message.msgid != MAVLINK_MSG_ID_BATTERY_STATUS ||
            message.sysid == 0) return;

    mavlink_battery_status_t battery;
    mavlink_msg_battery_status_decode(&message, &battery);
    int8_t battery_rem = battery.battery_remaining;
    emit BatterySignal(message.sysid, battery_rem);

}
