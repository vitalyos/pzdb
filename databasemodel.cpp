#include <QDebug>

#include "databasemodel.h"
#include "TableEntity.h"

DatabaseModel::DatabaseModel(QObject *parentObject)
    : QAbstractListModel (parentObject)
{
    DataBaseEntity d1("University");
    QList<TableEntity*> tel1;
    TableEntity *te11 = new TableEntity;
    TableEntity *te12 = new TableEntity;
    TableEntity *te13 = new TableEntity;
    te11->setName ("t11");
    te12->setName ("te12");
    te13->setName ("te13");
    tel1 << te11 << te12 << te13;
    d1.setTables(tel1);
    m_Content << d1
              << DataBaseEntity("Life")
              << DataBaseEntity("High School");
}

DatabaseModel::~DatabaseModel()
{

}

int DatabaseModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_Content.size();
}

QVariant DatabaseModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    int idx = index.row();
    if (idx < 0 || idx >= m_Content.size()) {
        return QVariant();
    }

    DataBaseEntity current = m_Content.at(idx);

    switch (role) {
    case NAME_ROLE:
        return current.name();
    case TABLE_ROLE: {
        QList<QObject*> ret;
        foreach (TableEntity *te, current.tables ()) {
            ret << te;
        }
        return QVariant::fromValue(ret);
    }
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> DatabaseModel::roleNames() const
{
    QHash<int, QByteArray> ret;

    ret[NAME_ROLE] = "name";
    ret[TABLE_ROLE] = "tableModel";

    return ret;
}
