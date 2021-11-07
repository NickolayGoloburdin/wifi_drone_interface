#include "info_communicator.h"
#include <QDebug>
// MAVLink


// Internal
#include "abstract_server.h"
#include "abstract_client.h"

using namespace domain;

InfoCommunicator::InfoCommunicator(QObject* parent):
    QObject(parent),
    m_lastReceivedLink(nullptr)
{
}

QList<AbstractClient*> InfoCommunicator::links() const
{
    return m_linkChannels.keys();
}

void InfoCommunicator::addLink(AbstractClient* link, uint8_t channel)
{
    if (m_linkChannels.contains(link)) return;

    m_linkChannels[link] = channel;
//    connect(link, &AbstractClient::dataReceived,
//            this, &InfoCommunicator::onDataReceived);
}

void InfoCommunicator::removeLink(AbstractClient* link)
{
    if (!m_linkChannels.contains(link)) return;

    m_linkChannels.remove(link);
//    disconnect(link, &AbstractLink::dataReceived,
    //               this, &InfoCommunicator::onDataReceived);
}

void InfoCommunicator::addServer(AbstractServer *link, uint8_t channel)
{
    if (m_RecievedlinkChannels.contains(link)) return;

    m_RecievedlinkChannels[link] = channel;
    connect(link, &AbstractServer::dataReceived,
            this, &InfoCommunicator::onDataReceived);
}

void InfoCommunicator::removeServer(AbstractServer *link)
{
    if (!m_RecievedlinkChannels.contains(link)) return;

    m_RecievedlinkChannels.remove(link);
    disconnect(link, &AbstractServer::dataReceived,
               this, &InfoCommunicator::onDataReceived);
}


void InfoCommunicator::sendMessage(QString message, AbstractClient* link)
{
    if (!link || !link->isUp()) return;

    QByteArray buffer = message.toUtf8();

    link->sendData(QByteArray((const char*)buffer.data()));
}


void InfoCommunicator::sendMessageOnAllLinks(QString message)
{
    for (AbstractClient* link : m_linkChannels.keys())
        this->sendMessage(message, link);
}

void InfoCommunicator::onDataReceived(const QByteArray& data)
{

    m_lastReceivedLink = qobject_cast<AbstractServer*>(this->sender());
    if (!m_lastReceivedLink) return;
    QString msg = QString::fromUtf8(data);
    emit messageReceived(msg);


    // TODO: Link RX status
}
