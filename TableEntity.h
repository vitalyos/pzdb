#ifndef TABLEENTITY_H
#define TABLEENTITY_H

#include <QString>
#include <QList>
#include <QDebug>
#include <QObject>
#include "FieldEntity.h"

class TableEntity : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString tableName READ name NOTIFY nameChanged)
    Q_PROPERTY(QVariant fields READ fields NOTIFY fieldsChanged)
public:
    TableEntity(QObject * aParent = 0);

    QVariant fields () const;
    void setFields (QList<FieldEntity*> fields);
    QList<FieldEntity*> flist() const;

    int primaryIndex () const;

    QString name() const;
    void setName(const QString &name);

private:
    QString m_Name;
    QList<FieldEntity*> m_Fields;
signals:
    void nameChanged ();
    void fieldsChanged ();
};

#endif // TABLEENTITY_H
