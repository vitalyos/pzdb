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
    Q_PROPERTY(QStringList lens READ lens NOTIFY lensChanged)
public:
    DataBaseQueryResultModel(QObject * aParent = 0);
    ~DataBaseQueryResultModel();
    QStringList content() const;
    void setContent(const QStringList &content);

    TableEntity* currentTable() const;
    void setCurrentTable(TableEntity * currentTable);

    int rowCount (const QModelIndex &parent) const;
    int columnCount (const QModelIndex &parent) const;

    QVariant data (const QModelIndex &index, int role) const;
    QVariant headerData (int section, Qt::Orientation orientation, int role) const;

    QStringList header () const;
    QStringList lens () const;

public slots:
    void deleteRow (const QString aKey);
    void addDataRow (const QStringList & aDataRow);
    void changeCurrentTable (QObject * aTable);
private slots:
    void updateModelData ();

private:
    QStringList m_content;
    QStringList m_tableKeys;
    TableEntity* m_currentTable;
    MongoService *m_mongo;

protected:
    QHash<int, QByteArray> roleNames () const;
signals:
    void dataChanged ();
    void headerChanged ();
    void lensChanged ();
};

#endif // DATABASEQUERYRESULTMODEL_HPP
