import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 1.2

Item {
    id: contentManager;
    property alias tableContent: table.model;
    property int wsize: 0;
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
        onRowCountChanged: createFields(qmodel.header.length - 1, editors, editArea);
        onColumnCountChanged: createFields(qmodel.header.length - 1, editors, editArea);
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
        return (contentManager.wsize - 70) / (size - 1);
    }

    function createHeaderElement (elementName, size) {
        return {
            "role": elementName,
            "title": elementName,
            "width": tableHeaderSize(size)
        }
    }

}

