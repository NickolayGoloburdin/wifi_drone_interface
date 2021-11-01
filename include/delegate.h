#ifndef DELEGATE_H
#define DELEGATE_H

#include <QObject>
#include "qslistmodel.h"
#include <QDir>

#include "drone_container.h"
class Delegate: public QObject
{
    Q_OBJECT
public:
     explicit Delegate(QString persistDir, QObject *parent = 0);
    void run();
    QSListModel* droneStore_;
    QString path_;
    signals:

    public slots:
        void persistDrones(); //NPM
        QByteArray stringifyDrones(); //NPM



        void addDrone(const QString& droneUuid);
        void setGps(const QString& droneUuid, int sattelites);
        void setvoltage(const QString& droneUuid, int voltage);
        void setHeartbeat(const QString& droneUuid, bool heartbeat);
        void removeDrone(const QString& droneUuid);


    private slots:

        void sync();

    private:

        // A fake trello board
        DroneContainer m_drone;
    };


#endif // DELEGATE_H
