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
//    QLis load () const;
    static void save (QList<DataBaseEntity> *aList);
private:
    QSettings m_Settings;
    static QString filename;
};

#endif // DATABACECATALOGSERIALIZER_H
