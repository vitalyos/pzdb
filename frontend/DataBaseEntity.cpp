#include "DataBaseEntity.h"

DataBaseEntity::DataBaseEntity(const QString &name)
    : QStandardItem (name)
{
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
    for (int i = 0; i < length; ++i) {
        TableEntity * table = (TableEntity*)dbe.child(i);
        out << *table;
    }
    return out;
}

QDataStream& operator >> (QDataStream &in, DataBaseEntity &dbe)
{
    int length;
    QString text;
    in >> text >> length;
    dbe.setText(text);
    for (int i = 0; i < length; ++i) {
        TableEntity table;
        in >> table;
        dbe.appendRow(new TableEntity(table));
    }
    return in;
}
