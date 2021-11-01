#ifndef ABSTRACT_COMMUNICATOR_FACTORY_H
#define ABSTRACT_COMMUNICATOR_FACTORY_H
#include <tuple>

namespace domain
{
    class MavLinkCommunicator;
    class InfoCommunicator;

    class AbstractCommunicatorFactory
    {
    public:
        AbstractCommunicatorFactory();
        virtual ~AbstractCommunicatorFactory();

        virtual std::tuple<MavLinkCommunicator*, InfoCommunicator*> create() = 0;
    };
}
#endif // ABSTRACT_COMMUNICATOR_FACTORY_H
