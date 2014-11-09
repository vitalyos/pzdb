#ifndef DATABASEENTITY_H
#define DATABASEENTITY_H

#include <QList>
#include <QString>
#include <QStandardItem>
#include <QDebug>
#include "TableEntity.h"

class DataBaseEntity
        : public QStandardItem
{
public:
    DataBaseEntity(const QString &name = QString());
    DataBaseEntity (const DataBaseEntity &other);
    void addTable (TableEntity *table);
};

QDataStream& operator << (QDataStream &out,  const DataBaseEntity &dbe);
QDataStream& operator >> (QDataStream &in, DataBaseEntity &dbe);

Q_DECLARE_METATYPE (DataBaseEntity)

#endif // DATABASEENTITY_H
