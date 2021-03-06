#include "drone_container.h"
#include <QFile>
#include <QTextStream>
#include <QJsonParseError>
#include <QtCore>
#include "drone.h"
DroneContainer::DroneContainer()
{

}


DroneContainer::~DroneContainer()
{

}

QList<Drone> DroneContainer::drones() const
{
    return drones_;
}

void DroneContainer::addDrone(int id, QString ip, int port)
{
    drones_.append(Drone(id, ip, port));
}

void DroneContainer::removeDrone(const int &uuid)
{
    for (int i = 0 ; i < drones_.size() ; i++) {
        Drone& drone = drones_[i];
        if (drone.uuid() == uuid) {
            drones_.removeAt(i);
            break;
        }
    }
}

void DroneContainer::setGps(const int &droneUuid, int sattelites)
{
    for (int i = 0 ; i < drones_.size() ; i++) {
        Drone& drone = drones_[i];
        if (drone.uuid() == droneUuid) {
            drone.setGps(sattelites);
            break;
        }
    }
}

void DroneContainer::setvoltage(const int &droneUuid, int voltage)
{
    for (int i = 0 ; i < drones_.size() ; i++) {
        Drone& drone = drones_[i];
        if (drone.uuid() == droneUuid) {
            drone.setvoltage(voltage);
            break;
        }
    }
}

void DroneContainer::setHeartbeat(const int &droneUuid, bool heartbeat)
{
    for (int i = 0 ; i < drones_.size() ; i++) {
        Drone& drone = drones_[i];
        if (drone.uuid() == droneUuid) {
            drone.setHeartbeat(heartbeat);
            break;
        }
    }

}

void DroneContainer::setStatus(const int &droneUuid, QString &status)
{
    for (int i = 0 ; i < drones_.size() ; i++) {
        Drone& drone = drones_[i];
        if (drone.uuid() == droneUuid) {
            drone.setStatus(status);
            break;
        }
    }
}

void DroneContainer::setTcpLink(const int &droneUuid, bool tcp_link)
{
    for (int i = 0 ; i < drones_.size() ; i++) {
        Drone& drone = drones_[i];
        if (drone.uuid() == droneUuid) {
            drone.setTcpLink(tcp_link);
            break;
        }
    }
}




void DroneContainer::load(const QString &persistFilePath)
{
    QFile file(persistFilePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "NOTE: using default board because no persistence file found: " << persistFilePath;
        DroneContainer::failsafeLoad();
    } else {
        QTextStream stream(&file);
        QString text = stream.readAll();
        file.close();

        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(text.toUtf8(), &error);

        if (error.error != QJsonParseError::NoError) {
            qWarning() << "JSON::parse() error: " << error.errorString();
            qWarning() << "NOTE: using default board because persistence file is malformed: " << persistFilePath;
            DroneContainer::failsafeLoad();
        } else {
            QVariantMap     map        = doc.object().toVariantMap();
            QList<QVariant> drones      = map.value("drones").toList();
            int             dronesCount = drones.size();
            for (int i = 0; i < dronesCount; i++) {
                QMap<QString, QVariant> dronesMap  = drones[i].toMap();
                int     uuid = dronesMap.value("uuid").toInt();
                QString     ip = dronesMap.value("ip").toString();
                int         port = dronesMap.value("port").toInt();
                bool        heartbeat = dronesMap.value("heartbeat").toBool();
                int         sattelites = dronesMap.value("sattelites").toInt();
                int         voltage =   dronesMap.value("voltage").toInt();
                QString     status = dronesMap.value("status").toString();
                bool tcp_link = dronesMap.value("tcp_link").toBool();
                drones_ << (Drone(uuid, ip, heartbeat, sattelites, voltage, port, status, tcp_link ));
            }

        }

    }
}

void DroneContainer::failsafeLoad()
{

    drones_ << Drone(0,"127.0.0.1", 5760);}

void DroneContainer::eraseAdditionaldata()
{
    for (Drone& i : drones_) {
        i.eraseStatus();
        i.setHeartbeat(false);
        i.eraseVoltage();
        i.setTcpLink(false);
        i.setGps(0);

    }
}

QVariantMap DroneContainer::toMap() const
{
    QVariantMap res;
    QVariantList drones;
    for (int i = 0 ; i < drones_.size() ; i++) {
        drones << drones_[i].toMap();
    }
    res["drones"] = drones;
    return res;
}


