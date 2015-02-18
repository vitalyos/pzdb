import QtQuick 2.0
import QtQuick.Controls 1.3;

Item {
    id: dbstructure;
    property alias content: databases.model;
    width: 350;
    height: 25 * databases.count;

    Item {
        id: createDbFieldComp;
        width: 350;
        height: 25;
        anchors.top: databases.bottom;
        anchors.left: parent.left;
        visible: false;
        TextField {
            id: edit;
            width: 250;
            height: 25;
            anchors.top: parent.top;
            anchors.left: parent.left;
        }
        Text {
            id: ok;
            height: 25;
            width: 50;
            text: "+";
            visible: edit.text != ""
            anchors.top: parent.top;
            anchors.left: edit.right;
            MouseArea {
                anchors.fill: parent;
                onClicked: {
                    root.createDb(edit.text);
                    resetDbView();
                }
            }
        }
        Text {
            id: cancel;
            height: 25;
            width: 50;
            text: "--";
            anchors.top: parent.top;
            anchors.right: parent.right;
            MouseArea {
                anchors.fill: parent;
                onClicked: resetDbView();
            }
        }
    }

    ListView {
        id: databases;
        anchors.top: parent.top;
        anchors.left: parent.left;
        height: parent.height;
        delegate: Component {
            id: dbDelegate;
            Item {
                id: dbWrapperItem;
                height: dbname.height;
                Text {
                    id: dbname;
                    text: name;
                    height: 25;
                    MouseArea {
                        id: dbElementClick;
                        anchors.fill: parent;
                        acceptedButtons: Qt.LeftButton | Qt.RightButton;
                        onClicked: {
                            if (mouse.button == Qt.LeftButton) {
                                changeFields();
                                tableList.content = tableModel;
                            }
                            if (mouse.button == Qt.RightButton) {
                                dbMenu.popup();
                            }
                        }
                    }

                    Menu {
                        id: dbMenu;
                        visible: true;
                        title: "dbs";
                        MenuItem {
                            id: createDb;
                            text: "createDb";
                            onTriggered: createDbView();
                        }
                        MenuItem {
                            id: dropDb;
                            text: "dropDb";
                            onTriggered: root.dropDb(dbname.text);
                        }
                    }
                }

            }
        }
    }

    Item {
        id: tables;
        visible: false;
        anchors.top: parent.top;
        anchors.left: parent.left;
        width: parent.width;
        height: parent.height;
        Text {
            id: backBtn;
            text: qsTr("<-");
            width: 35;
            height: parent.height;
            anchors.top: parent.top;
            anchors.left: parent.left;
            verticalAlignment: Text.AlignVCenter;
            horizontalAlignment: Text.AlignHCenter;

            MouseArea {
                id: backBtnClick;
                anchors.fill: parent;
                onClicked: {
                    changeFields();
                    tableList.content = null;
                }
            }
        }
        TableListView {
            id: tableList;
            anchors.top: parent.top;
            anchors.left: backBtn.right;
        }
    }

    function changeFields () {
        tables.visible = !tables.visible;
        databases.visible = !databases.visible;
    }

    function createDbView () {
        createDbFieldComp.visible = true;
    }

    function resetDbView () {
        createDbFieldComp.visible = false;
        createDbFieldComp.edit.text = "";
    }
}

