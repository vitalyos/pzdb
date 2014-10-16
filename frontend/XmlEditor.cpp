#include "XmlEditor.h"

XmlEditor::XmlEditor(const QDomDocument &document, const QString &filename)
    :_document (document), _fileName (filename)
{
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

bool XmlEditor::dropTable(const QString &databaseName, const QString &tableName)
{
    QDomElement root = _document.firstChildElement();
    QDomNodeList dbs = root.childNodes();
    for (int i = 0; i < dbs.count(); ++i) {
        QDomElement el = dbs.at(i).toElement();
        if (el.attribute("dataBaseName") == databaseName) {
            QDomNodeList tables = el.firstChildElement().childNodes();
            for (int j = 0; j < tables.count(); ++j) {
                QDomElement table = tables.at(j).toElement();
                if (table.attribute("tableName") == tableName) {
                    el.firstChildElement().removeChild(table);
                    save ();
                    return true;
                }
            }
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
