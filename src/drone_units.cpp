#include "drone_units.h"
#include "ui_drone_units.h"

drone_units::drone_units(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::drone_units)
{
    ui->setupUi(this);
}

drone_units::~drone_units()
{
    delete ui;
}
