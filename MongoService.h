#ifndef MONGOSERVICE_H
#define MONGOSERVICE_H

#include "mongo/client/dbclient.h"
#include "mongo/client/dbclientinterface.h"
#include <QDebug>
#include <string>

class MongoService
{
public:
    MongoService();
    void insert (const QString &table, const QString &key, const QString &value);
    QString data (const QString &table, const QString &key);
    void remove (const QString &table, const QString &key);
    QStringList getAllRows (const QString &tableName);
    QStringList getAllKeys (const QString &tableName);
private:
    mongo::DBClientConnection m_Connection;
    QString m_ProjectName;
    std::string convert (const QString &tableName) const;
    QStringList getMongoFiled (const QString &tableName, const QString &fieldName);
    static QString KEY_NAME;
    static QString VALUE_NAME;
};

#endif // MONGOSERVICE_H
