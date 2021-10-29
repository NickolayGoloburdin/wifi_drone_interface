#include "dronelist.h"
#include "ui_dronelist.h"
#include "abstract_link.h"
using namespace domain;
DroneList::DroneList(QMap<AbstractLink*, uint8_t> links, QWidget *parent):
    QWidget(parent),
    ui(new Ui::DroneList),
    links_(links)
{
    ui->setupUi(this);
//    widget = new drone_units(scrollAreaWidgetContents);
//    widget->setObjectName(QString::fromUtf8("widget"));
//    widget->setGeometry(QRect(30, 30, 201, 51));
//    widget_2 = new drone_units(scrollAreaWidgetContents);
//    widget_2->setObjectName(QString::fromUtf8("widget_2"));
//    widget_2->setGeometry(QRect(30, 120, 201, 61));
//    scrollArea->setWidget(scrollAreaWidgetContents);
}

DroneList::~DroneList()
{
    delete ui;
}
