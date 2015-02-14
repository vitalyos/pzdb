#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "PZDBController.h"
#include "databasemodel.h"
#include "TableEntity.h"
#include "DataBaseQueryResultModel.hpp"

#include "mongo/client/dbclient.h"
#include "mongo/client/init.h"

void registeTypes ();

int main(int argc, char *argv[])
{
    mongo::Status status = mongo::client::initialize ();
    if (!status.isOK ()) {
        abort ();
    }
    QGuiApplication app(argc, argv);
    registeTypes();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

void registeTypes()
{
    qmlRegisterType<PZDBController>("edu.bbte.pzdb", 1, 0, "Controller");
    qmlRegisterType<DatabaseModel>("edu.bbte.pzdb", 1, 0, "DatabaseModel");
    qmlRegisterType<DataBaseQueryResultModel>("edu.bbte.pzdb", 1, 0, "DataBaseQueryResultModel");

    qRegisterMetaType<TableEntity>("TableEntity");
    qRegisterMetaType< QList<TableEntity> >("QList<TableEntity>");

    qRegisterMetaTypeStreamOperators<TableEntity>("TableEntity");
    qRegisterMetaTypeStreamOperators< QList<TableEntity> >("QList<TableEntity>");
}
