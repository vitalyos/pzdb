#include "FieldEntity.h"

FieldEntity::FieldEntity(const QString &name, const quint8 &type, const quint32 &length, bool primary)
    :QStandardItem (name), m_Type (type), m_Lenght (length), m_Primary (primary)
{
}

FieldEntity::FieldEntity ()
    : m_Type (0), m_Primary (false)
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

bool FieldEntity::primary() const
{
    return m_Primary;
}

void FieldEntity::setPrimary(const bool &primary)
{
    m_Primary = primary;
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
    out << fe.text()
        << fe.fieldType()
        << fe.length()
        << fe.primary();
    return out;
}

QDataStream& operator >> (QDataStream &in, FieldEntity &fe)
{
    QString text;
    quint8 type;
    quint32 length;
    bool primary;
    in >> text >> type >> length >> primary;
    fe.setText(text);
    fe.setFieldType(type);
    fe.setLength(length);
    fe.setPrimary(primary);
    return in;
}
