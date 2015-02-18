#ifndef DATABASEMODEL_H
#define DATABASEMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QList>
#include <QHash>
#include <QByteArray>

#include "DataBaseEntity.h"

class DatabaseModel
        : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit DatabaseModel(QObject * parentObject = 0);
    ~DatabaseModel();
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    Q_INVOKABLE void sig ();
private:
    QList<DataBaseEntity> m_Content;
    QHash<int, QByteArray> roleNames() const;

    int getIndexByName (const QString &aName);

    enum Roles {
        NAME_ROLE = 1,
        TABLE_ROLE = 2
    };
signals:
    void currentTableChanged (QObject * aTable);
public slots:
    void dropDatabase (const QString &dbName);
    void createDatabase (const QString &dbName);
};

#endif // DATABASEMODEL_H
