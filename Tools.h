#ifndef TOOLS_H
#define TOOLS_H

#include <QString>
#include <QStringList>
#include <QPair>

#include "TableEntity.h"

class Tools
{
public:
     static QPair<QString, QString> convertData(const TableEntity &table, const QStringList &data);
     QStringList restoreData (const TableEntity &table, const QString & data);
};

#endif // TOOLS_H