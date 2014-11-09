#include "TableEntity.h"

TableEntity::TableEntity (const QString &name, const QList<QStandardItem*> &fields)
    : QStandardItem (name)
{
    qDebug () << text ();
    appendRows(fields);
}

TableEntity::TableEntity (const TableEntity &other)
    : QStandardItem (other.text())
{
    for (int i = 0; i < other.rowCount(); ++i) {
        appendRow(new FieldEntity(*(FieldEntity*)other.child(i)));
    }
}

QDataStream& operator << (QDataStream &out,  const TableEntity &te)
{
    int length = te.rowCount();
    out << te.text() << length;
    qDebug () << "TE length" << length;
    for (int i =  0; i < length; ++i) {
        FieldEntity * ent = (FieldEntity*)te.child(i);
        out << *ent;
        qDebug () << ent->text();
    }
    return out;
}

QDataStream& operator >> (QDataStream &in, TableEntity &te)
{
    int length;
    QString text;
    in >> text >> length;
    te.setText(text);
    qDebug () << text << "TE length" << length;
    QList<QStandardItem*> children;
    for (int i = 0; i < length; ++i) {
        FieldEntity ent;
        in >> ent;
        children << new FieldEntity(ent);
        qDebug () << ent.text();
    }
    te.appendRows(children);
    return in;
}
