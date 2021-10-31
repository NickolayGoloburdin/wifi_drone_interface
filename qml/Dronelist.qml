import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls.Styles 1.4

Item {
    property int defterminalmargin: 15
    property int koeff_width: 5
    property int koeff_height: 5
    id: dronearea

    anchors.top: parent.top
    anchors.bottom: parent.bottom
    anchors.left: parent.left
    anchors.topMargin: parent.height / 12
    anchors.bottomMargin: defterminalmargin
    anchors.leftMargin: defterminalmargin
    ListView {
        id: listview1
        anchors.fill: parent
        model: ["Drone id:1", "Drone id:2", "Drone id:3", "Drone id:1", "Drone id:2", "Drone id:3"]
        delegate: Item {
            id: item
            property color buttoncolor: "#1e1f30"
            property bool active: false
            anchors.left: parent.left
            anchors.right: parent.right
            height: 100
            Button {

                anchors.fill: parent
                anchors.margins: 5
                background: Rectangle {
                    id: rect
                    anchors.fill: parent
                    color: buttoncolor
                }

                MouseArea {
                    id: mousarea
                    property bool active: false
                    anchors.fill: parent
                    onClicked: {
                        if (active === false) {
                            active = true
                            buttoncolor = "#71c3a8"
                        } else {
                            active = false
                            buttoncolor = "#1e1f30"
                        }
                    }
                }

                contentItem: Text {
                    font.pointSize: 10
                    font.family: "Arial"
                    text: modelData
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    color: "white"
                }
            }
        }
    }
}
