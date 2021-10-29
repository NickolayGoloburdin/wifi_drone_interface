#ifndef STATUS_HANDLER_H
#define STATUS_HANDLER_H
#include "abstract_handler.h"
#include <QString>

namespace domain
{
    class StatusHandler: public AbstractHandler
    {
        Q_OBJECT

    public:
        StatusHandler(MavLinkCommunicator* communicator);
    signals:
        void statusSignal(QString status);

    public slots:
        void processMessage(const mavlink_message_t& message) override;
    };
}
#endif // STATUS_HANDLER_H
