#include "TableEntity.h"

TableEntity::TableEntity (const QString &name, const QList<FieldEntity> &fields)
    : m_Name (name), m_Fields (fields)
{
}

TableEntity::TableEntity ()
    : TableEntity (QString(), QList<FieldEntity>())
{

}

TableEntity::TableEntity(const QString &name)
    : TableEntity(name, QList<FieldEntity>())
{

}

QList<FieldEntity> TableEntity::fields() const
{
    return m_Fields;
}

void TableEntity::setFields (const QList<FieldEntity> &fields)
{
    m_Fields = fields;
}

int TableEntity::primaryIndex() const
{
    QList<FieldEntity> fs = fields();
    for (int i = 0; i < fs.length(); ++i) {
        if (fs.at(i).primary()) {
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
}


QDataStream& operator << (QDataStream &out,  const TableEntity &te)
{
    out << te.name () << te.fields ();
    return out;
}

QDataStream& operator >> (QDataStream &in, TableEntity &te)
{
    int length;
    QString name;
    in >> name >> length;
    te.setName (name);
    QList<FieldEntity> ents;
    in >> ents;
    te.setFields (ents);
    return in;
}

QDataStream& operator << (QDataStream &out, const QList<TableEntity> &aList)
{
    qDebug () << "..............." << aList.size ();
    out << aList.size();
//    for (auto &el : aList) {
    foreach (TableEntity el, aList) {
        out << el;
    }
    return out;
}

QDataStream& operator >> (QDataStream &in, QList<TableEntity> &aList)
{
    int size;
    in >> size;
    for (int i = 0; i < size; ++i) {
        TableEntity aEntity;
        in >> aEntity;
        aList << aEntity;
    }
    qDebug () << "deserialized size: " << aList.size();
    return in;
}
