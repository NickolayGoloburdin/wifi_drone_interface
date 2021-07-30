#include "info_communicator.h"
#include <QDebug>
// MAVLink


// Internal
#include "abstract_link.h"

using namespace domain;

InfoCommunicator::InfoCommunicator(QObject* parent):
    QObject(parent),
    m_lastReceivedLink(nullptr)
{
}

QList<AbstractLink*> InfoCommunicator::links() const
{
    return m_linkChannels.keys();
}

void InfoCommunicator::addLink(AbstractLink* link, uint8_t channel)
{
    if (m_linkChannels.contains(link)) return;

    m_linkChannels[link] = channel;
    connect(link, &AbstractLink::dataReceived,
            this, &InfoCommunicator::onDataReceived);
}

void InfoCommunicator::removeLink(AbstractLink* link)
{
    if (!m_linkChannels.contains(link)) return;

    m_linkChannels.remove(link);
    disconnect(link, &AbstractLink::dataReceived,
            this, &InfoCommunicator::onDataReceived);
}


void InfoCommunicator::sendMessage(QString message, AbstractLink* link)
{
    if (!link || !link->isUp()) return;

    QByteArray buffer = message.toUtf8();

    link->sendData(QByteArray((const char*)buffer.data()));
}

void InfoCommunicator::sendMessageOnLastReceivedLink(QString message)
{
    this->sendMessage(message, m_lastReceivedLink);
}

void InfoCommunicator::sendMessageOnAllLinks(QString message)
{
    for (AbstractLink* link: m_linkChannels.keys())
        this->sendMessage(message, link);
}

void InfoCommunicator::onDataReceived(const QByteArray& data)
{

    m_lastReceivedLink = qobject_cast<AbstractLink*>(this->sender());
    if (!m_lastReceivedLink) return;
       QString msg = QString::fromUtf8(data);
       emit messageReceived(msg);


    // TODO: Link RX status
}
