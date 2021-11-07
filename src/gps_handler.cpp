# include "gps_handler.h"
#include <ardupilotmega/mavlink.h>

// Qt
#include <QtMath>
#include <QDebug>

using namespace domain;

GPSHandler::GPSHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator)
{}

void GPSHandler::processMessage(const mavlink_message_t& message)
{
    if (message.msgid != MAVLINK_MSG_ID_GPS_RAW_INT ||
            message.sysid == 0) return;
    int nsat_ =  mavlink_msg_gps_raw_int_get_satellites_visible(&message);
    emit gpsSignal(QString::number(message.sysid), nsat_);
}
