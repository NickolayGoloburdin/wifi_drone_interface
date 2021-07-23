#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer_id_ =  this->startTimer(10000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_connection(){
ui->connection->setText("Подключение:\nустановлено");
this->killTimer(timer_id_);
timer_id_ =  this->startTimer(10000);
}
void MainWindow::timerEvent(QTimerEvent* event)
{
    Q_UNUSED(event)
    ui->connection->setText("Подключение:\nне  установлено");
}
void MainWindow::update_status(QString status){
    ui->status->setText(ui->status->text() +QString("\n") + status );
}
void MainWindow::update_sattelites(int sattelites){
    ui->sattelites->setText("Спутников:" + QString::number(sattelites));
}
void MainWindow::update_battery(int8_t battery_charge){
ui->battery->setText("Заряд дрона:" + QString::number(battery_charge)+ QString("%"));
}

void MainWindow::on_Arm_clicked()
{
    emit armSignal();
}

void MainWindow::on_Disarm_clicked()
{
    emit disarmSignal();

}

void MainWindow::on_SendPoint_clicked()
{
   int x,y,x_land, y_land, height_takeoff, height_point, height_land;
   x = static_cast<int>(10000000*(ui->attitude->text().toDouble()));
   y = static_cast<int>(10000000*(ui->longtitude->text().toDouble()));
   x_land = static_cast<int>(10000000*(ui->land_x->text().toDouble()));
   y_land = static_cast<int>(10000000*(ui->land_y->text().toDouble()));
   height_takeoff = static_cast<float>(ui->height_takeoff->text().toDouble());
   height_point = static_cast<float>(ui->height_point->text().toDouble());
   height_land = static_cast<float>(ui->height_land->text().toDouble());
   emit missionSignal(x, y, x_land, y_land,height_takeoff, height_point, height_land);
}

void MainWindow::on_Start_clicked()
{
    emit startSignal();
}

void MainWindow::update_log_list(mavlink_log_entry_t log_entry){
ui->log_list->setText(ui->log_list->text() + QString("id:") + QString(log_entry.id) + QString("\n") + QString("Total number of logs:") + QString(log_entry.num_logs) + QString("\n") + QString("High log number:") + QString(log_entry.last_log_num) + QString("\n"));

}
void MainWindow::on_log_list_request_clicked()
{
    emit logListReqSignal();
}

void MainWindow::on_log_request_clicked()
{
    emit logReqSignal(ui->log_id->text().toInt());
}
