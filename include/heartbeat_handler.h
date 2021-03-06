#ifndef HEARTBEAT_HANDLER_H
#define HEARTBEAT_HANDLER_H
#include "abstract_handler.h"
#include <QMap>
namespace domain
{
class HeartbeatHandler: public AbstractHandler
{
        Q_OBJECT

    public:
        HeartbeatHandler(uint8_t type, MavLinkCommunicator* communicator);
    protected:
        void timerEvent(QTimerEvent *event) override;

    signals:
        void HeartbeatSignal(int id, bool heartbeat);

    public slots:
        void processMessage(const mavlink_message_t& message) override;
    private:
        const uint8_t m_type;
        QMap<int, bool> heartbeats;
};
}

#endif // HEARTBEAT_HANDLER_H
