#include "udp_link_client.h"

#include <QUdpSocket>

using namespace domain;

UdpLinkClient::UdpLinkClient(QUdpSocket* socket, const QString& address, int txPort,
                             QObject* parent):
    AbstractClient(parent),
    m_socket(socket),
    m_address(address),
    m_txPort(txPort)
{
}

bool UdpLinkClient::isUp() const
{
    return m_socket->state() == QAbstractSocket::BoundState;
}


QString UdpLinkClient::address() const
{
    return m_address;
}

int UdpLinkClient::txPort() const
{
    return m_txPort;
}


void UdpLinkClient::sendData(const QByteArray& data)
{
    m_socket->writeDatagram(data, QHostAddress(m_address), m_txPort);
}



void UdpLinkClient::setAddress(const QString& address)
{
    if (m_address == address) return;

    m_address = address;
    emit addressChanged(address);
}

void UdpLinkClient::setTxPort(int port)
{
    if (m_txPort == port) return;

    m_txPort = port;
    emit txPortChanged(port);
}

