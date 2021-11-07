#ifndef LOG_HANDLER_H
#define LOG_HANDLER_H
#include "abstract_handler.h"
#include <ardupilotmega/mavlink.h>
namespace domain
{
class LogHandler: public AbstractHandler
{
    Q_OBJECT

public:
    LogHandler(MavLinkCommunicator* communicator);
signals:
    void logEntrySignal(mavlink_log_entry_t log_entry, int id);
    void logDataSignal(mavlink_log_data_t lof_data, int id);

public slots:
    void processMessage(const mavlink_message_t& message) override;
};
}
#endif // LOG_HANDLER_H
