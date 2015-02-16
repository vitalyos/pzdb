#include "TableEntity.h"

TableEntity::TableEntity (QObject *aParent)
    : QObject(aParent)
{
}

QVariant TableEntity::fields() const
{
    QList<QObject*> ret;
    foreach (FieldEntity *f, m_Fields) {
        ret << f;
    }
    return QVariant::fromValue(ret);
}

QList<FieldEntity*> TableEntity::flist () const
{
    return m_Fields;
}

void TableEntity::setFields (QList<FieldEntity*> fields)
{
    m_Fields = fields;
}

int TableEntity::primaryIndex() const
{
    for (int i = 0; i < m_Fields.length(); ++i) {
        if (m_Fields.at(i)->primary()) {
            return i;
        }
    }
    return -1;
}

QString TableEntity::name() const
{
    return m_Name;
}

void TableEntity::setName(const QString &name)
{
    m_Name = name;
    emit nameChanged ();
}
