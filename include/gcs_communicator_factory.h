#ifndef GCS_COMMUNICATOR_FACTORY_H
#define GCS_COMMUNICATOR_FACTORY_H
#include "abstract_communicator_factory.h"
#include <tuple>
#include <QVariantList>
namespace domain
{
class GcsCommunicatorFactory: public AbstractCommunicatorFactory
{
public:
    GcsCommunicatorFactory();

    std::tuple<MavLinkCommunicator*, InfoCommunicator*> create() override;
};
}

#endif // GCS_COMMUNICATOR_FACTORY_H
