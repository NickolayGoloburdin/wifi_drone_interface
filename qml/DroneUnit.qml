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
    signal commandAck(int id, bool res)
    property color buttoncolor: "#1e1f30"
    property color animcolor: "red"
    property bool active: false
    anchors.left: parent.left
    anchors.right: parent.right
    height: 100

    Rectangle {
        id: rect
        anchors.left: rectangle.right
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        width: parent.width / 1.5
        color: buttoncolor
        anchors.margins: 5
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
        text: "id : " + uuid
        anchors.centerIn: rect
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
    //        text: "Соединение : " + heartbeat.toString()
    //        anchors.left: rect.left
    //        anchors.bottom: rect.bottom
    //        color: "white"
    //    }
    Text {
        font.pointSize: 7
        font.family: "Arial"
        text: "Напряжение : " + voltage.toString()
        anchors.left: rect.left
        anchors.top: rect.top
        color: "white"
    }

    Rectangle {
        id: rectangle
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        width: parent.width / 6
        height: parent.height
        color: heartbeat ? "#71c3a8" : "gray"
        anchors.margins: 5
    }
    Rectangle {
        id: rectack
        anchors.left: rect.right
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        width: parent.width / 6
        height: parent.height
        color: heartbeat ? "#71c3a8" : "gray"
        anchors.margins: 5
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
