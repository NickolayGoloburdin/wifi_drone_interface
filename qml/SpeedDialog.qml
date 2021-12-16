import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4

Dialog {
    function parsetext(text) {
        if (text.lenght === 0 || !text.trim()) {
            return 0
        } else {
            var v = parseInt(text)
            if (isNaN(v)) {
                return -1
            }
            if (v < 50)
                return -1
            else
                return v
        }
    }
    id: testDialog
    property alias testDialog: testDialog
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
                TextField {
                    id: hspeed
                    placeholderText: qsTr("Горизонтальная ск, см/с")
                    color: "gray"
                }
                TextField {
                    id: upspeed
                    placeholderText: qsTr("Скорость взлета, см/с")
                    color: "gray"
                }
                TextField {
                    id: dwnspeed
                    placeholderText: qsTr("Скорость посадки, см/с")
                    color: "gray"
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
                    onClicked: testDialog.close()
                }
                contentItem: Text {
                    font.pointSize: 10
                    font.family: "Arial"
                    text: "Cancel"
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
                    onClicked: {
                        if (parsetext(hspeed.text) === -1 || parsetext(
                                    upspeed.text) === -1 || parsetext(
                                    dwnspeed.text) === -1) {

                            dialogerror.open()
                            hspeed.text = ""
                            upspeed.text = ""
                            dwnspeed.text = ""
                        } else {
                            if (parsetext(hspeed.text) !== 0) {
                                commandSender.set_fly_speed(parsetext(
                                                                hspeed.text))
                            }
                            if (parsetext(upspeed.text) !== 0) {
                                commandSender.set_takeoff_speed(
                                            parsetext(upspeed.text))
                            }
                            if (parsetext(dwnspeed.text) !== 0) {
                                commandSender.set_land_speed(parsetext(
                                                                 dwnspeed.text))
                            }
                        }
                    }
                    Dialog {
                        id: dialogerror
                        title: "Скорость не может быть менее 50 см/с"
                        standardButtons: Dialog.Ok
                    }
                }
                contentItem: Text {
                    font.pointSize: 10
                    font.family: "Arial"
                    text: "Загрузить параметры"
                    anchors.centerIn: btnrec2
                    color: "#d7d8da"
                }
            }
        }
    }
}
