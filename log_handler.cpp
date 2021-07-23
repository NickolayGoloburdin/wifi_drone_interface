#include "log_handler.h"

// MAVLink


// Qt
#include <QtMath>
#include <QDebug>

using namespace domain;

LogHandler::LogHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator)
{}

void LogHandler::processMessage(const mavlink_message_t& message)
{
    switch(message.msgid ){
    case MAVLINK_MSG_ID_LOG_ENTRY:
        mavlink_log_entry_t log_entry;
        mavlink_msg_log_entry_decode(&message, &log_entry);
        emit logEntrySignal(log_entry);
        break;
    case MAVLINK_MSG_ID_LOG_DATA:
        mavlink_log_data_t log_data;
        mavlink_msg_log_data_decode(&message, &log_data);
        emit logDataSignal(log_data);
        break;
    }


}
