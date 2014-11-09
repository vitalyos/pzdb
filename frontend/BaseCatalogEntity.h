#ifndef BASECATALOGENTITY_H
#define BASECATALOGENTITY_H

#include <QDebug>
#include <QString>
#include <QList>
#include <QStandardItem>
#include "DataBaseEntity.h"
#include "DataBaseEntity.h"

class BaseCatalogEntity
        : public QStandardItem
{
public:
    BaseCatalogEntity(const QString &name = QString());
    BaseCatalogEntity(const BaseCatalogEntity &other);
    void addDatabase (DataBaseEntity * database);
};

QDataStream& operator << (QDataStream &out,  const BaseCatalogEntity &bce);
QDataStream& operator >> (QDataStream &in, BaseCatalogEntity &bce);

Q_DECLARE_METATYPE (BaseCatalogEntity)
#endif // BASECATALOGENTITY_H
