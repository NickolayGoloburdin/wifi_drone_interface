#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPushButton>

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
signals:
    void armSignal();
    void disarmSignal();
    void missionSignal(int x, int y, int x_land, int y_land,float height_takeoff, float height_point, float height_land);
    void startSignal();
protected:
    void timerEvent(QTimerEvent *event) override;
    int timer_id_;
private slots:
    void on_SendPoint_clicked();

    void on_Start_clicked();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
