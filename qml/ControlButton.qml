import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls.Styles 1.4

Item {
    id: root
    property string name: "Button"
    property int k_width: 3
    property int k_height: 1
    property bool press: false
    property color buttonlcolor: press ? "#71c3a8" : "#1e1f30"

    Button {

        visible: true
        anchors.fill: parent
        background: Rectangle {
            id: back
            anchors.fill: parent
            visible: true
            color: buttonlcolor
            //Qt.darker(buttonlcolor,1.2) : buttonlcolor
        }

        contentItem: Text {
            font.pointSize: 10
            font.family: "Arial"
            text: name
            anchors.centerIn: back
            color: "#d7d8da"
        }
    }
}
