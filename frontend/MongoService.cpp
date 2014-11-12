#include "MongoService.h"

MongoService::MongoService()
{
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
    m_Connection.insert(convert(table), builder.obj());
    qDebug () << "insert ok" << table << key << value;
}

QString MongoService::data(const QString &table, const QString &key)
{
    mongo::auto_ptr<mongo::DBClientCursor> cursor;
    cursor = m_Connection.query(convert(table),
                                QUERY ("key" << key.toStdString()));
    QString ret;

    if (cursor->more()) {
        mongo::BSONObj tempObj = cursor->next();
        ret = tempObj.getStringField("value");
        qDebug () << "data found for" << key << "in" << table;
    } else {
        qDebug () << "data doesn't exists for" << key << "in" << table;
    }

    return ret;
}

void MongoService::remove(const QString &table, const QString &key)
{
    m_Connection.remove(convert(table),
                        QUERY("key" << key.toStdString()));
    qDebug () << "remove ok" << table << key;
}
