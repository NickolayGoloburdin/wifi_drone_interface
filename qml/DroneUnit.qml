import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls.Styles 1.4

Item {
    property var uuid
    property var ip
    property var heartbeat
    property var sattelites
    property var voltage
    property var tcp_link
    signal commandAck(int id, bool res)
    property color buttoncolor: "#1e1f30"
    property color animcolor: "red"
    property bool active: false
    property bool visible_param: false
    anchors.left: parent.left
    anchors.right: parent.right
    height: 100
    Rectangle {
        id: param_list
        visible: visible_param
        height: rectack.height
        anchors.left: rectack.right
        color: "#1e1f30"
        anchors.top: rectack.top
        width: parent.width / 3.5
        z: 1
        GridLayout {
            id: param_grid
            columnSpacing: 5
            rowSpacing: 5
            anchors.fill: parent
            anchors.leftMargin: 5
            rows: 2
            columns: 2
            Text {

                Layout.columnSpan: 1
                Layout.rowSpan: 1
                Layout.row: 1
                Layout.column: 1
                font.pointSize: 6
                font.family: "Arial"
                Layout.alignment: Qt.AlignHCenter
                text: voltage.toString() + "%"
                color: "white"
            }
            Text {

                Layout.columnSpan: 1
                Layout.rowSpan: 1
                Layout.row: 1
                Layout.alignment: Qt.AlignHCenter
                Layout.column: 2
                font.pointSize: 6
                font.family: "Arial"
                text: sattelites.toString() + "sat"
                color: "white"
            }
            Text {

                Layout.columnSpan: 1
                Layout.rowSpan: 1
                Layout.row: 2
                Layout.alignment: Qt.AlignHCenter
                Layout.column: 1
                font.pointSize: 6
                font.family: "Arial"
                text: "Arm"
                color: "white"
            }
            Text {

                Layout.columnSpan: 1
                Layout.rowSpan: 1
                Layout.row: 2
                Layout.alignment: Qt.AlignHCenter
                Layout.column: 2
                font.pointSize: 6
                font.family: "Arial"
                text: "Heartbeat"
                color: heartbeat ? "green" : "red"
            }
        }
    }
    Rectangle {
        id: rect
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        width: parent.width / 1.5
        color: buttoncolor
        anchors.margins: 5
        Image {
            id: drone_icon
            source: "qrc:/images/drone.png"
            height: parent.height / 2
            width: height
            anchors.left: parent.left
            anchors.leftMargin: parent.width / 10
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    MouseArea {
        id: mousarea
        property bool active: false
        anchors.fill: rect
        onClicked: {
            if (active === false) {
                active = true
                buttoncolor = "#71c3a8"
                communicator.addLinkToChosen(uuid)
            } else {
                active = false
                buttoncolor = "#1e1f30"
                communicator.removeLinkFromChosen(uuid)
            }
        }
    }
    Text {
        font.pointSize: 10
        font.family: "Arial"
        text: "???????? : " + uuid
        anchors.verticalCenter: rect.verticalCenter
        anchors.right: rect.right
        anchors.rightMargin: rect.width / 4
        color: "white"
    }
    Text {
        font.pointSize: 7
        font.family: "Arial"
        text: ip
        anchors.right: rect.right
        anchors.bottom: rect.bottom
        color: "white"
    }

    //    Text {
    //        font.pointSize: 7
    //        font.family: "Arial"
    //        text: "???????????????????? : " + heartbeat.toString()
    //        anchors.left: rect.left
    //        anchors.bottom: rect.bottom
    //        color: "white"
    //    }
    //    Text {
    //        font.pointSize: 7
    //        font.family: "Arial"
    //        text: "???????????????????? : " + voltage.toString()
    //        anchors.left: rect.left
    //        anchors.top: rect.top
    //        color: "white"
    //    }
    Rectangle {
        id: rectangle
        anchors.left: rectack.right
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        width: parent.width / 4
        height: parent.height
        color: "#121324"
        anchors.margins: 5
        ColumnLayout {
            id: unitgrid
            anchors.horizontalCenter: parent.Center
            anchors.top: parent.top
            anchors.bottom: parent.bottom

            //anchors.topMargin: rectangle.height / 4
            Rectangle {
                width: rectangle.height / 5
                height: rectangle.height / 5

                color: tcp_link ? "#71c3a8" : "#ab2424"
                border.color: "#1e1f30"
                border.width: 2
                radius: width * 0.5
            }
            Rectangle {
                width: rectangle.height / 5
                height: rectangle.height / 5
                color: "#121324"
                border.color: "#1e1f30"
                border.width: 2
                radius: width * 0.5
            }
        }
    }
    Rectangle {
        id: rectack
        anchors.left: rect.right
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        width: parent.width / 8
        height: parent.height
        color: ma.containsPress ? "#71c3a8" : "#1e1f30"
        anchors.margins: 5
        MouseArea {
            id: ma
            anchors.fill: rectack
            onClicked: {
                if (visible_param === false) {
                    visible_param = true
                } else {
                    visible_param = false
                }
            }
        }
        Image {
            id: icon
            source: "qrc:/images/info.png"
            height: parent.height / 5
            width: height
            anchors.centerIn: parent
        }
    }
    Connections {
        target: AckHandler
        onCommandSignal: if (id === uuid) {

                             if (res === false) {
                                 animcolor = "red"
                                 seqAni.start()
                             } else {
                                 animcolor = "#71c3a8"
                                 seqAni.start()
                             }
                         }
    }
    SequentialAnimation {

        id: seqAni

        ColorAnimation {
            target: rectack
            from: "gray"
            to: animcolor
            duration: 1000
        }

        ColorAnimation {
            target: rectack
            from: animcolor
            to: "gray"
            duration: 1000
        }
    }
}
