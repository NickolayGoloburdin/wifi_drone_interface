#ifndef BATTERY_HANDLER_H
#define BATTERY_HANDLER_H
#include "abstract_handler.h"

namespace domain
{
class BatteryHandler: public AbstractHandler
{
    Q_OBJECT

public:
    BatteryHandler(MavLinkCommunicator* communicator);
signals:
    void BatterySignal(const QString& id, int8_t battery_rem);
public slots:
    void processMessage(const mavlink_message_t& message) override;
};
}
#endif // BATTERY_HANDLER_H
