#ifndef DATABASEQUERYRESULTMODEL_HPP
#define DATABASEQUERYRESULTMODEL_HPP

#include <QAbstractTableModel>
#include <QObject>
#include "TableEntity.h"

class MongoService;

class DataBaseQueryResultModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(QStringList header READ header NOTIFY headerChanged)
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

    QStringList header () const;

public slots:
    void deleteRow (const QString aKey);
    void addDataRow (const QStringList & aDataRow);
private slots:
    void updateModelData ();

private:
    QStringList m_content;
    QStringList m_tableKeys;
    TableEntity m_currentTable;
    MongoService *m_mongo;

protected:
    QHash<int, QByteArray> roleNames () const;
signals:
    void dataChanged ();
    void headerChanged ();
};

#endif // DATABASEQUERYRESULTMODEL_HPP
