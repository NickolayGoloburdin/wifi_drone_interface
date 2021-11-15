#ifndef DRONE_H
#define DRONE_H
#include <QString>
#include <QVariantMap>
class Drone
{
    public:
        Drone();
        Drone(int uuid, QString ip,
              bool heartbeat,
              int sattelites,
              int voltage,
              QString status);
        int uuid_;
        QString ip_;
        bool heartbeat_;
        int sattelites_;
        int voltage_;
        QString status_;
        const int & uuid() const;
        void setGps(int sattelites);
        void setvoltage(int voltage);
        void setHeartbeat(bool heartbeat);
        void setStatus(QString& status);
        void eraseStatus();
        void eraseVoltage();
        QVariantMap toMap() const;
};

#endif // DRONE_H
