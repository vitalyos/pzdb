import QtQuick 2.0

Item {
    id: tableListRoot;
    property alias content: tables.model;
    ListView {
        id: tables;
        height: tableListRoot.height;
        anchors.top: parent.tpo;
        anchors.left: parent.left;
        delegate: Component {
            id: tableDelegate;
            Item {
                id: tableWrapper;
                height: tname.height + fieldListView.height;
                Text {
                    id: tname;
                    text: model.modelData.tableName;
                    height: 25;
                }
                FieldListView {
                    id: fieldListView;
                    content: model.modelData.fields;
                    anchors.top: tname.bottom;
                    anchors.left: parent.left;
                    anchors.leftMargin: 25;

                    Component.onCompleted: {
                        console.log ("flv", tname.text, fieldListView.height)
                    }
                }
                Component.onCompleted: {
                    tableListRoot.height = (tname.height + fieldListView.height) * tables.count;
                    console.log("tabs", tname.text, tableListRoot.height);
                }
            }
        }
    }
}
