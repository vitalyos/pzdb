#ifndef FIELDENTITY_H
#define FIELDENTITY_H
#include <QString>
#include <QList>
#include <QDebug>
#include <QObject>
class FieldEntity
        : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int fieldType READ fieldType  NOTIFY fieldTypeChanged)
    Q_PROPERTY(int length READ length  NOTIFY lengthChanged)
    Q_PROPERTY(bool primary READ primary NOTIFY primaryChanged)
    Q_PROPERTY(QString fieldName READ name NOTIFY nameChanged)
    Q_PROPERTY(QString rtable READ refTableName WRITE setRefTableName NOTIFY rtableChanged)
    Q_PROPERTY(QString rfield READ refFieldName WRITE setRefFieldName NOTIFY rfieldChanged)
    Q_PROPERTY(bool indexed READ indexed WRITE setIndexed NOTIFY indexedChanged)
public:
    FieldEntity (const QString &name, const quint8 &type, const quint32 &length, const bool &primary, QObject * aParent = 0);
    FieldEntity (QObject *aParent = 0);

    quint8 fieldType () const;
    quint32 length () const;
    bool primary () const;

    void setFieldType (const quint8 &type);
    void setLength (const quint32 &length);
    void setPrimary (const bool &primary);

    QString name() const;
    void setName(const QString &name);

    QString refTableName() const;
    void setRefTableName(const QString &refTableName);

    QString refFieldName() const;
    void setRefFieldName(const QString &refFieldName);

    bool indexed() const;
    void setIndexed(bool indexed);

private:
    quint8 m_Type;
    quint32 m_Lenght;
    bool m_Primary;
    QString m_Name;
    QString m_refTableName;
    QString m_refFieldName;
    bool m_indexed;
signals:
    void fieldTypeChanged ();
    void lengthChanged ();
    void primaryChanged ();
    void nameChanged ();
    void rtableChanged ();
    void rfieldChanged ();
    void indexedChanged ();
};

#endif // FIELDENTITY_H
