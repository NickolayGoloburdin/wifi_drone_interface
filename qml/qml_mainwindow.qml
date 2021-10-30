import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls.Styles 1.4

Window {
    id: appWindow
    visible: true
    height: 800
    width: 1200
    title: qsTr("MyApp")
    color: "#121324"
    Item {
        id: terminalarea
        property int defterminalmargin: 15
        property color terminalcolor: "#1e1f30"
        width: parent.width / 4
        anchors.top: parent.top
        anchors.topMargin: defterminalmargin
        anchors.bottomMargin: defterminalmargin
        anchors.rightMargin: defterminalmargin
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        Rectangle {

            id: terminalrectangle
            visible: true
            anchors.fill: parent
            color: parent.terminalcolor
        }
    }
    Dronelist {
        id: dronearea
        width: 240
        height: 229
    }
    Controlarea {
        id: controlarea
        property int defcontrolmargin: 30
        anchors.right: terminalarea.left
        anchors.rightMargin: defcontrolmargin
    }
}
