#ifndef DRONE_UNITS_H
#define DRONE_UNITS_H

#include <QWidget>
#include <abstract_link.h>

namespace Ui {
class drone_units;
}

class drone_units : public QWidget
{
    Q_OBJECT

public:
    explicit drone_units(QWidget *parent = nullptr);
    ~drone_units();

private:
    Ui::drone_units *ui;
};

#endif // DRONE_UNITS_H
