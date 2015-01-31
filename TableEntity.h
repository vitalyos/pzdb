#ifndef TABLEENTITY_H
#define TABLEENTITY_H

#include <QString>
#include <QList>
#include <QDebug>
#include "FieldEntity.h"

class TableEntity
{
public:
    TableEntity(const QString &name, const QList<FieldEntity> &fields);
    TableEntity(const QString &name);
    TableEntity();

    QList<FieldEntity> fields () const;
    void setFields (const QList<FieldEntity> &fields);

    int primaryIndex () const;

    QString name() const;
    void setName(const QString &name);

private:
    QString m_Name;
    QList<FieldEntity> m_Fields;
};

QDataStream& operator << (QDataStream &out,  const TableEntity &te);
QDataStream& operator >> (QDataStream &in, TableEntity &te);
QDataStream& operator << (QDataStream &out, const QList<TableEntity> &aList);
QDataStream& operator >> (QDataStream &in, QList<TableEntity> &aList);

Q_DECLARE_METATYPE(TableEntity)
Q_DECLARE_METATYPE(QList<TableEntity>)
#endif // TABLEENTITY_H
