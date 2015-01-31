#ifndef FIELDENTITY_H
#define FIELDENTITY_H
#include <QString>
#include <QList>
#include <QDebug>
#include "Enumerator.h"

class FieldEntity
{
public:
    FieldEntity(const QString &name, const quint8 &type, const quint32 &length, bool primary = false);
    FieldEntity();
    FieldEntity(const FieldEntity &other);

    quint8 fieldType () const;
    quint32 length () const;
    bool primary () const;

    void setFieldType (const quint8 &type);
    void setLength (const quint32 &length);
    void setPrimary (const bool &primary);

    QString name() const;
    void setName(const QString &name);

private:
    quint8 m_Type;
    quint32 m_Lenght;
    bool m_Primary;
    QString m_Name;
};


QDataStream& operator << (QDataStream &out,  const FieldEntity &fe);
QDataStream& operator >> (QDataStream &in, FieldEntity &fe);

QDataStream& operator << (QDataStream &out,  const QList<FieldEntity> &fes);
QDataStream& operator >> (QDataStream &in, QList<FieldEntity> &fe);


Q_DECLARE_METATYPE (FieldEntity)
Q_DECLARE_METATYPE (QList<FieldEntity>)

#endif // FIELDENTITY_H
