#ifndef SQL_COMMUNICATOR_H
#define SQL_COMMUNICATOR_H
#include <QtSql>
#include <QString>
#include <QVector>
#include "mavlink_communicator.h"
namespace domain {
class SQLCommunicator: public QObject{
    Q_OBJECT
public:
    explicit SQLCommunicator(QString host, QString database, QString username, QString password);
    SQLCommunicator() = delete;
public slots:
    void send_mission(QVector<mavlink_mission_item_int_t>& mission);
signals:
    void sqlStatus(QString status);
private:
    QSqlDatabase db;

};
}
#endif // SQL_COMMUNICATOR_H
