#include "http_communicator.h"
#include <QDate>
using namespace httpc;

HTTPCommunicator::HTTPCommunicator(QString url, QString user_name_, QString operation_system_, QString ardu_version_, QObject* parent):
                                    user_name(user_name_), operation_system(operation_system_), ardu_version(ardu_version_), QObject(parent){
    manager = new QNetworkAccessManager();
    url_string = "http://" + url;
    get_self_ip();
}

void HTTPCommunicator::get_self_ip(){
        const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
        for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
            if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
                 ip_address = address.toString();
        }
}

void HTTPCommunicator::send_mission_json(QVector<mavlink_mission_item_int_t>& mission) const {

    const QUrl url(url_string);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject obj;

    QString cd = QDate::currentDate().toString("yyyy-MM-dd");
    QString ct = QTime::currentTime().toString("hh:mm:ss");
    QString dateTime = cd + QString("T") + ct + QString("Z");
    obj["mission_system_user_name"] = user_name;
    obj["mission_ip_address"] = ip_address;
    obj["mission_operation_system"] = operation_system;
    obj["mission_name"] = "mission_name";
    obj["mission_create_datetime"] = dateTime;
    obj["mission_ardupilot_version"] = ardu_version;

    for (auto item : mission){
        obj["param1"] = item.param1;
        obj["param2"] = item.param2;
        obj["param3"] = item.param3;
        obj["param4"] = item.param4;
        obj["x"] = item.x;
        obj["y"] = item.y;
        obj["z"] = item.z;
        obj["seq"] = item.seq;
        obj["command"] = item.command;
        obj["target_system"] = item.target_system;
        obj["target_component"] = item.target_component;
        obj["frame"] = item.frame;
        obj["current"] = item.current;
        obj["autocontinue"] = item.autocontinue;
        obj["mission_type"] = item.mission_type;
        QJsonDocument doc(obj);
        QByteArray data = doc.toJson();

        QNetworkReply *reply = manager->post(request, data);


        QObject::connect(reply, &QNetworkReply::finished, [=](){
            if(reply->error() == QNetworkReply::NoError){
                QString contents = QString::fromUtf8(reply->readAll());
                qDebug() << contents;
            }
            else{
                QString err = reply->errorString();
                qDebug() << err;
            }
            reply->deleteLater();
        });
    }
}
