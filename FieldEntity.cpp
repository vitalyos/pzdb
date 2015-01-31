#include "FieldEntity.h"

FieldEntity::FieldEntity(const QString &name, const quint8 &type, const quint32 &length, bool primary)
    : m_Name (name),
      m_Type (type),
      m_Lenght (length),
      m_Primary (primary)
{
    qRegisterMetaType<FieldEntity>("FieldEntity");
    qRegisterMetaType< QList<FieldEntity> >("QList<FieldEntity>");

    qRegisterMetaTypeStreamOperators<FieldEntity>("FieldEntity");
    qRegisterMetaTypeStreamOperators< QList<FieldEntity> >("QList<FieldEntity>");
}

FieldEntity::FieldEntity ()
    : FieldEntity (QString(), 0, 24, false)
{
}

FieldEntity::FieldEntity(const FieldEntity &other)
    : m_Name (other.name ()),
      m_Type (other.fieldType()),
      m_Lenght (other.length()),
      m_Primary (other.primary())
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
QString FieldEntity::name() const
{
    return m_Name;
}

void FieldEntity::setName(const QString &name)
{
    m_Name = name;
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
    out << fe.name ()
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
    fe.setName (text);
    fe.setFieldType(type);
    fe.setLength(length);
    fe.setPrimary(primary);
    return in;
}

QDataStream& operator << (QDataStream &out,  const QList<FieldEntity> &fes)
{
    out << fes.size ();
    for (auto &fe : fes) {
        out << fe;
    }
    return out;
}

QDataStream& operator >> (QDataStream &in, QList<FieldEntity> &fe)
{
    int size;
    in >> size;
    for (int i = 0; i < size; ++i) {
        FieldEntity aEnt;
        in >> aEnt;
        fe << aEnt;
    }
    return in;
}
