#ifndef FIELDENTITY_H
#define FIELDENTITY_H
#include <QString>
#include <QList>
#include <QStandardItem>
#include <QDebug>
#include "Enumerator.h"

class FieldEntity : public QStandardItem
{
public:
    FieldEntity(const QString &name, const quint8 &type, const quint32 &length);
    FieldEntity();
    FieldEntity(const FieldEntity &other);

    quint8 fieldType () const;
    quint32 length () const;

    void setFieldType (const quint8 &type);
    void setLength (const quint32 &length);
private:
    quint8 m_Type;
    quint32 m_Lenght;
};


QDataStream& operator << (QDataStream &out,  const FieldEntity &fe);
QDataStream& operator >> (QDataStream &in, FieldEntity &fe);

Q_DECLARE_METATYPE (FieldEntity)

#endif // FIELDENTITY_H
