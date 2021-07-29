#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer_id_ =  this->startTimer(10000);
    ui->status->textCursor().insertText(QString("\nGui is started"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_connection(){
ui->connection->setText("Подключение: установлено");
this->killTimer(timer_id_);
timer_id_ =  this->startTimer(10000);
}
void MainWindow::timerEvent(QTimerEvent* event)
{
    Q_UNUSED(event)
    ui->connection->setText("Подключение: не  установлено");
}
void MainWindow::update_status(QString status){
    //ui->status->setText(ui->status->text() +QString("\n") + status );
    ui->status->textCursor().insertText(QString("\n") + status );
    //ui->status->
}
void MainWindow::update_sattelites(int sattelites){
    ui->sattelites->setText("Спутников:" + QString::number(sattelites));
}
void MainWindow::update_battery(int8_t battery_charge){
ui->battery->setText("Заряд дрона:" + QString::number(battery_charge)+ QString("%"));
}

void MainWindow::on_Arm_clicked()
{
    ui->status->textCursor().insertText(QString("\nArming..."));
    emit armSignal();
}

void MainWindow::on_Disarm_clicked()
{
    ui->status->textCursor().insertText(QString("\nDisarming..."));
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
   ui->status->textCursor().insertText(QString("\nFlight Plan Sending..."));
   emit missionSignal(x, y, x_land, y_land,height_takeoff, height_point, height_land);
}

void MainWindow::on_Start_clicked()
{
    ui->status->textCursor().insertText(QString("\nMission starting..."));
    emit startSignal();
}

void MainWindow::update_log_list(mavlink_log_entry_t log_entry){
    if (log_entry.size != 0)
    {
ui->log_list->setText(ui->log_list->text() + QString("id:") + QString(log_entry.id) + QString("\n") + QString("Total number of logs:") + QString(log_entry.num_logs) + QString("\n") + QString("High log number:") + QString(log_entry.last_log_num) + QString("\n"));
    }
    else
    {
        ui->log_list->setText(ui->log_list->text() + QString("В дроне нет сохраненных логов\n"));
    }
}
void MainWindow::on_log_list_request_clicked()
{
    ui->status->textCursor().insertText(QString("\nLog list request"));

    emit logListReqSignal();
}

void MainWindow::on_log_request_clicked()
{
    ui->status->textCursor().insertText(QString("\nLog request"));

    emit logReqSignal(ui->log_id->text().toInt());
}

void MainWindow::on_set_takeoff_speed_clicked()
{
    ui->status->textCursor().insertText(QString("\nTakeoff speed is uploaded"));
    emit takeoffSpeedSignal(ui->takeoff_speed->text().toFloat());
}

void MainWindow::on_set_land_speed_clicked()
{
    ui->status->textCursor().insertText(QString("\nLand speed is uploaded"));

    emit landSpeedSignal(ui->land_speed->text().toFloat());

}

void MainWindow::on_set_fly_speed_clicked()
{
    ui->status->textCursor().insertText(QString("\nFly speed is uploaded"));

    emit flySpeedSignal(ui->fly_speed->text().toFloat());
}
