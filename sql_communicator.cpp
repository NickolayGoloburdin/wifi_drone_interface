#include "sql_communicator.h"
#include <QDate>
using namespace domain;
SQLCommunicator::SQLCommunicator(QString host, QString database, QString username, QString password){
    db = QSqlDatabase::addDatabase("QODBC3");
    db.setDatabaseName(QString("DRIVER={SQL Server};"
                               "SERVER=%1;DATABASE=%2;Persist Security Info=true;"
                                           "uid=%3;pwd=%4")
              .arg(host, database, username, password));
    if (!db.open()){qDebug() << "succesfull";}
    else {qDebug() << "failed";}

}
void SQLCommunicator::send_mission(QVector<mavlink_mission_item_int_t>& mission){

    QString date = QDate::currentDate().toString();
    for (auto item : mission){
    QSqlQuery query;
        query.prepare("INSERT INTO [dbo].[mission_plans] ([mission_system_user_name],[mission_ip_address],[mission_operation_system],"
                      "[mission_name],[mission_create_datetime],[mission_ardupilot_version],[param1],[param2],[param3],[param4],[x],[y],[z],[seq],[command],[target_system],"
                      "[target_component],[frame],[current],[autocontinue],[mission_type]))"
                      "VALUES (:mission_system_user_name, :mission_ip_address, :mission_operation_system,"
                      ":mission_name, :mission_create_datetime, :mission_ardupilot_version, "
                      ":param1, :param2, :param3,:param4,:x, :y, :z, :seq,:command, :target_system, :target_component, :frame,:current, :autocontinue, :mission_type)");
        query.bindValue(":mission_system_user_name", "NickolayGoloburdin");
        query.bindValue(":mission_ip_address", "172.31.144.1");
        query.bindValue(":mission_operation_system", "Windows");
        query.bindValue(":mission_name", "Anapa_spas_fly");
        query.bindValue(":mission_create_datetime", date);
        query.bindValue(":mission_ardupilot_version", "3.5.0");
        query.bindValue(":param1", item.param1);
        query.bindValue(":param2", item.param2);
        query.bindValue(":param3", item.param3);
        query.bindValue(":param4", item.param4);
        query.bindValue(":x", item.x);
        query.bindValue(":y", item.y);
        query.bindValue(":z", item.z);
        query.bindValue(":seq", item.seq);
        query.bindValue(":command", item.command);
        query.bindValue(":target_system", item.target_system);
        query.bindValue(":target_component", item.target_component);
        query.bindValue(":frame", item.frame);
        query.bindValue(":current", item.current);
        query.bindValue(":autocontinue", item.autocontinue);
        query.bindValue(":mission_type", item.mission_type);
        query.exec();
}
}

