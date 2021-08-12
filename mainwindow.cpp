#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer_id_ =  this->startTimer(10000);
    ui->status->textCursor().insertText(QString("\nИнтерфейс запущен"));


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
    ui->connection->setText("Подключение: не установлено");
    //ui->status->textCursor().insertText(QString("\nСоединение потеряно"));
}
void MainWindow::update_status(QString status){
    //ui->status->setText(ui->status->text() +QString("\n") + status );
    if (status == QString("Flight plan recieved")){ ui->status->textCursor().insertText(QString("\n") + "Полетный план получен" );}
    else{
    ui->status->textCursor().insertText(QString("\n") + status );
    }

}
void MainWindow::update_sattelites(int sattelites){
    ui->sattelites->setText("Спутников:" + QString::number(sattelites));
}
void MainWindow::update_battery(int8_t battery_charge){
ui->battery->setText("Заряд дрона:" + QString::number(battery_charge)+ QString("%"));
}
void MainWindow::update_coordinates(QString in_x, QString in_y){

ui->attitude->setText(in_x);
ui->longtitude->setText(in_y);
QMessageBox::warning(this, "Внимание", "Координаты точки для сброса обновлены, можно загружать полетное задание");
}

void MainWindow::on_Arm_clicked()
{
    ui->status->textCursor().insertText(QString("\nЗапуск..."));
    emit armSignal();
    //QMessageBox::warning(this,"Внимание", "Координаты точки для сброса обновлены, можно загружать полетное задание");
}

void MainWindow::on_Disarm_clicked()
{
    ui->status->textCursor().insertText(QString("\nВыключение двигателей..."));
    emit disarmSignal();

}

void MainWindow::on_SendPoint_clicked()
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
   emit missionSignal(x, y, x_land, y_land,height_takeoff, height_point, height_land,manual_drop,db_send);
}

void MainWindow::on_Start_clicked()
{
    ui->status->textCursor().insertText(QString("\nЗапуск миссии..."));
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
    ui->status->textCursor().insertText(QString("\nЗапрошен лист логов"));

    emit logListReqSignal();
}

void MainWindow::on_log_request_clicked()
{
    ui->status->textCursor().insertText(QString("\nЗапрос логов"));

    emit logReqSignal(ui->log_id->text().toInt());
}

void MainWindow::on_set_takeoff_speed_clicked()
{
    ui->status->textCursor().insertText(QString("\nСкорость взлета установлена"));
    emit takeoffSpeedSignal(ui->takeoff_speed->text().toFloat());
}

void MainWindow::on_set_land_speed_clicked()
{
    ui->status->textCursor().insertText(QString("\nСкорость посадки установлена"));

    emit landSpeedSignal(ui->land_speed->text().toFloat());

}

void MainWindow::on_set_fly_speed_clicked()
{
    ui->status->textCursor().insertText(QString("\nСкорость полета установлена"));

    emit flySpeedSignal(ui->fly_speed->text().toFloat());
}

void MainWindow::on_return_to_home_clicked()
{
    emit RTLSignal();
    ui->status->textCursor().insertText(QString("\nРежим возвращения домой"));
}

void MainWindow::on_continue_mission_clicked()
{
     ui->status->textCursor().insertText(QString("\nПродолжение миссии"));
    emit AutoModeSignal();
}

void MainWindow::on_Pause_clicked()
{
    ui->status->textCursor().insertText(QString("\nОстановка"));
   emit LoiterModeSignal();
}

void MainWindow::on_takeoff_clicked()
{
    ui->status->textCursor().insertText(QString("\nВзлет"));
    emit takeoffSignal(ui->takeoff_height->text().toFloat());
}

void MainWindow::on_Hold_time_clicked()
{
    emit LoiterTimeModeSignal(ui->time_of_holdng->text().toFloat());
    ui->status->textCursor().insertText(QString("\nОстановка"));
    emit AutoModeSignal();

}
