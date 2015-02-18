#ifndef DATABACECATALOGSERIALIZER_H
#define DATABACECATALOGSERIALIZER_H

#include <QSettings>
#include <QVariant>
#include <QDebug>
#include "DataBaseEntity.h"
#include <QString>

class DataBaseCatalogSerializer
{
public:
    static QList<DataBaseEntity> load ();
    static void save (QList<DataBaseEntity> *aList);
private:
    static QString filename;
};

#endif // DATABACECATALOGSERIALIZER_H
