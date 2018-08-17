import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 1.4
import QtQuick.Controls 2.2

Window {
    id: mainWindow
    visible: true
    width: 1024
    height: 768
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
                unitModel.updateModel()
                abilityModel.updateModel();
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
        height: 77
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

    Pane {
        id: pane
        x: 0
        y: 189
        width: 640
        height: 192

        ComboBox {
            id: comboBox
            x: 0
            y: 21
            width: 122
            height: 27
            model:unitModel
        }

        ComboBox {
            id: comboBox1
            x: 132
            y: 86
            width: 130
            height: 28
            model:abilityModel
        }

        Button {
            id: button
            x: 329
            y: 86
            width: 81
            height: 28
            text: qsTr("Save")
            onClicked:{
                updateUnitAbilityHandler.updateUnitAbility(comboBox.currentText, comboBox1.currentText)
            }
        }

        Text {
            id: text1
            x: 0
            y: 54
            text: qsTr("Name")
            font.pixelSize: 12
        }

        TextInput {
            id: textInput
            x: 0
            y: 89
            width: 80
            height: 20
            text: qsTr("Text Input")
            font.pixelSize: 12
        }

        Text {
            id: text2
            x: 132
            y: 54
            width: 25
            height: 10
            text: qsTr("Ability")
            font.pixelSize: 12
        }

        Text {
            id: text3
            text: qsTr("Unit")
            font.pixelSize: 12
        }
    }
}
