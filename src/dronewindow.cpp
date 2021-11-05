#include "dronewindow.h"
#include "ui_DroneWindow.h"
#include <QScrollBar>
#include <QCoreApplication>
#include <QNetworkConfigurationManager>
#include <QNetworkConfiguration>
#include <QDebug>
#include <QNetworkSession>

DroneWindow::DroneWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DroneWindow)
{
    ui->setupUi(this);
    timer_id_ =  this->startTimer(10000);
    ui->status->textCursor().insertText(QString("\nИнтерфейс запущен"));


}

DroneWindow::~DroneWindow()
{
    delete ui;
}

void DroneWindow::update_connection(){
    ui->connection->setText("Подключение: установлено");
    this->killTimer(timer_id_);
    timer_id_ =  this->startTimer(10000);
}
void DroneWindow::timerEvent(QTimerEvent* event)
{
    Q_UNUSED(event)
    ui->connection->setText("Подключение: не установлено");
    //ui->status->textCursor().insertText(QString("\nСоединение потеряно"));
}
void DroneWindow::update_status(QString status){
    //ui->status->setText(ui->status->text() +QString("\n") + status );
    if (status == QString("Flight plan recieved")){

        ui->status->textCursor().insertText(QString("\n") + "Полетный план получен" );
    }
    else{
        ui->status->textCursor().insertText(QString("\n") + status );
    }
        ui->status->verticalScrollBar()->setValue(ui->status->verticalScrollBar()->maximum());

}
void DroneWindow::update_sattelites(int sattelites){
    ui->sattelites->setText("Спутников:" + QString::number(sattelites));
}
void DroneWindow::update_battery(int8_t battery_charge){
    ui->battery->setText("Заряд дрона:" + QString::number(battery_charge)+ QString("%"));
}
void DroneWindow::update_coordinates(QString in_x, QString in_y){

    ui->attitude->setText(in_x);
    ui->longtitude->setText(in_y);

//QMessageBox::warning(this, "Внимание", "Координаты точки для сброса обновлены, можно загружать полетное задание");
    on_SendPoint_clicked();
}

void DroneWindow::on_Arm_clicked()
{
    ui->status->textCursor().insertText(QString("\nЗапуск..."));
    ui->status->verticalScrollBar()->setValue(ui->status->verticalScrollBar()->maximum());
    emit armSignal();
    //QMessageBox::warning(this,"Внимание", "Координаты точки для сброса обновлены, можно загружать полетное задание");

}

void DroneWindow::on_Disarm_clicked()
{
    ui->status->textCursor().insertText(QString("\nВыключение двигателей..."));
    ui->status->verticalScrollBar()->setValue(ui->status->verticalScrollBar()->maximum());
    emit disarmSignal();

}

void DroneWindow::on_SendPoint_clicked()
{
   int x,y,x_land, y_land, height_takeoff, height_point, height_land;
   bool manual_drop,db_send;
   x = static_cast<int>(10000000*(ui->attitude->text().toDouble()));
   y = static_cast<int>(10000000*(ui->longtitude->text().toDouble()));
   x_land = static_cast<int>(10000000*(ui->land_x->text().toDouble()));
   y_land = static_cast<int>(10000000*(ui->land_y->text().toDouble()));
   height_takeoff = static_cast<float>(ui->height_takeoff->text().toDouble());
   height_point = static_cast<float>(ui->height_point->text().toDouble());
   height_land = static_cast<float>(ui->height_land->text().toDouble());
   manual_drop = ui->manual_drop->isChecked();
   db_send = ui->db_upload->isChecked();
   ui->status->textCursor().insertText(QString("\nОтправка полетного задания..."));
   if (db_send) ui->status->textCursor().insertText(QString("\nЗагрузка в базу данных..."));
   else ui->status->textCursor().insertText(QString("\nБез загрузки в базу данных"));
   ui->status->verticalScrollBar()->setValue(ui->status->verticalScrollBar()->maximum());
   emit missionSignal(x, y, x_land, y_land,height_takeoff, height_point, height_land,manual_drop,db_send);
}

