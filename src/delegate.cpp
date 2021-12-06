#include "delegate.h"
#include "qsdiffrunner.h"
#include <QQmlContext>
Delegate::Delegate(QString persistDir, QQmlApplicationEngine* engine, QObject *parent): QObject(parent), path_(persistDir),
    engine_(engine)
{
    droneStore_ = new QSListModel();

}

void Delegate::run()
{
    m_drone.load(path_);
    engine_->rootContext()->setContextProperty("PersistFilePath", QString("setting.json"));
    engine_->rootContext()->setContextProperty("droneStore", droneStore_);
    engine_->rootContext()->setContextProperty("App", this);
    sync();

}



void Delegate::persistDrones()
{
    QFile file(path_);
    file.open(QIODevice::WriteOnly);
    file.write(Delegate::stringifyDrones());
    file.close();

}

QByteArray Delegate::stringifyDrones()
{
    m_drone.eraseAdditionaldata();
    sync();
    QVariantList drones;
    int count = droneStore_->storage().size();
    for (int i = 0 ; i < count ; i++) {
        drones << droneStore_->get(i);
    }

    QVariantMap map;
    map["drones"] = drones;
    QJsonObject object = QJsonObject::fromVariantMap(map);

    QJsonDocument doc;
    doc.setObject(object);
    QByteArray bytes = doc.toJson(QJsonDocument::Indented);

    return bytes;
}



void Delegate::addDrone(const int &droneUuid)
{
    m_drone.addDrone();
    sync();

}

void Delegate::setGps(const int &droneUuid, int sattelites)
{
    m_drone.setGps(droneUuid, sattelites);
    sync();
}

void Delegate::setvoltage(const int &droneUuid, int voltage)
{
    m_drone.setvoltage(droneUuid, voltage);
    sync();
}

void Delegate::setHeartbeat(const int &droneUuid, bool heartbeat)
{
    m_drone.setHeartbeat(droneUuid, heartbeat);
    sync();
}


void Delegate::removeDrone(const int &droneUuid)
{
    m_drone.removeDrone(droneUuid);
    sync();
}

void Delegate::setStatus(const int &droneUuid, QString &status)
{
    m_drone.setStatus(droneUuid,status);
    sync();
}

void Delegate::setTcpLink(const int &droneUuid, bool tcp_link)
{
    m_drone.setTcpLink(droneUuid, tcp_link);
    sync();
}

void Delegate::sync()
{
    QVariantMap map = m_drone.toMap();

    QVariantList drones = map["drones"].toList();

    QSDiffRunner runner;

    // It is important to set an unique key field on input data.
    // Otherwise, it won't be able to generate insertion, removal and move patch.
    runner.setKeyField("uuid");

    QList<QSPatch> patches = runner.compare(droneStore_->storage(),
                                            drones);

    runner.patch(droneStore_, patches);
}
