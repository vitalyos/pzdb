#include "FieldEntity.h"

FieldEntity::FieldEntity(const QString &name, const quint8 &type, const quint32 &length, const bool &primary, QObject * aParent)
    : QObject (aParent),
      m_Type (type),
      m_Lenght (length),
      m_Primary (primary),
      m_Name (name)
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
    emit primaryChanged ();
}
QString FieldEntity::name() const
{
    return m_Name;
}

void FieldEntity::setName(const QString &name)
{
    m_Name = name;
    emit nameChanged ();
}
QString FieldEntity::refTableName() const
{
    return m_refTableName;
}

void FieldEntity::setRefTableName(const QString &refTableName)
{
    m_refTableName = refTableName;
    emit rtableChanged();
}
QString FieldEntity::refFieldName() const
{
    return m_refFieldName;
}

void FieldEntity::setRefFieldName(const QString &refFieldName)
{
    m_refFieldName = refFieldName;
    emit rfieldChanged ();
}
bool FieldEntity::indexed() const
{
    return m_indexed;
}

void FieldEntity::setIndexed(bool indexed)
{
    m_indexed = indexed;
    emit indexedChanged ();
}

void FieldEntity::setFieldType(const quint8 &type)
{
    m_Type = type;
    emit fieldTypeChanged ();
}

quint32 FieldEntity::length() const
{
    return m_Lenght;
}

void FieldEntity::setLength(const quint32 &length)
{
    m_Lenght = length;
    emit lengthChanged ();
}
