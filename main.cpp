#include "PZDBMainWindow.h"
#include <QApplication>
#include <QMetaType>

#include "BaseCatalogEntity.h"
#include "DataBaseEntity.h"
#include "TableEntity.h"
#include "FieldEntity.h"

#include "MongoService.h"
#include "PZDBController.h"
#include "DataBaseStructureModel.h"
#include "DataBaseCatalogSerializer.h"
#include "MongoService.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType<BaseCatalogEntity>("BaseCatalogEntity");
    qRegisterMetaType<DataBaseEntity>("DataBaseEntity");
    qRegisterMetaType<TableEntity>("TableEntity");
    qRegisterMetaType<FieldEntity>("FieldEntity");

    qRegisterMetaTypeStreamOperators<BaseCatalogEntity>("BaseCatalogEntity");
    qRegisterMetaTypeStreamOperators<DataBaseEntity>("DataBaseEntity");
    qRegisterMetaTypeStreamOperators<TableEntity>("TableEntity");
    qRegisterMetaTypeStreamOperators<FieldEntity>("FieldEntity");

    QApplication a(argc, argv);

    MongoService * service = new MongoService;
    PZDBController * controller = new PZDBController (service);
    DataBaseCatalogSerializer * serizalizer = new DataBaseCatalogSerializer("catalog.ini");
    DataBaseStructureModel * model = new DataBaseStructureModel(serizalizer);
    PZDBMainWindow * w = new PZDBMainWindow(model);
    w->show();

    QObject::connect(w, &PZDBMainWindow::closeApplication, &a, QApplication::exit);
    return a.exec();
}