void DroneWindow::on_Start_clicked()
{
    ui->status->textCursor().insertText(QString("\nЗапуск миссии..."));
    ui->status->verticalScrollBar()->setValue(ui->status->verticalScrollBar()->maximum());
    emit startSignal();
}

void DroneWindow::update_log_list(mavlink_log_entry_t log_entry){
    if (log_entry.size != 0)
    {
        ui->log_list->setText(ui->log_list->text() + QString("id:") + QString(log_entry.id) + QString("\n") + QString("Total number of logs:") + QString(log_entry.num_logs) + QString("\n") + QString("High log number:") + QString(log_entry.last_log_num) + QString("\n"));
    }
    else
    {
        ui->log_list->setText(ui->log_list->text() + QString("В дроне нет сохраненных логов\n"));
    }
}
void DroneWindow::on_log_list_request_clicked()
{
    ui->status->textCursor().insertText(QString("\nЗапрошен лист логов"));
    ui->status->verticalScrollBar()->setValue(ui->status->verticalScrollBar()->maximum());

    emit logListReqSignal();
}

void DroneWindow::on_log_request_clicked()
{
    ui->status->textCursor().insertText(QString("\nЗапрос логов"));
    ui->status->verticalScrollBar()->setValue(ui->status->verticalScrollBar()->maximum());

    emit logReqSignal(ui->log_id->text().toInt());
}

void DroneWindow::on_set_takeoff_speed_clicked()
{
    ui->status->textCursor().insertText(QString("\nСкорость взлета установлена"));
    ui->status->verticalScrollBar()->setValue(ui->status->verticalScrollBar()->maximum());
    emit takeoffSpeedSignal(ui->takeoff_speed->text().toFloat());
}

void DroneWindow::on_set_land_speed_clicked()
{
    ui->status->textCursor().insertText(QString("\nСкорость посадки установлена"));
    ui->status->verticalScrollBar()->setValue(ui->status->verticalScrollBar()->maximum());
    emit landSpeedSignal(ui->land_speed->text().toFloat());

}

void DroneWindow::on_set_fly_speed_clicked()
{
    ui->status->textCursor().insertText(QString("\nСкорость полета установлена"));
    ui->status->verticalScrollBar()->setValue(ui->status->verticalScrollBar()->maximum());
    emit flySpeedSignal(ui->fly_speed->text().toFloat());
}

void DroneWindow::on_return_to_home_clicked()
{
    emit RTLSignal();
    ui->status->textCursor().insertText(QString("\nРежим возвращения домой"));
    ui->status->verticalScrollBar()->setValue(ui->status->verticalScrollBar()->maximum());
}

void DroneWindow::on_continue_mission_clicked()
{
     ui->status->textCursor().insertText(QString("\nПродолжение миссии"));
     ui->status->verticalScrollBar()->setValue(ui->status->verticalScrollBar()->maximum());
     emit AutoModeSignal();
}

void DroneWindow::on_Pause_clicked()
{
    ui->status->textCursor().insertText(QString("\nОстановка"));
    ui->status->verticalScrollBar()->setValue(ui->status->verticalScrollBar()->maximum());
    emit LoiterModeSignal();
}

void DroneWindow::on_takeoff_clicked()
{
    ui->status->textCursor().insertText(QString("\nОтправка тестового задания, высота ")+ui->takeoff_height->text() +QString(" м, Время зависания ") + ui->time_of_holdng->text()+QString(" секунды ") );
    ui->status->verticalScrollBar()->setValue(ui->status->verticalScrollBar()->maximum());
    emit takeoffMissionSignal(ui->takeoff_height->text().toFloat(), ui->time_of_holdng->text().toFloat());
}

void DroneWindow::on_Hold_time_clicked()
{
    emit LoiterTimeModeSignal(ui->time_of_holdng->text().toFloat());
    ui->status->textCursor().insertText(QString("\nОстановка"));
    ui->status->verticalScrollBar()->setValue(ui->status->verticalScrollBar()->maximum());

}
