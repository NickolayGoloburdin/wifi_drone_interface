import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import QtQuick 2.9

Item {
    id: terminalarea
    property int defterminalmargin
    property color terminalcolor
    width: parent.width / 4
    Rectangle {

        id: terminalrectangle
        visible: true
        anchors.fill: parent
        color: terminalcolor
        TabView {
            id: tabViewer
            anchors.fill: parent
            visible: true
            style: TabViewStyle {
                frameOverlap: 1
                tab: Rectangle {
                    color: styleData.selected ? terminalcolor : "#121324"
                    implicitWidth: Math.max(text.width + 4, 80)
                    implicitHeight: 50
                    radius: 2
                    border.color: terminalcolor
                    Text {
                        id: text
                        anchors.centerIn: parent
                        text: styleData.title
                        color: "white" //styleData.selected ? "white" : "black"
                    }
                }
            }
            Repeater {
                model: droneStore
                delegate: Tab {
                    title: model.uuid

                    TextArea {

                        anchors.fill: parent
                        font.pointSize: 10
                        font.family: "Arial"
                        text: model.status

                        style: TextAreaStyle {

                            textColor: "white"
                            selectionColor: "steelblue"
                            selectedTextColor: "#eee"
                            backgroundColor: terminalcolor
                        }
                    }
                }
            }
        }
    }
}
