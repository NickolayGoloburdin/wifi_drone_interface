#ifndef HEARTBEART_HANDLER_H
#define HEARTBEART_HANDLER_H
#include "abstract_handler.h"

namespace domain
{
    class HeartbeatHandler: public AbstractHandler
    {
        Q_OBJECT

    public:
        HeartbeatHandler(uint8_t type, MavLinkCommunicator* communicator);

    protected:
        void timerEvent(QTimerEvent *event) override;

    public slots:
        void processMessage(const mavlink_message_t& message) override;

    private:
        const uint8_t m_type;
    };
}

#endif // HEARTBEART_HANDLER_H
