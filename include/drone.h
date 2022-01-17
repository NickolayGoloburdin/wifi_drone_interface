#ifndef DRONE_H
#define DRONE_H
#include <QString>
#include <QVariantMap>
class Drone
{
    public:
        Drone();
        Drone(int id, QString ip);
        Drone(int uuid, QString ip,
              bool heartbeat,
              int sattelites,
              int voltage,
              int port,
              QString status, bool tcp_link);
        int uuid_;
        QString ip_;
        int port_;
        const int & uuid() const;
        void setGps(int sattelites);
        void setTcpLink(bool tcp_link);
        void setvoltage(int voltage);
        void setHeartbeat(bool heartbeat);
        void setStatus(QString& status);
        void eraseStatus();
        void eraseVoltage();
        QVariantMap toMap() const;
    private:
        bool heartbeat_;
        int sattelites_;
        int voltage_;
        QString status_;
        bool tcp_link_;
};

#endif // DRONE_H
