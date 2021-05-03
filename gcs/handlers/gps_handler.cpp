#include "gps_handler.h"

// MAVLink
#include <mavlink.h>

// Qt
#include <QtMath>
#include <QDebug>

using namespace domain;

GPSHandler::GPSHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator)
{

}

void GPSHandler::processMessage(const mavlink_message_t& message)
{
  if (message.msgid != MAVLINK_MSG_ID_GPS_STATUS) return;

    mavlink_gps_status_t gps;
    mavlink_msg_gps_status_decode(&message, &gps);

    qDebug() << "Sattelites:: " << gps.satellites_visible;
}
