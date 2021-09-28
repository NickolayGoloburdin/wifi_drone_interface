#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPushButton>
#include <QMessageBox>
#include "mavlink_communicator.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void on_Arm_clicked();
    void on_Disarm_clicked();
    void update_connection();
    void update_status(QString status);
    void update_sattelites(int sattelites);
    void update_battery(int8_t battery_charge);
    void update_log_list(mavlink_log_entry_t log_entry);
    void update_coordinates(QString in_x, QString in_y);
    void on_Start_clicked();
signals:
    void armSignal();
    void disarmSignal();
    void missionSignal(int x, int y, int x_land, int y_land,float height_takeoff, float height_point, float height_land, bool drop, bool send_db);
    void startSignal();
    void takeoffMissionSignal(float meters, float time);
    void logListReqSignal();
    void logReqSignal(int number);
    void takeoffSpeedSignal(float speed);
    void landSpeedSignal(float speed);
    void flySpeedSignal(float speed);
    void RTLSignal();
    void AutoModeSignal();
    void LoiterModeSignal();
    void LoiterTimeModeSignal(float seconds);
protected:
    void timerEvent(QTimerEvent *event) override;
    int timer_id_;
private slots:
    void on_SendPoint_clicked();





    void on_log_list_request_clicked();

    void on_log_request_clicked();

    void on_set_takeoff_speed_clicked();

    void on_set_land_speed_clicked();

    void on_set_fly_speed_clicked();

    void on_return_to_home_clicked();

    void on_continue_mission_clicked();

    void on_Pause_clicked();

    void on_takeoff_clicked();

    void on_Hold_time_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
