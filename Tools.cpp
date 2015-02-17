#include "Tools.h"

QPair<QString, QString> Tools::convertData(TableEntity * table, const QStringList &data)
{
    QString key;
    QString value;
    QList<FieldEntity*> fs = table->flist ();

    if (data.size() !=  fs.size()) {
        qDebug () << "table !~ data";
    }

    int idx = 0;
//    for (QString d : data) {
    foreach (QString d, data) {
        FieldEntity *fe = fs.at(idx);
        QString longString = d.leftJustified(fe->length(), ' ');
        if (fe->primary()) {
            key.append(longString);
        }
        value.append(longString);
        ++idx;
    }
    return QPair<QString, QString>(key, value);
}

QStringList Tools::restoreData(TableEntity *table, const QString &data)
{
    QStringList retList;
    QList<FieldEntity*> fs = table->flist ();
    int from = 0;

//    for (FieldEntity fe : fs) {
    foreach (FieldEntity *fe, fs) {
        int length = fe->length();
        QString columnData = data.mid(from, length);
        retList <<  clearData (columnData);
        from += length;
    }
//    qDebug () << retList;
    return retList;
}

QString Tools::clearData (const QString &aData)
{
    int idx = aData.length () - 1;
    for (; idx >= 0; --idx) {
        if (aData.at (idx) != ' ') {
            break;
        }
    }
    return aData.mid (0, idx + 1);
}
