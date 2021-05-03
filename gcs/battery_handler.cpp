#include "battery_handler.h"

// MAVLink
#include <mavlink.h>

// Qt
#include <QtMath>
#include <QDebug>

using namespace domain;

BatteryHandler::BatteryHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator)
{

}

void BatteryHandler::processMessage(const mavlink_message_t& message)
{
  if (message.msgid != MAVLINK_MSG_ID_BATTERY_STATUS) return;

    mavlink_battery_status_t battery;
    mavlink_msg_battery_status_decode(&message, &battery);

    qDebug() << "Battery  " << battery.voltages;
}
