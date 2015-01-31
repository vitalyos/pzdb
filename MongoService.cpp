#include "MongoService.h"

MongoService::MongoService()
{
    mongo::client::initialize ();
    try {
        m_ProjectName = "qoptim";
        m_Connection.connect("localhost");
        qDebug () << "connection ok";
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
    builder << "key" << key.toStdString();
    builder << "value" << value.toStdString();
    qDebug () << key << value;
    m_Connection.insert(convert(table), builder.obj());
}

QString MongoService::data(const QString &table, const QString &key)
{
    std::auto_ptr<mongo::DBClientCursor> cursor;
    cursor = m_Connection.query(convert(table),
                                MONGO_QUERY ("key" << key.toStdString()));
    QString ret;

    if (cursor->more()) {
        mongo::BSONObj tempObj = cursor->next();
        ret = tempObj.getStringField("value");
    }

    return ret;
}

void MongoService::remove(const QString &table, const QString &key)
{
    m_Connection.remove(convert(table),
                        MONGO_QUERY("key" << key.toStdString()));
}

QStringList MongoService::getAllRows(const QString &table)
{
    QStringList ret;
    std::auto_ptr<mongo::DBClientCursor> cursor;
    cursor = m_Connection.query(convert(table), mongo::BSONObj());
    while (cursor->more()) {
        mongo::BSONObj current = cursor->next();
        ret << current.getStringField("value");
    }
    return ret;
}
