#ifndef INDEXINGSERVICE_H
#define INDEXINGSERVICE_H

#include <QList>
#include <QPair>
#include "TableEntity.h"
#include "MongoService.h"

class IndexingService
{
public:
    IndexingService();
    QHash<QString, QStringList> createInvertedIndex (TableEntity * table, const int &fieldIndex);
private:
    MongoService m_MongoService;
};

#endif // INDEXINGSERVICE_H
