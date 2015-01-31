import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.2

import edu.bbte.pzdb 1.0

Window {
    id: root
    visible: true
    width: 1280
    height: 720

    signal loadDatabaseCatalog ();

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
                    height: dbname.height + 20 * tables.count
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
                        model: tableModel
                        Component.onCompleted: {
                            console.log(tables.count)
                        }
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

        TableView {
            id: table;
            model: qmodel;
        }
    }

    Controller {
        id: controller
    }

    Component.onCompleted: {
        root.loadDatabaseCatalog.connect(controller.loadDatabaseCatalog)

        //        controller.databaseCatalogLoaded.connect()

        root.loadDatabaseCatalog();
    }
}
