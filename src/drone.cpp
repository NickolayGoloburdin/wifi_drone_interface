#include "drone.h"

Drone::Drone(): uuid_(0),
    ip_("192.0.0.0"),
    heartbeat_(false),
    sattelites_(0),
    voltage_(0),
    status_("empty")
{

}

Drone::Drone(int uuid,
             QString ip,
             bool heartbeat,
             int sattelites,
             int voltage,
             QString status): uuid_(uuid),
    ip_(ip),
    heartbeat_(heartbeat),
    sattelites_(sattelites),
    voltage_(voltage),
    status_(status)
{

}

const int &Drone::uuid() const
{
    return uuid_;
}

void Drone::setGps(int sattelites)
{
    sattelites_ = sattelites;
}

void Drone::setvoltage(int voltage)
{
    voltage_ = voltage;
}

void Drone::setHeartbeat(bool heartbeat)
{
    heartbeat_ = heartbeat;
}

void Drone::setStatus(QString& status)
{
    status_ += ("\n" + status);
}

void Drone::eraseStatus()
{
    status_ = "Terminal started";
}

void Drone::eraseVoltage()
{
    voltage_ = 0;
}

QVariantMap Drone::toMap() const
{
    QVariantMap res;
    res["uuid"] = uuid_;
    res["ip"] = ip_;
    res["heartbeat"] = heartbeat_;
    res["sattelites"] = sattelites_;
    res["voltage"] = voltage_;
    res["status"] = status_;
    return res;
}
