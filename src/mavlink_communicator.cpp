#include "mavlink_communicator.h"

// MAVLink


// Internal
#include "abstract_client.h"
#include "abstract_server.h"

using namespace domain;

MavLinkCommunicator::MavLinkCommunicator(uint8_t systemId, uint8_t componentId,
        QObject* parent):
    QObject(parent),
    m_lastReceivedLink(nullptr),
    m_systemId(systemId),
    m_componentId(componentId)
{
    qRegisterMetaType<mavlink_message_t>("mavlink_message_t");
}

QList<AbstractClient*> MavLinkCommunicator::links() const
{
    return m_linkChannels.keys();
}

uint8_t MavLinkCommunicator::systemId() const
{
    return m_systemId;
}

uint8_t MavLinkCommunicator::componentId() const
{
    return m_componentId;
}

void MavLinkCommunicator::addLink(AbstractClient* link, uint8_t channel)
{
    if (m_linkChannels.contains(link)) return;

    m_linkChannels[link] = channel;

}
void MavLinkCommunicator::addServer(AbstractServer* link, uint8_t channel)
{
    if (m_RecievedlinkChannels.contains(link)) return;

    m_RecievedlinkChannels[link] = channel;
    connect(link, &AbstractServer::dataReceived,
            this, &MavLinkCommunicator::onDataReceived);
}

void MavLinkCommunicator::removeServer(AbstractServer* link)
{
    if (!m_RecievedlinkChannels.contains(link)) return;

    m_RecievedlinkChannels.remove(link);
    disconnect(link, &AbstractServer::dataReceived,
               this, &MavLinkCommunicator::onDataReceived);
}
void MavLinkCommunicator::removeLink(AbstractClient* link)
{
    if (!m_linkChannels.contains(link)) return;

    m_linkChannels.remove(link);
}

void MavLinkCommunicator::setSystemId(uint8_t systemId)
{
    m_systemId = systemId;
}

void MavLinkCommunicator::setComponentId(uint8_t componentId)
{
    m_componentId = componentId;
}

void MavLinkCommunicator::sendMessage(mavlink_message_t& message, AbstractClient* link)
{
    if (!link || !link->isUp()) return;
    uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
    int lenght = mavlink_msg_to_send_buffer(buffer, &message);

    if (!lenght) return;
    link->sendData(QByteArray((const char*)buffer, lenght));
}
void MavLinkCommunicator::sendMessageOnChannel(mavlink_message_t& message, uint8_t channel)
{
    AbstractClient* link = m_linkChannels.key(channel);

    if (!link || !link->isUp()) return;

    uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
    int lenght = mavlink_msg_to_send_buffer(buffer, &message);

    if (!lenght) return;
    link->sendData(QByteArray((const char*)buffer, lenght));
}

void MavLinkCommunicator::sendMessageOnAllLinks(mavlink_message_t& message)
{
    for (AbstractClient* link : m_linkChannels.keys())
        this->sendMessage(message, link);
}
void MavLinkCommunicator::sendMessageOnAllChosenLinks(mavlink_message_t& message)
{
    for (AbstractClient* link : m_chosenChannels.keys())
        this->sendMessage(message, link);
}

void MavLinkCommunicator::addLinkToChosen(const int& channel)
{
    if (m_chosenChannels.values().contains(channel)) return;
    m_chosenChannels[m_linkChannels.key(channel)] = channel;
}
void MavLinkCommunicator::removeLinkFromChosen(const int& channel)
{
    if (!m_chosenChannels.values().contains(channel)) return;
    m_chosenChannels.remove(m_linkChannels.key(channel));
}
void MavLinkCommunicator::onDataReceived(const QByteArray& data)
{
    mavlink_message_t message;
    mavlink_status_t status;

    m_lastReceivedLink = qobject_cast<AbstractServer*>(this->sender());
    if (!m_lastReceivedLink) return;

    uint8_t channel = m_RecievedlinkChannels.value(m_lastReceivedLink);
    for (int pos = 0; pos < data.length(); ++pos) {
        if (!mavlink_parse_char(channel, (uint8_t)data[pos],
                                &message, &status))
            continue;

        emit messageReceived(message);
    }

    // TODO: Link RX status
}
