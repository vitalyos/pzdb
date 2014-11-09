#include "DataBaseEntity.h"

DataBaseEntity::DataBaseEntity(const QString &name)
    : QStandardItem (name)
{
    qDebug () << text();
}

DataBaseEntity::DataBaseEntity (const DataBaseEntity &other)
    : QStandardItem (other.text())
{
    for (int i = 0; i < other.rowCount(); ++i) {
        appendRow(new TableEntity(*(TableEntity*)other.child(i)));
    }
}

void DataBaseEntity::addTable(TableEntity *table)
{
    appendRow(table);
}

QDataStream& operator << (QDataStream &out,  const DataBaseEntity &dbe)
{
    int length = dbe.rowCount();
    out << dbe.text() << length;
    qDebug () << "DBE length" << length;
    for (int i = 0; i < length; ++i) {
        TableEntity * table = (TableEntity*)dbe.child(i);
        out << *table;
        qDebug () << table->text();
    }
    return out;
}

QDataStream& operator >> (QDataStream &in, DataBaseEntity &dbe)
{
    int length;
    QString text;
    in >> text >> length;
    dbe.setText(text);
    qDebug () << text << "DBE length" << length;
    for (int i = 0; i < length; ++i) {
        TableEntity table;
        in >> table;
        dbe.appendRow(new TableEntity(table));
        qDebug () << table.text();
    }
    return in;
}
