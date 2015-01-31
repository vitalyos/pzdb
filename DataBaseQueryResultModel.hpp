#ifndef DATABASEQUERYRESULTMODEL_HPP
#define DATABASEQUERYRESULTMODEL_HPP

#include <QAbstractTableModel>
#include <QObject>
#include "TableEntity.h"

class MongoService;

class DataBaseQueryResultModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    DataBaseQueryResultModel(QObject * aParent = 0);
    ~DataBaseQueryResultModel();
    QStringList content() const;
    void setContent(const QStringList &content);

    TableEntity currentTable() const;
    void setCurrentTable(const TableEntity &currentTable);

    int rowCount (const QModelIndex &parent) const;
    int columnCount (const QModelIndex &parent) const;

    QVariant data (const QModelIndex &index, int role) const;
    QVariant headerData (int section, Qt::Orientation orientation, int role) const;

private:
    QStringList m_content;
    TableEntity m_currentTable;
    MongoService *m_mongo;
signals:
    void dataChanged ();
};

#endif // DATABASEQUERYRESULTMODEL_HPP
