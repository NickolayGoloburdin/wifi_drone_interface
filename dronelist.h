#ifndef DRONELIST_H
#define DRONELIST_H

#include <QWidget>

namespace Ui {
class DroneList;
}

class DroneList : public QWidget
{
    Q_OBJECT

public:
    explicit DroneList(QWidget *parent = nullptr);
    ~DroneList();
    Ui::DroneList *ui;
};

#endif // DRONELIST_H
