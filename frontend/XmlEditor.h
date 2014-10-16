#ifndef XMLEDITOR_H
#define XMLEDITOR_H

#include <QString>
#include <QDomDocument>
#include <QDomNode>
#include <QDomNodeList>
#include <QDomElement>
#include <QFile>
#include <QDomAttr>
#include <QDebug>
#include <QTextStream>

class XmlEditor
{
public:
    XmlEditor(const QString &filename);
    bool createDatabase (const QString &databaseName);
    bool dropDatabase (const QString &databaseName);
    bool dropTable (const QString &databaseName, const QString &tableName);
    bool createTable ();
private:
    QDomDocument _document;
    QString _fileName;

    void save ();
};

#endif // XMLEDITOR_H
