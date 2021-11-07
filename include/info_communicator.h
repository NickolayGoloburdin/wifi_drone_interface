#ifndef INFO_COMMUNICATOR_H
#define INFO_COMMUNICATOR_H
#include <mavlink_types.h>
#include <ardupilotmega/mavlink.h>
// Qt
#include <QObject>
#include <QMap>

namespace domain
{
class AbstractServer;
class AbstractClient;

class InfoCommunicator: public QObject
{
        Q_OBJECT

    public:
        InfoCommunicator(QObject* parent = nullptr);

        QList<AbstractClient*> links() const;
        QMap<AbstractServer*, uint8_t> m_RecievedlinkChannels;

    public slots:
        void addLink(AbstractClient* link, uint8_t channel);
        void removeLink(AbstractClient* link);
        void addServer(AbstractServer* link, uint8_t channel);
        void removeServer(AbstractServer* link);
        void sendMessage(QString message, AbstractClient* link);
        void sendMessageOnAllLinks(QString message);

    signals:
        void messageReceived(const QString message);

    protected slots:
        void onDataReceived(const QByteArray& data);

    protected:
        QMap<AbstractClient*, uint8_t> m_linkChannels;
        AbstractServer* m_lastReceivedLink;

        uint8_t m_systemId;
        uint8_t m_componentId;
};
}
#endif // INFO_COMMUNICATOR_H
