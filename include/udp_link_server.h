#ifndef UDPLINKSERVER_H
#define UDPLINKSERVER_H


#include "abstract_server.h"

class QUdpSocket;

namespace domain
{
class UdpLinkServer: public AbstractServer
{
        Q_OBJECT

        Q_PROPERTY(int rxPort READ rxPort WRITE setRxPort NOTIFY rxPortChanged)

    public:
        UdpLinkServer(int rxPort, QObject* parent = nullptr);

        bool isUp() const override;
        QUdpSocket* getSocket();
        int rxPort() const;

    public slots:
        void up() override;
        void down() override;


        void setRxPort(int port);

    signals:
        void rxPortChanged(int port);

    private slots:
        void readPendingDatagrams();

    private:
        QUdpSocket* m_socket;
        int m_rxPort;
};
}

#endif // UDPLINKSERVER_H
