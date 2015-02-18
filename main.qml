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

    // drop
    signal dbDroped(var dbName);
    signal tableDroped(var tableName);

    // change
    signal currentDbChanged(var dbName);
    signal currentTableChanged (var tableName);

    //
    signal tableCreated (var name, var body);
    signal dbCreated(var dbName);

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
        root.dbDroped.connect(dbsModel.dropDatabase);
        root.dbCreated.connect(dbsModel.createDatabase);
        root.currentDbChanged.connect(dbsModel.changeCurrentDatabase);
        root.currentTableChanged.connect(dbsModel.changeCurrentTable);
        root.tableCreated.connect(dbsModel.createTable);
        root.tableDroped.connect(dbsModel.dropTable);
    }
}
