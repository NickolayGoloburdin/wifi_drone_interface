import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls.Styles 1.4
import QSyncable 1.0

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
        model: droneStore
        delegate: DroneUnit {
            uuid: model.uuid
            ip: model.ip
            heartbeat: model.heartbeat
            sattelites: model.sattelites
            voltage: model.voltage
        }
    }
}
