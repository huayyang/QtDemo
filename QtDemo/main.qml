import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 1.4
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
                sqlModel.updateModel()
            }
        }

        Button {
            id:close
            text:"Close"
            anchors.topMargin: 0
            onClicked: {
                sqlite.closeSqliteDB()
            }
        }
    }

    TableView {
        id: tableView
        y: 73
        height: 172
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0

        TableViewColumn {
            role: "id"
            title: "unit id"
        }

        TableViewColumn {
            role: "default_name"
            title: "unit name"
        }

        TableViewColumn {
            role: "unity_prefab_path"
            title: "prefab"
        }

        model: sqlModel
    }
}
