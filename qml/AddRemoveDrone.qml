import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
Item{
    property int defterminalmargin: 15
    id: addrm
    Rectangle{
    id:rect
    anchors.fill: parent
    color: "#121324"
    Rectangle {
        id:insiderect
        anchors.fill: parent
        color: "#121324"
        anchors.rightMargin: parent.width /4.5
    ControlButton{
        id:add
        name: ""
        anchors.left: parent.left
        width: parent.width/2
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.leftMargin: 5
        anchors.topMargin: 10
        press: mousearea.containsPress
        Image {
            id: drone_icon
            source: "qrc:/images/add_plus.png"
            height: parent.height / 2
            width: height
            anchors.centerIn: parent
        }
        MouseArea {
           id: mousearea
           anchors.fill: parent
             onClicked: addDialog.open()
    }
    }
    ControlButton{
        name: ""
        anchors.left: add.right
        width: parent.width/2
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.leftMargin: 5
        anchors.topMargin: 10
        press: mousearea2.containsPress
        Image {
            id: drone_icon_rm
            source: "qrc:/images/rm_minus.png"
            height: parent.height / 2
            width: height
            anchors.centerIn: parent
        }


        MouseArea {
           id: mousearea2
           anchors.fill: parent
             onClicked: dialog.open()
    }
    }
    Dialog {
        id: dialog
        title: "Удалить дроны"
        width: addrm.width
        standardButtons: Dialog.Ok | Dialog.Cancel

         contentItem: Rectangle {
            id: backgr
            anchors.fill: parent
            color: "#121324"
            Rectangle{
                  id:txt
                    anchors.fill: parent
                    anchors.bottomMargin: parent.height/2
                    color: "#121324"
                    Text {
                        font.pointSize: 10
                        font.family: "Arial"
                        text: "Удалить выбранные дроны?"
                        anchors.centerIn: txt

                        color: "#d7d8da"}}
            Row {
                id: row
                anchors.top: txt.bottom
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
                        onClicked: dialog.close()
                    }
                    contentItem: Text {
                        font.pointSize: 10
                        font.family: "Arial"
                        text: "Отмена"
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
                       onClicked: dialog.close()}
                    contentItem: Text {
                        font.pointSize: 10
                        font.family: "Arial"
                        text: "Удалить"
                        anchors.centerIn: btnrec2

                        color: "#d7d8da"}
    }
            }
    }
}
    Dialog {
        width: 270
        height: 400
        title: "Добавить дрон"
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
        id: addDialog

        contentItem: Rectangle {
            id: back
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
                        id: ip
                        placeholderText: qsTr("Ip")
                        color: "gray"
                    }
                    TextField {
                        id: idnum
                        placeholderText: qsTr("id")
                        color: "gray"
                    }
//                    TextField {
//                        id: port
//                        placeholderText: qsTr("Порт")
//                        color: "gray"
//                    }
                }
            }

            Row {
                id: row2
                anchors.top: info.bottom
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.right: back.right
                anchors.bottomMargin: 5
                anchors.leftMargin: 5
                anchors.rightMargin: 5
                spacing: 5

                Button {
                    id: dialogButtonCancel2
                    // Растягиваем кнопку по высоте строки
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    width: row.width / 2
                    anchors.rightMargin: 2

                    background: Rectangle {
                        id: butnrec12
                        anchors.fill: parent
                        color: mouse1.containsPress ? "#71c3a8" : "#1e1f30"
                    }
                    MouseArea {
                        id: mouse1
                        anchors.fill: butnrec12
                        onClicked: addDialog.close()
                    }
                    contentItem: Text {
                        font.pointSize: 10
                        font.family: "Arial"
                        text: "Отмена"
                        anchors.centerIn: butnrec12

                        color: "#d7d8da"
                    }
                }
                Button {
                    id: dialogButtonSend1
                    // Растягиваем кнопку по высоте строки
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.leftMargin: 2

                    width: row.width / 2
                    background: Rectangle {
                        id: btnrec21
                        anchors.fill: parent
                        color: mouse21.containsPress ? "#71c3a8" : "#1e1f30"
                    }
                    MouseArea {
                        id: mouse21
                        anchors.fill: btnrec21
                        onClicked: {
                            addDialog.close()

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
                        text: "Добавить"
                        anchors.centerIn: btnrec21
                        color: "#d7d8da"
                    }
                }
            }
        }
    }

}
}
}
