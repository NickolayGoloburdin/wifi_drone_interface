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
        void addDrone(int id, QString ip, int port);
        void removeDrone(int& uuid);
        void setGps(const int& droneUuid, int sattelites);
        void setvoltage(const int& droneUuid, int voltage);
        void setHeartbeat(const int& droneUuid, bool heartbeat);
        void setStatus(const int& droneUuid, QString& status);
        void setTcpLink(const int& droneUuid, bool tcp_link);
        void removeDrone(const int& droneUuid);
        void load(const QString &persistFilePath);
        void failsafeLoad();
        void eraseAdditionaldata();
        QVariantMap toMap() const;
        QList<Drone> drones_;


    private:


};

#endif // DRONECONTAINER_H
