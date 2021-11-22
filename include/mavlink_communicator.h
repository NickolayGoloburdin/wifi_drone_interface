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
class AbstractClient;
class AbstractServer;
class DataParser;

class MavLinkCommunicator: public QObject
{
        Q_OBJECT

    public:
        MavLinkCommunicator(uint8_t systemId = 254, uint8_t componentId = 1,
                            QObject* parent = nullptr);

        QList<AbstractClient*> links() const;
        QMap<AbstractClient*, uint8_t> m_linkChannels;
        QMap<AbstractServer*, uint8_t> m_RecievedlinkChannels;
        QMap<AbstractClient*, uint8_t> m_chosenChannels;
        QMap<QString, QQueue<uint8_t>> m_UdpBuffers;
        uint8_t systemId() const;
        uint8_t componentId() const;

    public slots:
        void addLink(AbstractClient* link, uint8_t channel);
        void removeLink(AbstractClient* link);
        void addServer(AbstractServer* link, uint8_t channel);
        void removeServer(AbstractServer* link);
        void setSystemId(uint8_t systemId);
        void setComponentId(uint8_t componentId);

        void sendMessage(mavlink_message_t& message, AbstractClient* link);
        void sendMessageOnChannel(mavlink_message_t& message, uint8_t channel);
        void sendMessageOnAllLinks(mavlink_message_t& message);
        void sendMessageOnAllChosenLinks(mavlink_message_t& message);
        Q_INVOKABLE     void addLinkToChosen(const int& channel);
        Q_INVOKABLE     void removeLinkFromChosen(const int& channel);
    signals:
        void startParser();
        void messageReceived(const mavlink_message_t& message);

    protected slots:
        void onDataReceived(const QByteArray& data, QString sender);
        void dataParser(mavlink_message_t message);
    protected:

        AbstractServer* m_lastReceivedLink;

        uint8_t m_systemId;
        uint8_t m_componentId;
        QThread* thread_;
        DataParser* dataparser;
};
class DataParser: public QObject
{
        Q_OBJECT
    public:
        int count;
        DataParser(QMap<QString, QQueue<uint8_t>>* Buffers, QObject* parent = nullptr);
    public slots:
        void dataParse();
    signals:
        void messageParsed(const mavlink_message_t& message);
    private:
        QMap<QString, QQueue<uint8_t>>* udpBuffers;

};
}
#endif // MAVLINK_COMMUNICATOR_H
