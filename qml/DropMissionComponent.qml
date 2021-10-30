import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls.Styles 1.4

Item {
    visible: true
    anchors.fill: parent
    property string name: "Drop Mission"
    Rectangle {
        anchors.fill: parent
        visible: true
        color: "#1e1f30"
    }
    Text {
        text: name
        fontSizeMode: Text.Fit
        font.pointSize: 10
        font.family: "Arial"
        anchors.left: parent.left
        color: "#d7d8da"
    }
}
