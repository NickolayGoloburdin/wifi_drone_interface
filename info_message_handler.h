#ifndef INFO_MESSAGE_HANDLER_H
#define INFO_MESSAGE_HANDLER_H
#include "info_abstract_handler.h"

namespace domain
{
    class InfoMessageHandler: public InfoAbstractHandler
    {
        Q_OBJECT

    public:
        InfoMessageHandler( InfoCommunicator* communicator);

    signals:
        void CoordinatesSignal(QString x, QString y);

    public slots:
        void processMessage(QString message) override;

    };
}
#endif // INFO_MESSAGE_HANDLER_H
