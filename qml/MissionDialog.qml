import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4

Dialog {
    id: missionDialog
    property alias testDialog: missionDialog
    FileDialog {
        id: fds
        title: "Выбрать документ"
        folder: shortcuts.desktop
        selectExisting: true
        selectFolder: false
        selectMultiple: false
        nameFilters: ["Файл Миссии (*.waypoints)"]
        onAccepted: {
            commandSender.form_mission_from_file(fileUrl)
            console.log("Accepted: " + fileUrl)
        }
    }
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

            ColumnLayout {
                id: column1
                anchors.centerIn: parent
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.margins: 5
                Button {
                    id: filebutton

                    // Растягиваем кнопку по высоте строки
                    background: Rectangle {
                        id: filerect
                        anchors.fill: parent
                        color: mousefile.containsPress ? "#71c3a8" : "#1e1f30"
                    }
                    MouseArea {
                        id: mousefile
                        anchors.fill: filerect
                        onClicked: fds.open()
                    }
                    contentItem: Text {
                        font.pointSize: 10
                        font.family: "Arial"
                        text: "Открыть миссию"
                        anchors.centerIn: filerect

                        color: "#d7d8da"
                    }
                }
            }
        }

        Row {
            id: row
            anchors.top: info.bottom
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: backgr.right
            anchors.bottomMargin: 5
            anchors.leftMargin: 5
            anchors.rightMargin: 5
            spacing: 5

            Button {
                id: dialogButtonCancel
                // Растягиваем кнопку по высоте строки
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                width: row.width / 2
                anchors.rightMargin: 2

                background: Rectangle {
                    id: butnrec1
                    anchors.fill: parent
                    color: mouse.containsPress ? "#71c3a8" : "#1e1f30"
                }
                MouseArea {
                    id: mouse
                    anchors.fill: butnrec1
                    onClicked: missionDialog.close()
                }
                contentItem: Text {
                    font.pointSize: 10
                    font.family: "Arial"
                    text: "Выйти"
                    anchors.centerIn: butnrec1

                    color: "#d7d8da"
                }
            }
            Button {
                id: dialogButtonSend
                // Растягиваем кнопку по высоте строки
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.leftMargin: 2

                width: row.width / 2
                background: Rectangle {
                    id: btnrec2
                    anchors.fill: parent
                    color: mouse2.containsPress ? "#71c3a8" : "#1e1f30"
                }
                MouseArea {
                    id: mouse2
                    anchors.fill: btnrec2
                    onClicked: commandSender.upload_fly_mission()
                }
                contentItem: Text {
                    font.pointSize: 10
                    font.family: "Arial"
                    text: "Отправить дрону"
                    anchors.centerIn: btnrec2
                    color: "#d7d8da"
                }
            }
        }
    }
}
