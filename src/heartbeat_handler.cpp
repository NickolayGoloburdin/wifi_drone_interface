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

    this->startTimer(5000); // 3 Hz
    for( auto i :communicator->m_linkChannels.values()) {
        heartbeats[i] = false;
    }

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


    for (auto i : heartbeats.keys()) {
        emit HeartbeatSignal(i, heartbeats.value(i));
    }
    for (auto i : heartbeats.keys()) {
        heartbeats[i] = false;
    }

}

void HeartbeatHandler::processMessage(const mavlink_message_t& message)
{
    if (message.msgid != MAVLINK_MSG_ID_HEARTBEAT || !(heartbeats.keys().contains(message.sysid))) return;
    heartbeats[message.sysid] = true;
    //emit HeartbeatSignal(QString::number(message.sysid), true);
}
