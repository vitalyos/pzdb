#include "FieldEntity.h"

FieldEntity::FieldEntity(const QString &name, const quint8 &type)
    :QStandardItem (name), m_Type (type)
{
    qDebug () << text() << m_Type;
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

QDataStream& operator << (QDataStream &out,  const FieldEntity &fe)
{
    out << fe.text() << fe.fieldType();
    qDebug () << fe.text();
    return out;
}

QDataStream& operator >> (QDataStream &in, FieldEntity &fe)
{
    QString text;
    quint8 type;
    in >> text >> type;
    fe.setText(text);
    fe.setFieldType(type);
    qDebug () << fe.text();
    return in;
}