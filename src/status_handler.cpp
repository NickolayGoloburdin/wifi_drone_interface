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
    if (message.msgid == MAVLINK_MSG_ID_PARAM_VALUE) {
        mavlink_param_value_t param;
        mavlink_msg_param_value_decode(&message, &param);

        QString status = QString("Параметр ") + QString(param.param_id) + QString(" установлен в: ") + QString::number(param.param_value); ;
        emit statusSignal(message.sysid, status);
    }
    if (message.msgid != MAVLINK_MSG_ID_STATUSTEXT ||
            message.sysid == 0) return;

    mavlink_statustext_t text;
    mavlink_msg_statustext_decode(&message, &text);
    QString status = QString(text.text);
    emit statusSignal(message.sysid, status);
    qWarning() << status + "    message id: " + QString::number(message.sysid);


}
