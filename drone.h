#ifndef DRONE_H
#define DRONE_H

#include <QString>

class AbstractLink;
class Drone
{
    Drone() = delete;
public:
    explicit Drone(AbstractLink* link, int target_system_id, QString ip_address);
    AbstractLink* target_link_;
    int target_system_id_;
    QString ip_address_;
};

#endif // DRONE_H
