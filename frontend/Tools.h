#ifndef TOOLS_H
#define TOOLS_H

#include <QString>
#include <QStringList>
#include <QPair>

#include "TableEntity.h"

class Tools
{
public:
     QPair<QString, QString> convertData(const TableEntity &table, const QStringList &data) const;
     QStringList restoreData (const TableEntity &table, const QString & data) const;
};

#endif // TOOLS_H
