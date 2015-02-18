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

    signal dropDb(var dbName);
    signal createDb(var dbName);
    signal currentDbChanged(var dbName);
    signal currentTableChanged (var tableName);


    DatabaseModel {
        id: dbsModel;
    }

    Controller {
        id: controller
    }

    DataBaseQueryResultModel {
        id: qmodel;
    }

    DataBaseStructure {
        id: databaseTree;
        content: dbsModel;
        anchors.top: parent.top;
        anchors.left: parent.left;
    }

    CustomTableView {
        id: tableContent;
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: databaseTree.right
        anchors.right: parent.right
        wsize: root.width - databaseTree.width;
    }

    Component.onCompleted: createConnections();

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

        // intermodel communication
        dbsModel.currentTableChanged.connect(qmodel.changeCurrentTable);
        dbsModel.currentDbChanged.connect(qmodel.changeCurrentDb);

        // db structure communication
        root.dropDb.connect(dbsModel.dropDatabase);
        root.createDb.connect(dbsModel.createDatabase);
        root.currentDbChanged.connect(dbsModel.changeCurrentDatabase);
        root.currentTableChanged.connect(dbsModel.changeCurrentTable);
    }
}
