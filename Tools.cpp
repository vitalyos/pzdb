#include "Tools.h"

QPair<QString, QString> Tools::convertData(const TableEntity &table, const QStringList &data)
{
    QString key;
    QString value;
    QList<FieldEntity> fs = table.fields();

    if (data.size() !=  fs.size()) {
        qDebug () << "table !~ data";
    }

    int idx = 0;
    for (QString d : data) {
        FieldEntity fe = fs.at(idx);
        QString longString = d.leftJustified(fe.length(), ' ');
        if (fe.primary()) {
            key.append(longString);
        }
        value.append(longString);
        ++idx;
    }
    return QPair<QString, QString>(key, value);
}

QStringList Tools::restoreData(const TableEntity &table, const QString &data)
{
    QStringList retList;
    QList<FieldEntity> fs = table.fields();
    int from = 0;

    for (FieldEntity fe : fs) {
        int length = fe.length();
        retList << data.mid(from, length);
        from += length;
    }
    return retList;
}
