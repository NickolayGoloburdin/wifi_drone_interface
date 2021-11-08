# include "gps_handler.h"
#include <ardupilotmega/mavlink.h>
#include "mavlink_communicator.h"
// Qt
#include <QtMath>
#include <QDebug>

using namespace domain;



GPSHandler::GPSHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator)
{
    this->startTimer(4000); // 3 Hz
}
void GPSHandler::timerEvent(QTimerEvent *event)
{
    mavlink_message_t message;
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
void GPSHandler::processMessage(const mavlink_message_t& message)
{
    if (message.msgid != MAVLINK_MSG_ID_GPS_RAW_INT ||
            message.sysid == 0) return;
    int nsat_ =  mavlink_msg_gps_raw_int_get_satellites_visible(&message);
    emit gpsSignal(message.sysid, nsat_);
}
