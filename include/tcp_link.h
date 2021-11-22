#ifndef TCPLINK_H
#define TCPLINK_H


#include "abstract_link.h"

class QTcpSocket;

namespace domain
{
class TcpLink: public AbstractLink
{
        Q_OBJECT

    public:
        TcpLink(const QString& address, int txPort,
                QObject* parent = nullptr);

        bool isUp() const override;


        QString address() const;
        int txPort() const;

    public slots:
        void up() override;
        void down() override;
        void connected() override;
        void disconnected() override;
        void sendData(const QByteArray& data) override;
        void setAddress(const QString& address);
        void setTxPort(int port);

    signals:
        void rxPortChanged(int port);
        void addressChanged(QString address);
        void txPortChanged(int port);

    private slots:
        void readPendingDatagrams();

    private:
        QTcpSocket* m_socket;
        QString m_address;
        int m_txPort;
};
}

#endif // TCPLINK_H
