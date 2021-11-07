#include "udp_link_server.h"

#include <QUdpSocket>

using namespace domain;

UdpLinkServer::UdpLinkServer(int rxPort, QObject* parent):
    AbstractServer(parent),
    m_socket(new QUdpSocket(this)),
    m_rxPort(rxPort)
{
    QObject::connect(m_socket, &QUdpSocket::readyRead,
                     this, &UdpLinkServer::readPendingDatagrams);
}

bool UdpLinkServer::isUp() const
{
    return m_socket->state() == QAbstractSocket::BoundState;
}

int UdpLinkServer::rxPort() const
{
    return m_rxPort;
}


void UdpLinkServer::up()
{
    if (this->isUp()) return;

    if (!m_socket->bind(m_rxPort)) {
        qWarning("UDP connection error: '%s'!",
                 qPrintable(m_socket->errorString()));

        m_socket->close();
    } else {
        emit upChanged(true);
    }
}

void UdpLinkServer::down()
{
    if (!this->isUp()) return;

    m_socket->close();
    emit upChanged(false);
}

QUdpSocket *UdpLinkServer::getSocket()
{
    return m_socket;
}

void UdpLinkServer::setRxPort(int port)
{
    if (m_rxPort == port) return;

    m_rxPort = port;

    if (this->isUp()) {
        this->down();
        this->up();
    }

    emit rxPortChanged(port);
}


void UdpLinkServer::readPendingDatagrams()
{
    while (m_socket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(m_socket->pendingDatagramSize());
        m_socket->readDatagram(datagram.data(), datagram.size());

        emit dataReceived(datagram);
    }
}
