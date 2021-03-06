import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    id: appWindow
    visible: true
    height: 800
    width: 1400
    title: qsTr("Drone control center")
    color: "#121324"
    Terminalarea {
        defterminalmargin: 15
        terminalcolor: "#1e1f30"
        id: terminalarea
        anchors.bottom: parent.bottom
        anchors.bottomMargin: defterminalmargin
        anchors.right: parent.right
        anchors.rightMargin: defterminalmargin
        anchors.top: parent.top
        anchors.topMargin: defterminalmargin
    }
    Dronelist {
        id: dronearea
        anchors.right: controlarea.left
        anchors.rightMargin: 50
    }
    AddRemoveDrone {
        id:addrm
        anchors.right: dronearea.right
        anchors.top: dronearea.bottom
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15
        anchors.topMargin: 5
        anchors.left: dronearea.left
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
