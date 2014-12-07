#include "IndexingService.h"
#include "Tools.h"

IndexingService::IndexingService()
{
}

QHash<QString, QStringList> IndexingService::createInvertedIndex(const TableEntity &table, const int &fieldIndex)
{
    QHash<QString, QStringList> ret;
    QStringList list = m_MongoService.getAllRows(table.text());
    int primary = table.primaryIndex();
    for (QString data : list) {
        QStringList el  = Tools::restoreData(table, data);
        ret[el.at(fieldIndex)] << el.at(primary);
    }
    return ret;
}
