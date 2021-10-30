import QtQuick 2.0
import QtQuick.Window 2.0

Window {
    id: appWindow
    visible: true
    height: 600
    width: 800
    title: qsTr("MyApp")
    signal sendSignal

    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.rightMargin: 83
        anchors.fill: parent

        Rectangle {
            id: rectangle1
            y: 142
            width: rectangle.width/2
            height: 200
            color: "#ff5500"
            anchors.left: parent.left
            anchors.leftMargin: 30
        }
    }
}
