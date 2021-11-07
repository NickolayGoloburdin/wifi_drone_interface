#include "log_handler.h"

// MAVLink


// Qt
#include <QtMath>
#include <QDebug>
#include <QTextStream>
#include <QFile>

using namespace domain;

LogHandler::LogHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator)
{}

void LogHandler::processMessage(const mavlink_message_t& message)
{
    switch (message.msgid) {
        case MAVLINK_MSG_ID_LOG_ENTRY:
            mavlink_log_entry_t log_entry;
            mavlink_msg_log_entry_decode(&message, &log_entry);
            emit logEntrySignal(log_entry, message.sysid);
            break;
        case MAVLINK_MSG_ID_LOG_DATA:
            mavlink_log_data_t log_data;
            mavlink_msg_log_data_decode(&message, &log_data);
            //emit logDataSignal(log_data);
            QString filename = "C:\\logs.txt";
            QFile file(filename);
            if (file.open(QIODevice::ReadWrite)) {
                QTextStream out(&file);
                out << "id:" << log_data.id << endl;
                out << "data" << log_data.data << endl;

            } else {

                qWarning("Could not open file");
            }

            file.close();
            break;
    }


}
