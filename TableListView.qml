import QtQuick 2.0

Item {
    id: tableListRoot;
    property alias content: tables.model;
    width: parent.width;
    height: 25 * tables.count;

    ListView {
        id: tables;
        height: tableListRoot.height;
        anchors.top: parent.tpo;
        anchors.left: parent.left;
        delegate: Component {
            id: tableDelegate;
            Item {
                id: tableWrapper;
                height: tname.height;
                Text {
                    id: tname;
                    text: model.modelData.tableName;
                    height: 25;

                    MouseArea {
                        id: tableClick;
                        anchors.fill: parent;
                        onClicked: {
                            changeFields();
                            fieldListView.content = model.modelData.fields;
                        }
                    }
                }
            }
        }
    }

    Item {
        id: fields;
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
                    fieldListView.content = null;
                }
            }
        }
        FieldListView {
            id: fieldListView;
            anchors.top: parent.top;
            anchors.left: backBtn.right;
        }
    }

    function changeFields () {
        fields.visible = !fields.visible;
        tables.visible = !tables.visible;
    }
}
