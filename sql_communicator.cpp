#include "sql_communicator.h"
#include <QDate>
using namespace domain;
SQLCommunicator::SQLCommunicator(QString host, QString database, QString username, QString password){
    db = QSqlDatabase::addDatabase("QODBC3");
    db.setDatabaseName(QString("DRIVER={SQL Server};"
                               "SERVER=%1,1433;DATABASE=%2;"
                                           "uid=%3;pwd=%4;")
             .arg(host, database, username, password));

}
void SQLCommunicator::send_mission(QVector<mavlink_mission_item_int_t>& mission){

    if (!db.open()){emit sqlStatus(QString("База данных не подключена"));}
    else {emit sqlStatus(QString("База данных подключена"));}
    QString cd = QDate::currentDate().toString("yyyy-MM-dd");
    QString ct = QTime::currentTime().toString("hh:mm:ss.zzz");
    QString dateTime = cd + QString(" ") + ct;
    for (auto item : mission){
    QSqlQuery query;
        query.prepare("INSERT INTO [dbo].[mission_plans] ([mission_system_user_name],[mission_ip_address],[mission_operation_system],"
                      "[mission_name],[mission_create_datetime],[mission_ardupilot_version],[param1],[param2],[param3],[param4],[x],"
                      "[y],[z],[seq],[command],[target_system],"
                      "[target_component],[frame],[current],[autocontinue],[mission_type])"
                      "VALUES (:mission_system_user_name, :mission_ip_address, :mission_operation_system,"
                      ":mission_name, :mission_create_datetime, :mission_ardupilot_version, "
                      ":param1, :param2, :param3,:param4,:x, :y, :z, :seq,:command, :target_system, :target_component, :frame,:current,"
                      " :autocontinue, :mission_type)");
        query.bindValue(":mission_system_user_name", "NickolayGoloburdin");
        query.bindValue(":mission_ip_address", "172.31.144.1");
        query.bindValue(":mission_operation_system", "Windows");
        query.bindValue(":mission_name", "Anapa_spas_fly");
        query.bindValue(":mission_create_datetime", dateTime);//dwwddw!!!!
        query.bindValue(":mission_ardupilot_version", "3.5.0");
        query.bindValue(":param1", double(item.param1));
        query.bindValue(":param2", double(item.param2));
        query.bindValue(":param3", double(item.param3));
        query.bindValue(":param4", double(item.param4));
        query.bindValue(":x", double(item.x));
        query.bindValue(":y", double(item.y));
        query.bindValue(":z", double(item.z));
        query.bindValue(":seq", int(item.seq));
        query.bindValue(":command",int(item.command));
        query.bindValue(":target_system", int(item.target_system));
        query.bindValue(":target_component", int(item.target_component));
        query.bindValue(":frame", int(item.frame));
        query.bindValue(":current", int(item.current));
        query.bindValue(":autocontinue", int(item.autocontinue));
        query.bindValue(":mission_type", int(item.mission_type));
        query.exec();
}
}

