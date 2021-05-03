#include "gcs_communicator_factory.h"

// MAVLink
#include <mavlink.h>

// Internal
#include "mavlink_communicator.h"

#include "heartbeat_handler.h"
#include "attitude_handler.h"
#include "gps_handler.h"
#include "battery_handler.h"

using namespace domain;

GcsCommunicatorFactory::GcsCommunicatorFactory()
{}

MavLinkCommunicator* GcsCommunicatorFactory::create()
{
    MavLinkCommunicator* communicator = new MavLinkCommunicator(255, 0);

    new domain::HeartbeatHandler(MAV_TYPE_GCS, communicator);
    new domain::AttitudeHandler(communicator);
    new domain::GPSHandler(communicator);
    new::domain::BatteryHandler(communicator);


    return communicator;
}
