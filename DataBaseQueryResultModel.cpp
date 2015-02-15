#include "DataBaseQueryResultModel.hpp"
#include "Tools.h"
#include "FieldEntity.h"
#include "MongoService.h"
#include <QList>

DataBaseQueryResultModel::DataBaseQueryResultModel(QObject *aParent)
    : QAbstractTableModel (aParent)
{
    QList<FieldEntity> fs;
    fs << FieldEntity("studentName", 0, 32, true)
       << FieldEntity("phone", 0, 15)
       << FieldEntity("mail", 0, 40);
    m_currentTable.setName ("ExamPle");
    m_currentTable.setFields (fs);

    m_mongo = new MongoService;

#ifdef GENERATE_DATA
    for (int i = 0; i < 101; ++i) {
        QStringList al;
        al << "name" + QString::number (i)
           << "phone" + QString::number (i)
           << "user" + QString::number (i) + "@email.com";
        QPair<QString, QString> res = Tools::convertData (m_currentTable, al);
        m_mongo->insert (m_currentTable.name (), res.first, res.second);
    }
#endif
    connect (this, &DataBaseQueryResultModel::dataChanged, this, &DataBaseQueryResultModel::updateModelData);
    emit dataChanged ();
}

DataBaseQueryResultModel::~DataBaseQueryResultModel()
{
    delete m_mongo;
}
QStringList DataBaseQueryResultModel::content() const
{
    return m_content;
}

void DataBaseQueryResultModel::setContent(const QStringList &content)
{
    m_content = content;
}
TableEntity DataBaseQueryResultModel::currentTable() const
{
    return m_currentTable;
}

void DataBaseQueryResultModel::setCurrentTable(const TableEntity &currentTable)
{
    m_currentTable = currentTable;
}

int DataBaseQueryResultModel::rowCount (const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_content.size ();
}

int DataBaseQueryResultModel::columnCount (const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_currentTable.fields ().size ();
}

QVariant DataBaseQueryResultModel::headerData (int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    if (orientation == Qt::Horizontal) {
        if (section >= m_currentTable.fields ().size ()) {
            return QVariant();
        } else {
            return m_currentTable.fields ().at (section).name ();
        }
    }
    return QVariant();
}

QVariant DataBaseQueryResultModel::data (const QModelIndex &index, int role) const
{
    if (!index.isValid ()) {
        return QVariant();
    }

    int row = index.row ();
    int column = index.column ();

    if (row >= m_content.size () || row < 0) {
        return QVariant();
    }

    if (column >= m_currentTable.fields ().size () && column < 0) {
        return QVariant();
    }

    if (role == m_currentTable.fields ().size ()) {
        return m_tableKeys.at (row);
    }

    QStringList aRow = Tools::restoreData (m_currentTable, m_content.at (row));
    return aRow.at (role);

    return QVariant();
}

QStringList DataBaseQueryResultModel::header () const
{
    QStringList result;
    foreach (FieldEntity field, m_currentTable.fields ()) {
        result << field.name ();
    }
    result << "dbkey";
    return result;
}

QHash<int, QByteArray> DataBaseQueryResultModel::roleNames () const
{
    QHash<int, QByteArray> roles;
    for (int i = 0; i < m_currentTable.fields ().length (); ++i) {
        roles[i] = m_currentTable.fields ().at (i).name ().toStdString ().c_str ();
    }
    roles[m_currentTable.fields ().length ()] = "dbkey";
    return roles;
}

void DataBaseQueryResultModel::deleteRow (const QString aKey)
{
    m_mongo->remove (m_currentTable.name (), aKey);
    emit dataChanged ();
}

void DataBaseQueryResultModel::updateModelData ()
{
    beginResetModel ();
    m_content = m_mongo->getAllRows (m_currentTable.name ());
    m_tableKeys = m_mongo->getAllKeys (m_currentTable.name ());
    endResetModel ();
}

void DataBaseQueryResultModel::addDataRow (const QStringList &aDataRow)
{
    QPair<QString, QString> data = Tools::convertData (m_currentTable, aDataRow);
    m_mongo->insert (m_currentTable.name (), data.first, data.second);
    emit dataChanged ();
}

QStringList DataBaseQueryResultModel::lens() const
{
    QStringList ret;
    for (int i = 0; i < m_currentTable.fields ().size (); ++i) {
        ret << QString::number (m_currentTable.fields ().at (i).length ());
    }
    return ret;
}
