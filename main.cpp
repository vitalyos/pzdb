#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "PZDBController.h"
#include "databasemodel.h"
#include "TableEntity.h"
#include "DataBaseQueryResultModel.hpp"

void registeTypes ();

int main(int argc, char *argv[])
{
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
