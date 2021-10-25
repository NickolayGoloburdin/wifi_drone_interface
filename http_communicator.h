#ifndef HTTP_COMMUNICATOR_H
#define HTTP_COMMUNICATOR_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QApplication>
#include "mavlink_communicator.h"

namespace httpc {
class HTTPCommunicator : public QObject {
Q_OBJECT
public:
    explicit HTTPCommunicator(QString url, QString user_name_, QString operation_system_, QString ardu_version_, QObject* parent = nullptr);
    void send_mission_json(QVector<mavlink_mission_item_int_t>& mission) const;

    QNetworkAccessManager *manager;
private:
    QString url_string;
    QString user_name;
    QString operation_system;
    QString ardu_version;
    QString ip_address;

    void get_self_ip();
};
}
#endif // HTTP_COMMUNICATOR_H
