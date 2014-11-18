#include "DataBaseStructureModel.h"
#include "BaseCatalogEntity.h"

DataBaseStructureModel::DataBaseStructureModel(DataBaseCatalogSerializer * serializer)
    : m_Serializer (serializer)
{
    loadModel();
}

void DataBaseStructureModel::loadModel()
{
    m_CatalogRoot = new BaseCatalogEntity(m_Serializer->load());
    beginResetModel();
    appendRow(m_CatalogRoot);
    endResetModel();
}

void DataBaseStructureModel::saveModel()
{
    m_Serializer->save(*m_CatalogRoot);
}

void DataBaseStructureModel::createDataBase(const QString &dataBaseName)
{

}

void DataBaseStructureModel::dropDataBase(const QString &dataBaseName)
{

}

void DataBaseStructureModel::createTable(const QString &dataBaseName, TableEntity *table)
{

}

void DataBaseStructureModel::dropTable(const QString &dataBaseName, const QString tableName)
{

}
