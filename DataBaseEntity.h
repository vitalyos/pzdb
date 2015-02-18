#ifndef DATABASEENTITY_H
#define DATABASEENTITY_H

#include <QList>
#include <QString>
#include <QDebug>
#include <QMetaType>

#include "TableEntity.h"

class DataBaseEntity
{
public:
    DataBaseEntity(const QString &name);
    QString name() const;
    void setName(const QString &Name);


    QList<TableEntity*> tables() const;
    void setTables(QList<TableEntity*> tables);

    int getIndexByName (const QString &tableName) const;

private:
    QString m_Name;
    QList<TableEntity*> m_Tables;
};
#endif // DATABASEENTITY_H
