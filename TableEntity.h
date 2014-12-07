#ifndef TABLEENTITY_H
#define TABLEENTITY_H

#include <QString>
#include <QList>
#include <QStandardItem>
#include <QDebug>
#include "FieldEntity.h"

class TableEntity : public QStandardItem
{
public:
    TableEntity(const QString &name = QString(), const QList<QStandardItem *> &fields = QList<QStandardItem*>());
    TableEntity(const TableEntity &other);
    QList<FieldEntity> fields () const;
    int primaryIndex () const;
};

QDataStream& operator << (QDataStream &out,  const TableEntity &te);
QDataStream& operator >> (QDataStream &in, TableEntity &te);

Q_DECLARE_METATYPE (TableEntity)

#endif // TABLEENTITY_H
