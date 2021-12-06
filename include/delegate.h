#ifndef DELEGATE_H
#define DELEGATE_H

#include <QObject>
#include "qslistmodel.h"
#include <QDir>
#include <QQmlApplicationEngine>

#include "drone_container.h"
class Delegate: public QObject
{
        Q_OBJECT
    public:
        explicit Delegate(QString persistDir, QQmlApplicationEngine* engine, QObject *parent = 0);
        void run();
        QSListModel* droneStore_;
        QString path_;
        DroneContainer m_drone;

    signals:

    public slots:
        void persistDrones(); //NPM
        QByteArray stringifyDrones(); //NPM



        void addDrone(const int& droneUuid);
        void setGps(const int& droneUuid, int sattelites);
        void setvoltage(const int& droneUuid, int voltage);
        void setHeartbeat(const int& droneUuid, bool heartbeat);
        void removeDrone(const int& droneUuid);
        void setStatus(const int& droneUuid, QString& status);
        void setTcpLink(const int& droneUuid, bool tcp_link);


    private slots:

        void sync();
    private:
        QQmlApplicationEngine* engine_;


        // A fake trello board

};


#endif // DELEGATE_H
