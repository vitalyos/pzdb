#include "TableEntity.h"

TableEntity::TableEntity (const QString &name, const QList<QStandardItem*> &fields)
    : QStandardItem (name)
{
    appendRows(fields);
}

TableEntity::TableEntity (const TableEntity &other)
    : QStandardItem (other.text())
{
    for (int i = 0; i < other.rowCount(); ++i) {
        appendRow(new FieldEntity(*(FieldEntity*)other.child(i)));
    }
}

QList<FieldEntity> TableEntity::fields() const
{
    QList<FieldEntity> ret;
    for (int i = 0 ; i < rowCount(); ++i) {
        ret << *(FieldEntity*)child(i);
    }
    return ret;
}

QDataStream& operator << (QDataStream &out,  const TableEntity &te)
{
    int length = te.rowCount();
    out << te.text() << length;
    for (int i =  0; i < length; ++i) {
        FieldEntity * ent = (FieldEntity*)te.child(i);
        out << *ent;
    }
    return out;
}

QDataStream& operator >> (QDataStream &in, TableEntity &te)
{
    int length;
    QString text;
    in >> text >> length;
    te.setText(text);
    QList<QStandardItem*> children;
    for (int i = 0; i < length; ++i) {
        FieldEntity ent;
        in >> ent;
        children << new FieldEntity(ent);
    }
    te.appendRows(children);
    return in;
}
