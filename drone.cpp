#include "drone.h"
#include "abstract_link.h"
Drone::Drone(AbstractLink* link, int target_system_id, QString ip_address):target_link_(link),
    target_system_id_(target_system_id),ip_address_(ip_address){

}
