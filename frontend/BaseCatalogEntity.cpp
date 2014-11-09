#include "BaseCatalogEntity.h"

BaseCatalogEntity::BaseCatalogEntity(const QString &name)
    : QStandardItem (name)
{
    qDebug () << text();
}

BaseCatalogEntity::BaseCatalogEntity(const BaseCatalogEntity &other)
    : QStandardItem (other.text())
{
    for (int i = 0; i < other.rowCount(); ++i) {
        appendRow(new DataBaseEntity(*(DataBaseEntity*)other.child(i)));
    }
}

void BaseCatalogEntity::addDatabase(DataBaseEntity *database)
{
    appendRow(database);
}

QDataStream& operator << (QDataStream &out,  const BaseCatalogEntity &bce)
{
    int length = bce.rowCount();
    out << bce.text() << length;
    qDebug () << "BCE length" << length;
    for (int i = 0; i < length; ++i) {
        DataBaseEntity * dbe = (DataBaseEntity*)bce.child(i);
        out << (*dbe);
        qDebug () << dbe->text();
    }
    return out;
}

QDataStream& operator >> (QDataStream &in, BaseCatalogEntity &bce)
{
    int length;
    QString text;
    in >> text >> length;
    bce.setText(text);
    qDebug () << "BCE length" << length;
    for (int i = 0; i < length; ++i) {
        DataBaseEntity dbe;
        in >> dbe;
        bce.appendRow(new DataBaseEntity(dbe));
        qDebug () << dbe.text();
    }
    return in;
}
