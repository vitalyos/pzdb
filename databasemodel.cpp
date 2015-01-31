#include <QDebug>

#include "databasemodel.h"
#include "TableEntity.h"

DatabaseModel::DatabaseModel(QObject *parentObject)
    : QAbstractListModel (parentObject)
{
    DataBaseEntity d1("University");
    QList<TableEntity> tel1;
    tel1 << TableEntity("t11") << TableEntity("t12") << TableEntity("t13");
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
    case Roles::NAME_ROLE:
        return current.name();
    case Roles::TABLE_ROLE: {
        qDebug () << "size" << current.tables().size();
        QStringList tbs;
        for (auto &t : current.tables ()) {
            tbs << t.name ();
        }
        qDebug () << tbs;
        return QVariant::fromValue(tbs);
    }
        //return QVariant::fromValue(current.tables());
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> DatabaseModel::roleNames() const
{
    QHash<int, QByteArray> ret;

    ret[Roles::NAME_ROLE] = "name";
    ret[Roles::TABLE_ROLE] = "tableModel";

    return ret;
}
