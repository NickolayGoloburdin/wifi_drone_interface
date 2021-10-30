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
    width: parent.width / koeff_width
    anchors.top: parent.top
    anchors.bottom: parent.bottom
    anchors.left: parent.left
    anchors.bottomMargin: defterminalmargin
    anchors.leftMargin: defterminalmargin
    ListView {
        anchors.fill: parent
        Item {
            anchors.fill: parent
        }
    }
}
