#include "info_message_handler.h"

// Qt
#include <QtMath>
#include <QDebug>
#include <QStringList>

using namespace domain;

InfoMessageHandler::InfoMessageHandler(InfoCommunicator* communicator):
    InfoAbstractHandler(communicator)
{}

void InfoMessageHandler::processMessage(QString message)
{
    if (message[0] != '#') {
        return;
    }
    QStringList coordinates = message.split('#');

    if (coordinates.at(1) == "start") {
        emit StartSignal();
    } else

        emit CoordinatesSignal(coordinates.at(1), coordinates.at(2));


}
