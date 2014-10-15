#include "XmlEditor.h"

XmlEditor::XmlEditor(const QString &filename)
    :_fileName (filename)
{
    QFile *file = new QFile (_fileName);
    file->open(QIODevice::ReadOnly | QIODevice::Text);
    _document.setContent(file);
    file->close();
    delete file;
}

bool XmlEditor::createDatabase(const QString &databaseName)
{
    QDomNodeList dbs =_document.firstChildElement().childNodes();
    for (int i = 0; i < dbs.count(); ++i) {
        QDomElement el = dbs.at(i).toElement();
        if (el.attribute("dataBaseName") == databaseName) {
            return false;
        }
    }
    QDomElement el = _document.createElement("DataBase");
    el.setAttribute("dataBaseName", databaseName);
    _document.firstChildElement().appendChild(el);
    save();
    return true;
}

bool XmlEditor::dropDatabase(const QString &databaseName)
{
    QDomElement root = _document.firstChildElement();
    QDomNodeList dbs = root.childNodes();
    for (int i = 0; i < dbs.count(); ++i) {
        QDomElement el = dbs.at(i).toElement();
        if (el.attribute("dataBaseName") == databaseName) {
            root.removeChild(el);
            save();
            return true;
        }
    }
    return false;
}

void XmlEditor::save()
{
    QFile *file = new QFile (_fileName);
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream stream (file);
    stream << _document.toString();
    file->close();
    delete file;
}
