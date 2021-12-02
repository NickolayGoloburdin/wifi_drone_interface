#include "tcp_link.h"
#include <QTcpSocket>

using namespace domain;

TcpLink::TcpLink(const QString& address, int txPort,
                 QObject* parent):
    AbstractLink(parent),
    m_socket(new QTcpSocket(this)),
    m_address(address),
    m_txPort(txPort)
{
    QObject::connect(m_socket, &QTcpSocket::readyRead,
                     this, &TcpLink::readPendingDatagrams);
    QObject::connect(m_socket, &QTcpSocket::connected,
                     this, &TcpLink::connected);
    QObject::connect(m_socket, &QTcpSocket::disconnected,
                     this, &TcpLink::disconnected);



}

bool TcpLink::isUp() const
{
    return m_socket->state() == QAbstractSocket::ConnectedState;
}


QString TcpLink::address() const
{
    return m_address;
}

int TcpLink::txPort() const
{
    return m_txPort;
}

void TcpLink::up()
{
    m_socket->connectToHost(m_address, txPort());
    //if(!m_socket->waitForConnected(5000)) {
    //    qDebug() << "Error: " << m_socket->errorString();
    //}
}

void TcpLink::down()
{
    if (!this->isUp()) return;

    m_socket->close();
    emit upChanged(false);
}

void TcpLink::disconnected()
{
    qDebug() << "Disconnected, trying to reconnect...";
    up();
}

void TcpLink::connected()
{
    qDebug() << "Connected!";
}

void TcpLink::sendData(const QByteArray& data)
{
    m_socket->write(data);
}



void TcpLink::setAddress(const QString& address)
{
    if (m_address == address) return;

    m_address = address;
    emit addressChanged(address);
}

void TcpLink::setTxPort(int port)
{
    if (m_txPort == port) return;

    m_txPort = port;
    emit txPortChanged(port);
}

void TcpLink::readPendingDatagrams()
{
    QByteArray datagram = m_socket->readAll();
    emit dataReceived(datagram);
}
