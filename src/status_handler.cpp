#include "status_handler.h"

// MAVLink
#include <ardupilotmega/mavlink.h>

// Qt
#include <QtMath>
#include <QDebug>

using namespace domain;

StatusHandler::StatusHandler(MavLinkCommunicator* communicator):
    AbstractHandler(communicator)
{}

void StatusHandler::processMessage(const mavlink_message_t& message)
{
    if (message.msgid != MAVLINK_MSG_ID_STATUSTEXT ||
        message.sysid == 0) return;

    mavlink_statustext_t text;
    mavlink_msg_statustext_decode(&message, &text);
    QString status = QString(text.text);
    emit statusSignal(status, message.msgid);


}
