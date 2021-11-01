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

    property color buttoncolor: "#1e1f30"
    property bool active: false
    anchors.left: parent.left
    anchors.right: parent.right
    height: 100

    Rectangle {
        id: rect
        anchors.fill: parent
        anchors.margins: 5
        color: buttoncolor
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
    Text {
        font.pointSize: 7
        font.family: "Arial"
        text: "Соединение : " + heartbeat.toString()
        anchors.left: rect.left
        anchors.bottom: rect.bottom
        color: "white"
    }
    Text {
        font.pointSize: 7
        font.family: "Arial"
        text: "Напряжение : " + voltage.toString()
        anchors.left: rect.left
        anchors.top: rect.top
        color: "white"
    }
}
