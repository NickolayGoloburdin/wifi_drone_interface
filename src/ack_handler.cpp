#include "ack_handler.h"

// MAVLink


// Qt
#include <QtMath>
#include <QDebug>

using namespace domain;

AckHandler::AckHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator)
{}

void AckHandler::processMessage(const mavlink_message_t& message)
{
    switch (message.msgid) {
        case MAVLINK_MSG_ID_MISSION_ACK:
            mavlink_mission_ack_t ack;
            mavlink_msg_mission_ack_decode(&message, &ack);
            emit missionackSignal(ack.type, message.sysid);
        case MAVLINK_MSG_ID_MISSION_REQUEST:
            mavlink_mission_request_t mission_req;
            mavlink_msg_mission_request_decode(&message, &mission_req);
            emit missionSignal(mission_req, message.sysid);
        case MAVLINK_MSG_ID_COMMAND_ACK:
            emit commandSignal(message.sysid);
    }


}
