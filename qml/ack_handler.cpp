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
            mavlink_mission_ack_t mission_ack;
            mavlink_msg_mission_ack_decode(&message, &mission_ack);
            emit missionackSignal(mission_ack.type, message.sysid);

        case MAVLINK_MSG_ID_COMMAND_ACK:
            mavlink_command_ack_t ack;
            mavlink_msg_command_ack_decode(&message, &ack);
            bool res = ack.result == 0 ? true : false;
            emit commandSignal(message.sysid, res);
    }


}
