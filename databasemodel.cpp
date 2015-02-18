#include <QDebug>

#include "databasemodel.h"
#include "TableEntity.h"
#include "DataBaseCatalogSerializer.h"

//#define DEMO

DatabaseModel::DatabaseModel(QObject *parentObject)
    : QAbstractListModel (parentObject)
{
    m_currentDatabaseIndex = -1;

#ifdef DEMO
    DataBaseEntity d1("University");
    QList<TableEntity*> tel1;
    TableEntity *te11 = new TableEntity;
    TableEntity *te12 = new TableEntity;
    TableEntity *te13 = new TableEntity;
    QList<FieldEntity*>fes;
    fes << new FieldEntity("fe1", 1, 10, true)
        << new FieldEntity("fe2", 1, 10, false)
        << new FieldEntity("fe3", 1, 20, false);
    te11->setFields (fes);
    te11->setName ("te11");
    te12->setName ("te12");
    te13->setName ("te13");
    tel1 << te11 << te12 << te13;
    d1.setTables(tel1);
    m_Content << d1
              << DataBaseEntity("Life")
              << DataBaseEntity("High School");
    DataBaseCatalogSerializer::save (&m_Content);
#else
    m_Content = DataBaseCatalogSerializer::load ();
#endif
    connect (this, &DatabaseModel::structureChanged, this, &DatabaseModel::saveStructure);
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

void DatabaseModel::sig ()
{
    emit currentTableChanged (m_Content.at (0).tables ().at (0));
}

int DatabaseModel::getIndexByName (const QString &aName)
{
    for (int i = 0; i < m_Content.size (); ++i) {
        if (m_Content.at (i).name () == aName) {
            return i;
        }
    }
    return -1;
}

void DatabaseModel::createDatabase (const QString &dbName)
{
    int idx = getIndexByName (dbName);
    if (idx == -1) {
        beginResetModel ();
        m_Content << DataBaseEntity(dbName);
        endResetModel ();
    }
    emit structureChanged ();
}

void DatabaseModel::dropDatabase (const QString &dbName)
{
    int idx = getIndexByName (dbName);
    if (idx != -1) {
        beginResetModel ();
        m_Content.removeAt (idx);
        endResetModel ();
        emit structureChanged ();
    }
}

void DatabaseModel::changeCurrentDatabase (const QString &dbName)
{
    int idx = getIndexByName (dbName);
    if (idx != -1) {
        m_currentDatabaseIndex = idx;
        emit currentDbChanged (dbName);
    }
}

void DatabaseModel::changeCurrentTable (const QString &tableName)
{
    int idx = m_Content.at (m_currentDatabaseIndex).getIndexByName (tableName);
    if (idx != -1) {
        QObject *table = m_Content.at (m_currentDatabaseIndex).tables ().at (idx);
        emit currentTableChanged (table);
    }
}

void DatabaseModel::createTable (const QString &name, const QList<QStringList> &body)
{
    emit structureChanged ();
}

void DatabaseModel::dropTable (const QString &name)
{
    beginResetModel ();
    m_Content[m_currentDatabaseIndex].removeTable (name);
    endResetModel ();
    emit structureChanged ();
}

void DatabaseModel::saveStructure ()
{
    DataBaseCatalogSerializer::save (&m_Content);
}
