#ifndef TOOLS_H
#define TOOLS_H

#include <QString>
#include <QStringList>
#include <QPair>

#include "TableEntity.h"

class Tools
{
public:
     static QPair<QString, QString> convertData(TableEntity * table, const QStringList &data);
     static QStringList restoreData (TableEntity * table, const QString & data);
private:
     static QString clearData (const QString &aData);
};

#endif // TOOLS_H
