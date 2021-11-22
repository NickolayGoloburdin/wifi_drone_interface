#ifndef MAVLINK_COMMUNICATOR_H
#define MAVLINK_COMMUNICATOR_H
#include <mavlink_types.h>
#include <ardupilotmega/mavlink.h>
// Qt
#include <QObject>
#include <QThread>
#include <QMap>
#include <QHostAddress>
#include <QQueue>
namespace domain
{
class AbstractLink;


class MavLinkCommunicator: public QObject
{
        Q_OBJECT

    public:
        MavLinkCommunicator(uint8_t systemId = 254, uint8_t componentId = 1,
                            QObject* parent = nullptr);

        QList<AbstractLink*> links() const;
        QMap<AbstractLink*, uint8_t> m_linkChannels;
        QMap<AbstractLink*, uint8_t> m_RecievedlinkChannels;
        QMap<AbstractLink*, uint8_t> m_chosenChannels;

        uint8_t systemId() const;
        uint8_t componentId() const;

    public slots:
        void addLink(AbstractLink* link, uint8_t channel);
        void removeLink(AbstractLink* link);
        void setSystemId(uint8_t systemId);
        void setComponentId(uint8_t componentId);

        void sendMessage(mavlink_message_t& message, AbstractLink* link);
        void sendMessageOnChannel(mavlink_message_t& message, uint8_t channel);
        void sendMessageOnAllLinks(mavlink_message_t& message);
        void sendMessageOnAllChosenLinks(mavlink_message_t& message);
        Q_INVOKABLE     void addLinkToChosen(const int& channel);
        Q_INVOKABLE     void removeLinkFromChosen(const int& channel);
    signals:
        void messageReceived(const mavlink_message_t& message);

    protected slots:
        void onDataReceived(const QByteArray& data);
    protected:

        AbstractLink* m_lastReceivedLink;

        uint8_t m_systemId;
        uint8_t m_componentId;


};

}
#endif // MAVLINK_COMMUNICATOR_H
