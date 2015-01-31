#ifndef DATABASEENTITY_H
#define DATABASEENTITY_H

#include <QList>
#include <QString>
#include <QDebug>

#include "TableEntity.h"

class DataBaseEntity
{
public:
    DataBaseEntity(const QString &name);
    QString name() const;
    void setName(const QString &Name);


    QList<TableEntity> tables() const;
    void setTables(QList<TableEntity> tables);

private:
    QString m_Name;
    QList<TableEntity> m_Tables;
};

QDataStream& operator << (QDataStream &out,  const DataBaseEntity &dbe);
QDataStream& operator >> (QDataStream &in, DataBaseEntity &dbe);

#endif // DATABASEENTITY_H
