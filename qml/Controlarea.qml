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
            name: "arm"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 2
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 1
        }
        ControlButton {
            name: "Add drone"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 2
            Layout.rowSpan: 1
            Layout.row: 1
            Layout.column: 3
        }
        ControlButton {
            name: "Upload Fly mission"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 1
            Layout.rowSpan: 2
            Layout.row: 1
            Layout.column: 5
        }
        ControlButton {
            name: "disarm"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 2
            Layout.rowSpan: 1
            Layout.row: 2
            Layout.column: 1
        }

        ControlButton {
            name: "test fly mission"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 2
            Layout.column: 3
        }
        ControlButton {
            name: "Download logs"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 2
            Layout.column: 4
        }
        ControlButton {
            name: "Stop flight"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 3
            Layout.column: 1
        }
        ControlButton {
            name: "Upload Drop mission"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 2
            Layout.rowSpan: 1

            Layout.row: 3
            Layout.column: 4
        }
        ControlButton {
            name: "Start"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 5
            Layout.rowSpan: 1
            Layout.row: 4
            Layout.column: 1
        }
        ControlButton {
            name: "Return"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 3
            Layout.column: 2
        }
        ControlButton {
            name: "Continue"
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.row: 3
            Layout.column: 3
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
