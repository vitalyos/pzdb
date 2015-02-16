import QtQuick 2.0

Item {
    id: dbstructure
    property alias content: databases.model;
    width: 200

    ListView {
        id: databases;
        anchors.fill: parent;
        delegate: Component {
            id: dbDelegate;
            Item {
                Text {
                    id: dbname;
                    text: name;
                    height: 25;
                }
                height: dbname.height + tableList.height;

                TableListView {
                    id: tableList;
                    content: tableModel;
                    anchors.top: dbname.bottom;
                    anchors.left: parent.left;
                    anchors.leftMargin: 25;
                }
            }
        }
    }
}

