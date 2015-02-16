import QtQuick 2.0

Item {
    id: root;
    property alias content: tables.model;
    height: tables.height;
    ListView {
        id: tables;
        height: (content.length + 1) * 25
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
                }
            }
        }
    }
}

