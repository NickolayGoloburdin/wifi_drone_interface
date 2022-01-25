#include "tcp_link.h"
#include <QTcpSocket>

using namespace domain;

TcpLink::TcpLink(const QString& address, int txPort, int id,
                 QObject* parent):
    AbstractLink(parent),
    m_socket(new QTcpSocket(this)),
    m_address(address),
    m_txPort(txPort),
    id_(id)
{
    QObject::connect(m_socket, &QTcpSocket::readyRead,
                     this, &TcpLink::readPendingDatagrams);
    QObject::connect(m_socket, &QTcpSocket::connected,
                     this, &TcpLink::connected);
    QObject::connect(m_socket, &QTcpSocket::disconnected,
                     this, &TcpLink::disconnected);
    QObject::connect(m_socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
                     this, &TcpLink::reconnect);


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
    emit connect(id_, false);
    qDebug() << "Disconnected, trying to reconnect..."<< address();
    up();
}

void TcpLink::reconnect()
{
    auto err = m_socket->error();
    if (m_socket->error() == QAbstractSocket::ConnectionRefusedError ) {
        disconnected();
    };
    if (m_socket->error() == QAbstractSocket::NetworkError) {
        m_socket->abort();
        m_socket->close();
        qDebug() << "NetworkError"<< address();
        disconnected();
    };


}

void TcpLink::connected()
{
    emit connect(id_, true);
    qDebug() << "Connected! Ip:" << address();
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

int TcpLink::id()
{
    return id_;
}

void TcpLink::readPendingDatagrams()
{
    QByteArray datagram = m_socket->readAll();
    emit dataReceived(datagram);
}
