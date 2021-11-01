import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls.Styles 1.4

Item {
    property int defcontrolmargin: 15
    property int defverticalmargin: parent.width / 7
    property int koeff_width: 2
    property int koeff_height: 5
    id: controlarea
    width: parent.width / koeff_width

    anchors.horizontalCenter: parent.horizontalCenter
    anchors.horizontalCenterOffset: -defcontrolmargin * 2

    GridLayout {
        id: grid
        columnSpacing: 5
        rowSpacing: 5
        anchors.fill: parent
        rows: 4
        columns: 5
        ControlButton {

            name: "Включить \n двигатели"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 2
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 1
            press: mousearea.containsPress

            MouseArea {
                id: mousearea
                anchors.fill: parent
                onClicked: commandSender.send_arm()
            }
        }
        ControlButton {
            name: "Добавить \n дрон"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 2
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 3
            press: mousearea1.containsPress
            MouseArea {
                id: mousearea1
                anchors.fill: parent
            }
        }
        ControlButton {
            name: "Сформировать \n миссию"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 1
            Layout.rowSpan: 2
            Layout.row: 1
            Layout.column: 5
            press: mousearea2.containsPress
            MouseArea {
                id: mousearea2
                anchors.fill: parent
            }
        }
        ControlButton {
            name: "Выключить \n двигатели"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 2
            Layout.rowSpan: 1
            Layout.row: 2
            Layout.column: 1
            press: mousearea3.containsPress
            MouseArea {
                id: mousearea3
                anchors.fill: parent
                onClicked: commandSender.send_disarm()
            }
        }

        ControlButton {
            name: "Загрузка \n тестовой \n миссии"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 2
            Layout.column: 3
            press: mousearea4.containsPress
            MouseArea {
                id: mousearea4
                anchors.fill: parent
            }
        }
        ControlButton {
            name: "Скачать \n логи"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 2
            Layout.column: 4
            press: mousearea5.containsPress
            MouseArea {
                id: mousearea5
                anchors.fill: parent
            }
        }
        ControlButton {
            name: "Остановка"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 3
            Layout.column: 1
            press: mousearea6.containsPress
            MouseArea {
                id: mousearea6
                anchors.fill: parent
                onClicked: commandSender.set_guided_mode()
            }
        }
        ControlButton {
            name: "Загрузить \n миссию \n сброса"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 2
            Layout.rowSpan: 1

            Layout.row: 3
            Layout.column: 4
            press: mousearea7.containsPress
            MouseArea {
                id: mousearea7
                anchors.fill: parent
            }
        }
        ControlButton {
            name: "Старт"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 5
            Layout.rowSpan: 1
            Layout.row: 4
            Layout.column: 1
            press: mousearea8.containsPress
            MouseArea {
                id: mousearea8
                anchors.fill: parent
                onClicked: commandSender.start_mission()
            }
        }
        ControlButton {
            name: "Возврат"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 3
            Layout.column: 2
            press: mousearea9.containsPress
            MouseArea {
                id: mousearea9
                anchors.fill: parent
                onClicked: commandSender.send_rtl_cmd()
            }
        }
        ControlButton {
            name: "Продолжить"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 3
            Layout.column: 3
            press: mousearea10.containsPress
            MouseArea {
                id: mousearea10
                anchors.fill: parent
                onClicked: commandSender.set_auto_mode()
            }
        }
        //        DropMissionComponent {
        //            Layout.fillHeight: true
        //            Layout.fillWidth: true
        //            Layout.columnSpan: 1
        //            Layout.rowSpan: 1
        //            Layout.column: 1
        //            Layout.row: 5
        //        }
    }
}
