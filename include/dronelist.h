#ifndef DRONELIST_H
#define DRONELIST_H

#include <QWidget>
#include <QMap>

namespace Ui {
class DroneList;
}
namespace domain {
class AbstractLink;
}

class DroneList : public QWidget
{
    Q_OBJECT

public:
    DroneList(QMap<domain::AbstractLink*, uint8_t> links, QWidget *parent = nullptr);
    ~DroneList();
    Ui::DroneList *ui;
    QMap<domain::AbstractLink*, uint8_t> links_;
};

#endif // DRONELIST_H
