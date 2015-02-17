import QtQuick 2.0

Item {
    id: dbstructure;
    property alias content: databases.model;
    width: 200;

    ListView {
        id: databases;
        anchors.top: parent.top;
        anchors.left: parent.left;
        delegate: Component {
            id: dbDelegate;
            Item {
                id: dbWrapperItem;
                height: dbname.height + tableList.height;
                Text {
                    id: dbname;
                    text: name;
                    height: 25;
                }

                TableListView {
                    id: tableList;
                    content: tableModel;
                    anchors.top: dbname.bottom;
                    anchors.left: parent.left;
                    anchors.leftMargin: 25;
                }

                Component.onCompleted: {
                    databases.height = (dbname.height + tableList.height) * databases.count;
                    console.log("dbs:", dbname.text, databases.height)
                }
            }
        }
    }
}

