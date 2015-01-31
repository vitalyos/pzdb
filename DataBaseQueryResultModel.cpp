#include "DataBaseQueryResultModel.hpp"
#include "Tools.h"
#include "FieldEntity.h"
#include "MongoService.h"

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

    for (int i = 0; i < 10; ++i) {
        QStringList al;
        al << "name" + QString::number (i)
           << "phone" + QString::number (i)
           << "user" + QString::number (i) + "@email.com";
        auto res = Tools::convertData (m_currentTable, al);
        m_mongo->insert (m_currentTable.name (), res.first, res.second);
    }
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

    if (role == Qt::DisplayRole) {
        QStringList aRow = Tools::restoreData (m_currentTable, m_content.at (row));
        return aRow.at (column);
    }

    return QVariant();
}
