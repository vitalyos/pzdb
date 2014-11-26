#ifndef MONGOSERVICE_H
#define MONGOSERVICE_H

#include "mongo/client/dbclient.h"

#include <QDebug>
#include <string>

class MongoService
{
public:
    MongoService();
    void insert (const QString &table, const QString &key, const QString &value);
    QString data (const QString &table, const QString &key);
    void remove (const QString &table, const QString &key);
    QStringList getAllRows (const QString &table);
private:
    mongo::DBClientConnection m_Connection;
    QString m_ProjectName;
    std::string convert (const QString &tableName) const;
};

#endif // MONGOSERVICE_H
