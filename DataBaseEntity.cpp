#include "DataBaseEntity.h"

DataBaseEntity::DataBaseEntity(const QString &name)
    : m_Name (name)
{
}

QString DataBaseEntity::name() const
{
    return m_Name;
}

void DataBaseEntity::setName(const QString &name)
{
    m_Name = name;
}

QList<TableEntity *> DataBaseEntity::tables() const
{
    return m_Tables;
}

void DataBaseEntity::setTables(QList<TableEntity *> tables)
{
    m_Tables = tables;
}

int DataBaseEntity::getIndexByName (const QString &tableName) const
{
    for (int i = 0; i < m_Tables.size (); ++i) {
        if (m_Tables.at (i)->name () == tableName) {
            return i;
        }
    }
    return -1;
}

void DataBaseEntity::removeTable (const QString &tableName)
{
    int idx = getIndexByName (tableName);
    if (idx != -1) {
        m_Tables.removeAt (idx);
    }
}
