#ifndef XMLEDITOR_H
#define XMLEDITOR_H

#include <QString>
#include <QDomDocument>
#include <QDomNode>
#include <QDomNodeList>
#include <QDomElement>
#include <QFile>
#include <QDomAttr>
class XmlEditor
{
public:
    XmlEditor(const QString &filename);
    bool createDatabase (const QString &databaseName);
    bool dropDatabase (const QString &databaseName);
private:
    QDomDocument _document;
};

#endif // XMLEDITOR_H
