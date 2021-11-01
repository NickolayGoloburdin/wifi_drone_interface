#ifndef DRONECONTAINER_H
#define DRONECONTAINER_H
#include <QSharedDataPointer>
#include <QVariantMap>
class Drone;
class DroneContainer
{
public:
    DroneContainer();
    ~DroneContainer();
    QList<Drone> drones() const;
    void addDrone();
    void removeDrone(QString& uuid);
    void setGps(const QString& droneUuid, int sattelites);
    void setvoltage(const QString& droneUuid, int voltage);
    void setHeartbeat(const QString& droneUuid, bool heartbeat);
    void removeDrone(const QString& droneUuid);
    void load(const QString &persistFilePath);
    void failsafeLoad();
    QVariantMap toMap() const;
    QList<Drone> drones_;


private:


};

#endif // DRONECONTAINER_H
