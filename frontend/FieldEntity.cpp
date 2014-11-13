#include "FieldEntity.h"

FieldEntity::FieldEntity(const QString &name, const quint8 &type, const quint32 &length)
    :QStandardItem (name), m_Type (type), m_Lenght (length)
{
}

FieldEntity::FieldEntity ()
    : m_Type (0)
{
    setText(QString());
}

FieldEntity::FieldEntity(const FieldEntity &other)
    : QStandardItem (other.text()), m_Type (other.fieldType())
{
}

quint8 FieldEntity::fieldType() const
{
    return m_Type;
}

void FieldEntity::setFieldType(const quint8 &type)
{
    m_Type = type;
}

quint32 FieldEntity::length() const
{
    return m_Lenght;
}

void FieldEntity::setLength(const quint32 &length)
{
    m_Lenght = length;
}

QDataStream& operator << (QDataStream &out,  const FieldEntity &fe)
{
    out << fe.text() << fe.fieldType();
    return out;
}

QDataStream& operator >> (QDataStream &in, FieldEntity &fe)
{
    QString text;
    quint8 type;
    in >> text >> type;
    fe.setText(text);
    fe.setFieldType(type);
    return in;
}
