#include "MongoService.h"

QString MongoService::KEY_NAME = "key";
QString MongoService::VALUE_NAME = "value";

MongoService::MongoService()
{
    try {
        m_ProjectName = "qoptim";
        m_Connection.connect("localhost");
        qDebug () << "mongodb connection ok";
    } catch (mongo::DBException & exception) {
        qDebug () << "connection problem:" << exception.what();
    }
}

std::string MongoService::convert(const QString &tableName) const
{
    return (m_ProjectName + "." + tableName).toStdString();
}

void MongoService::insert(const QString &table, const QString &key, const QString &value)
{
    mongo::BSONObjBuilder builder;
    builder << MongoService::KEY_NAME.toStdString ()<< key.toStdString();
    builder << MongoService::VALUE_NAME.toStdString () << value.toStdString();
    qDebug () << key << value;
    m_Connection.insert(convert(table), builder.obj());
}

QString MongoService::data(const QString &table, const QString &key)
{
    std::auto_ptr<mongo::DBClientCursor> cursor;
    cursor = m_Connection.query(convert(table),
                                MONGO_QUERY (MongoService::KEY_NAME.toStdString () << key.toStdString()));
    QString ret;

    if (cursor->more()) {
        mongo::BSONObj tempObj = cursor->next();
        ret = tempObj.getStringField(MongoService::VALUE_NAME.toStdString ());
    }

    return ret;
}

void MongoService::remove(const QString &table, const QString &key)
{
    m_Connection.remove(convert(table),
                        MONGO_QUERY(MongoService::KEY_NAME.toStdString () << key.toStdString()));
}

QStringList MongoService::getAllRows(const QString &tableName)
{
    return getMongoFiled (tableName, MongoService::VALUE_NAME);
}

QStringList MongoService::getAllKeys (const QString &tableName)
{
    return getMongoFiled (tableName, MongoService::KEY_NAME);
}

QStringList MongoService::getMongoFiled (const QString &tableName, const QString &fieldName)
{
    QStringList ret;
    std::auto_ptr<mongo::DBClientCursor> cursor;
    cursor = m_Connection.query(convert(tableName), mongo::BSONObj());
    while (cursor->more()) {
        mongo::BSONObj current = cursor->next();
        ret << current.getStringField(fieldName.toStdString ());
    }
    return ret;
}
