#include "XmlEditor.h"

XmlEditor::XmlEditor(const QString &filename)
{
    QFile *file = new QFile (filename);
    file->open(QIODevice::ReadOnly);
    _document.setContent(file);
    delete file;
}

bool XmlEditor::createDatabase(const QString &databaseName)
{
    return true;
}

bool XmlEditor::dropDatabase(const QString &databaseName)
{
    QDomNodeList nodes = _document.elementsByTagName("Database");
    for (QDomNode node : nodes) {

    }
}
