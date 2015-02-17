import QtQuick 2.0

Item {
    id: dbstructure;
    property alias content: databases.model;
    width: 200;
    height: 25 * databases.count;

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
                        onClicked: {
                            changeFields();
                            tableList.content = tableModel;
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
            width: 50;
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
}

