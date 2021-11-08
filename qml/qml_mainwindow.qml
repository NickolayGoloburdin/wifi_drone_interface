import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
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
        anchors.right: controlarea.left
        anchors.rightMargin: 50
    }
    Controlarea {
        id: controlarea
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        anchors.bottomMargin: parent.height / 5
        anchors.topMargin: parent.height / 5
        property int defcontrolmargin: 30
        anchors.right: terminalarea.left
        anchors.rightMargin: defcontrolmargin
    }
    onClosing: {
        //console.log("Model=" + App.stringifyModel());
        console.log("Exiting application... Persisting model to file setting.json")
        App.persistDrones()
        close.accepted = true
    }
}
