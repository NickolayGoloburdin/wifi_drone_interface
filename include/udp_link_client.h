#ifndef UDPLINKCLIENT_H
#define UDPLINKCLIENT_H


#include "abstract_client.h"

class QUdpSocket;

namespace domain
{
class UdpLinkClient: public AbstractClient
{
        Q_OBJECT

        Q_PROPERTY(QString address READ address WRITE setAddress NOTIFY addressChanged)
        Q_PROPERTY(int txPort READ txPort WRITE setTxPort NOTIFY txPortChanged)

    public:
        UdpLinkClient(QUdpSocket* socket, const QString& address, int txPort,
                      QObject* parent = nullptr);

        bool isUp() const override;


        QString address() const;
        int txPort() const;

    public slots:


        void sendData(const QByteArray& data) override;
        void setAddress(const QString& address);
        void setTxPort(int port);

    signals:
        void addressChanged(QString address);
        void txPortChanged(int port);



    private:
        QUdpSocket* m_socket;
        QString m_address;
        int m_txPort;
};
}

#endif // UDPLINKCLIENT_H
