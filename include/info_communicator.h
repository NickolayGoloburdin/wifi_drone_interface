#ifndef INFO_COMMUNICATOR_H
#define INFO_COMMUNICATOR_H
#include <mavlink_types.h>
#include <ardupilotmega/mavlink.h>
// Qt
#include <QObject>
#include <QMap>

namespace domain
{
class AbstractLink;

class InfoCommunicator: public QObject
{
        Q_OBJECT

    public:
        InfoCommunicator(QObject* parent = nullptr);

        QList<AbstractLink*> links() const;
        QMap<AbstractLink*, uint8_t> m_RecievedlinkChannels;

    public slots:
        void addLink(AbstractLink* link, uint8_t channel);
        void removeLink(AbstractLink* link);
        void sendMessage(QString message, AbstractLink* link);
        void sendMessageOnAllLinks(QString message);

    signals:
        void messageReceived(const QString message);

    protected slots:
        void onDataReceived(const QByteArray& data);

    protected:
        QMap<AbstractLink*, uint8_t> m_linkChannels;
        AbstractLink* m_lastReceivedLink;

        uint8_t m_systemId;
        uint8_t m_componentId;
};
}
#endif // INFO_COMMUNICATOR_H
