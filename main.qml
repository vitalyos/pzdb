import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.2

import edu.bbte.pzdb 1.0

Window {
    id: root;
    visible: true;
    width: 1280;
    height: 720;

    signal loadDatabaseCatalog ();
    signal deleteKey (var key);
    signal insert(var data);

    Item {
        id: dbstructure
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        width: 200

        ListView {
            id: databases
            anchors.fill: parent
            delegate: Component {
                id: dbDelegate
                Item {
                    Text {
                        id: dbname
                        text: name
                    }
                    height: dbname.height + 25 * tables.count
                    ListView {
                        id: tables
                        anchors.top: dbname.bottom

                        delegate: Component {
                            id: tableDelegate
                            Item {
                                Text {
                                    id: tableName
                                    text: modelData
                                }
                                height: 40
                            }
                        }
                        model: tableModel;
                    }
                }
            }
            model: DatabaseModel {
                id: dbModel
            }
        }
    }

    Item {
        id: contentManager
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: dbstructure.right
        anchors.right: parent.right

        DataBaseQueryResultModel {
            id: qmodel;
        }

        Item {
            id: insertZone;
            anchors.bottom: parent.bottom;
            anchors.left: parent.left;
            anchors.right: parent.right;
            height: 50;
            Row  {
                id: editors;
                anchors.left: parent.left;
                anchors.right: addRow.left;
                anchors.top: parent.top;
                anchors.bottom: parent.bottom;

                Component.onCompleted: createFields(qmodel.header.length - 1, editors, editArea);
            }
            Text {
                id: addRow;
                text: qsTr("+");
                anchors.right: parent.right;
                width: 50;
                anchors.top: parent.top;
                anchors.bottom: parent.bottom;
                horizontalAlignment: Text.AlignHCenter;
                verticalAlignment: Text.AlignVCenter;

                MouseArea {
                    anchors.fill: parent;
                    onClicked: {
                        root.insert(collectFieldData(editors));
                    }
                }
            }
            Component {
                id: editArea;
                TextField {
                    id: edit;
                    height: 50;
                }
            }
        }

        TableView {
            id: table;
            model: qmodel;
            anchors.top: parent.top;
            anchors.left: parent.left;
            anchors.bottom: insertZone.top;
            anchors.right: parent.right;
            resources: updateTableHeader();
        }

        Component {
            id: tableHeaderElement;
            TableViewColumn {
                resizable: true;
            }
        }

        Component{
            id: deleteHeader;
            TableViewColumn {
                width: 50;
                title: "DEL";
                role: "dbkey";
                delegate: Component {
                    id: delRoot;
                    Item {
                        id: delWrapper;
                        Text {
                            id: delText;
                            text: qsTr("X");
                        }
                        MouseArea {
                            anchors.fill: parent;
                            onReleased: {
                                root.deleteKey (styleData.value);
                            }
                        }
                    }
                }
            }
        }

    }

    Controller {
        id: controller
    }

    Component.onCompleted: createConnections();

    function collectFieldData (source) {
        var data = [];
        for (var i = 0; i < source.children.length; ++i) {
            data.push(source.children[i].text);
        }
        return data;
    }

    function createFields (count, where, field) {
        var limit = where.children.length;
        for (var i = 0; i < limit; ++i) {
            where.children[i].destroy();
        }
        var lengths = qmodel.lens;
        console.log(lengths)
        for (i = 0; i < count; ++i) {
            field.createObject(where, {
                                   "width": tableHeaderSize(count + 1),
                                   "maximumLength": parseInt(lengths[i])
                               });
        }
    }

    function updateTableHeader() {
        var roleList = qmodel.header;
        var temp = [];
        for(var i = 0; i < roleList.length - 1; ++i) {
            var role  = roleList[i];
            temp.push(tableHeaderElement.createObject (table, createHeaderElement(role, roleList.length)));
        }
        temp.push(deleteHeader.createObject(table,{}));
        return temp
    }

    function tableHeaderSize (size) {
        return (root.width - dbstructure.width - 70) / (size - 1);
    }

    function createHeaderElement (elementName, size) {
        return {
            "role": elementName,
            "title": elementName,
            "width": tableHeaderSize(size)
        }
    }

    function createConnections () {
        // delete a row from table
        root.deleteKey.connect(controller.deleteRowByKey);
        controller.deleteRow.connect(qmodel.deleteRow);

        // database catalog
        root.loadDatabaseCatalog.connect(controller.loadDatabaseCatalog);
        root.loadDatabaseCatalog();

        // insert row
        root.insert.connect(controller.insertRow);
        controller.rowInserted.connect(qmodel.addDataRow);
    }
}
