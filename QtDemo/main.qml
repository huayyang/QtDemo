import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.2

Window {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("DreamCraft Editor")

    Row {
        id: mainMenu
        x: 0
        width: 640
        height: 40

        Button {
            id:load
            text: "Load"
            focusPolicy: Qt.StrongFocus
            display: AbstractButton.TextBesideIcon
            checkable: true
            checked: false
            autoRepeat: false
            flat: false
            highlighted: false
            anchors.topMargin: 0
            onClicked: {
                sqlite.loadSqliteDB()
            }
        }

        Button {
            id:save
            text:"Save"
            anchors.topMargin: 0
            onClicked: {

            }
        }
    }
}
