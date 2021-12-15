import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4

Dialog {

    id: syncDialog
    property alias testDialog: syncDialog
    contentItem: Rectangle {
        id: backgr
        anchors.fill: parent
        color: "#121324"

        Rectangle {
            id: info
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            height: parent.height / 1.5
            color: "#121324"

            ListView {
                id: listview1
                anchors.left: info.left
                anchors.top: info.top
                anchors.topMargin: 10
                anchors.bottom: info.bottom
                width: info.width / 3
                spacing: 5

                model: droneStore
                delegate: Rectangle {
                    id: bc

                    width: listview1.width
                    anchors.margins: 10

                    height: 40
                    property bool press: false
                    color: press ? "#71c3a8" : "#1e1f30"
                    Text {
                        font.pointSize: 10
                        font.family: "Arial"
                        text: "Дрон: " + uuid.toString()
                        anchors.verticalCenter: bc.verticalCenter
                        anchors.left: bc.left
                        anchors.leftMargin: 10
                        color: "white"
                    }

                    MouseArea {
                        id: mousarea
                        property bool active: false
                        anchors.fill: bc
                        onClicked: {
                            if (press === false) {
                                press = true
                                commandSender.add_drone_to_sync(uuid)
                            } else {

                                press = false
                                commandSender.remove_drone_from_sync(uuid)
                            }
                        }
                    }
                }
            }
            Rectangle {
                id: txt
                anchors.left: listview1.right
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.leftMargin: 10
                anchors.bottom: parent.bottom
                color: "#121324"
                Text {
                    font.pointSize: 12
                    font.family: "Arial"
                    text: "   Выберите дроны\n\tдля\nсинхронизации полета"
                    anchors.verticalCenter: txt.verticalCenter
                    anchors.left: txt.left
                    color: "#676767"
                }
            }
        }

        Button {
            id: dialogButtonCancel

            // Растягиваем кнопку по высоте строки
            anchors.top: info.bottom
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: backgr.right
            anchors.bottomMargin: 5
            anchors.leftMargin: 5
            anchors.rightMargin: 5
            spacing: 5

            background: Rectangle {
                id: butnrec1
                anchors.fill: parent
                color: mouse.containsPress ? "#71c3a8" : "#1e1f30"
            }
            MouseArea {
                id: mouse
                anchors.fill: butnrec1
                onClicked: syncDialog.close()
            }
            contentItem: Text {
                font.pointSize: 10
                font.family: "Arial"
                text: "Принять"
                anchors.centerIn: butnrec1

                color: "#d7d8da"
            }
        }
    }
}
