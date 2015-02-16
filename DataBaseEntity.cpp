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
