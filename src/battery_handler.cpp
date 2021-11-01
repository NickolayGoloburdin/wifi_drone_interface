#include "battery_handler.h"

// MAVLink
#include <ardupilotmega/mavlink.h>

// Qt
#include <QtMath>
#include <QDebug>

using namespace domain;

BatteryHandler::BatteryHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator)
{}

void BatteryHandler::processMessage(const mavlink_message_t& message)
{
    if (message.msgid != MAVLINK_MSG_ID_BATTERY_STATUS ||
        message.sysid == 0) return;

    mavlink_battery_status_t battery;
    mavlink_msg_battery_status_decode(&message,&battery);
    int8_t battery_rem = battery.battery_remaining;
    emit BatterySignal(QString::number(message.sysid), battery_rem);

}
