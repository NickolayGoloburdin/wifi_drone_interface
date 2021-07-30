#include "info_abstract_handler.h"

// Internal
#include "info_communicator.h"

using namespace domain;

InfoAbstractHandler::InfoAbstractHandler(InfoCommunicator* communicator):
    QObject(communicator),
    m_communicator(communicator)
{
    Q_ASSERT(communicator);
    connect(communicator, &InfoCommunicator::messageReceived,
            this, &InfoAbstractHandler::processMessage);
}
