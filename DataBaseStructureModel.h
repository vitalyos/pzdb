#ifndef DATABASESTRUCTUREMODEL_H
#define DATABASESTRUCTUREMODEL_H

#include <QStandardItemModel>
#include "TableEntity.h"
#include "DataBaseCatalogSerializer.h"

class DataBaseStructureModel
        : public QStandardItemModel
{
    Q_OBJECT
public:
    DataBaseStructureModel(DataBaseCatalogSerializer * serializer);
private:
    DataBaseCatalogSerializer * m_Serializer;
    BaseCatalogEntity * m_CatalogRoot;
public slots:
    void createDataBase (const QString &dataBaseName);
    void dropDataBase (const QString &dataBaseName);
    void createTable (const QString &dataBaseName, TableEntity * table);
    void dropTable (const QString &dataBaseName, const QString tableName);
    void loadModel ();
    void saveModel ();
};

#endif // DATABASESTRUCTUREMODEL_H
