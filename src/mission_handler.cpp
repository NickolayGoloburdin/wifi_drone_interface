#include "mission_handler.h"
#include "mavlink_communicator.h"

#include <QtMath>
#include <QDebug>


using namespace domain;

MissionHandler::MissionHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator), waypoints_(nullptr)
{
    data = QString();
}

void MissionHandler::processMessage(const mavlink_message_t& message)
{
    if (message.msgid == MAVLINK_MSG_ID_MISSION_REQUEST) {
        mavlink_mission_request_t mission_req;
        mavlink_msg_mission_request_decode(&message, &mission_req);
        // qWarning() << (QString("message id: ") + QString::number(message.sysid) + QString("   seq number: ") + QString::number(mission_req.seq));
        if (mission_req.seq > 10) {
            return;
        }

        mavlink_message_t message_send;
        (*waypoints_)[mission_req.seq].target_system = message.sysid;
        mavlink_msg_mission_item_int_encode(m_communicator->systemId(), m_communicator->componentId(), &message_send, &(*waypoints_)[mission_req.seq]);
        m_communicator->sendMessageOnChannel(message_send, message.sysid);

    }

}

void MissionHandler::missionDataRecieved(QVector<mavlink_mission_item_int_t>* waypoints)
{
    waypoints_ = waypoints;
}
