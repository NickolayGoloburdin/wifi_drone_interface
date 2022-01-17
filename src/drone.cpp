#include "drone.h"

Drone::Drone(): uuid_(0),
    ip_("127.0.0.1"),
    port_(5760),
    heartbeat_(false),
    sattelites_(0),
    voltage_(0),
    status_("empty"),
    tcp_link_(false)

{

}

Drone::Drone(int id, QString ip):uuid_(id),
                                ip_(ip),
                                port_(5760),
                                heartbeat_(false),
                                sattelites_(0),
                                voltage_(0),
                                status_("empty"),
                                tcp_link_(false)
{

}

Drone::Drone(int uuid,
             QString ip,
             bool heartbeat,
             int sattelites,
             int voltage,
             int port,
             QString status, bool tcp_link): uuid_(uuid),
    ip_(ip),

    port_(port),
    heartbeat_(heartbeat),
    sattelites_(sattelites),
    voltage_(voltage),
    status_(status),
    tcp_link_(tcp_link)
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

void Drone::setTcpLink(bool tcp_link)
{
    tcp_link_ = tcp_link;
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
    res["port"] = port_;
    res["heartbeat"] = heartbeat_;
    res["sattelites"] = sattelites_;
    res["voltage"] = voltage_;
    res["status"] = status_;
    res["tcp_link"] = tcp_link_;

    return res;
}
