#include "dronelist.h"
#include "ui_dronelist.h"

DroneList::DroneList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DroneList)
{
    ui->setupUi(this);
}

DroneList::~DroneList()
{
    delete ui;
}
