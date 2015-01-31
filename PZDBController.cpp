#include <QDebug>

#include "PZDBController.h"
#include "MongoService.h"

PZDBController::PZDBController(QObject *parentObject)
    : QObject(parentObject)
{
    qDebug () << "PZDBController created";
}

PZDBController::~PZDBController()
{
    qDebug () << "PZDBController destroyed";
}

void PZDBController::loadDatabaseCatalog()
{
    emit databeseCatalogLoaded();
    qDebug () << "database catalog loaded";
}
