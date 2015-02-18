#include "DataBaseCatalogSerializer.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>

QString DataBaseCatalogSerializer::filename = "/home/zsvitalyos/.pzdb/catalog.json";

//BaseCatalogEntity DataBaseCatalogSerializer::load() const
//{
//    qDebug () << "load...";
//    QVariant var=  m_Settings.value("main/catalog");
//    qDebug () << var.canConvert<BaseCatalogEntity>();
//    return qvariant_cast<BaseCatalogEntity>(var);
//}

//void DataBaseCatalogSerializer::save(const BaseCatalogEntity &ent)
//{
//    QVariant variant  = qVariantFromValue(ent);
//    qDebug () << "save.." << ent.rowCount() << "elements";
//    m_Settings.clear();
//    m_Settings.sync();
//    m_Settings.beginGroup("main");
//    m_Settings.setValue("catalog", variant);
//    m_Settings.endGroup();
//    m_Settings.sync();
//}

void DataBaseCatalogSerializer::save (QList<DataBaseEntity> *aList)
{
    QJsonArray cat;
    for (int i = 0; i < aList->size (); ++i) {
        QJsonObject aDB;
        QJsonArray tabs;
        for (int t = 0; t < aList->at (i).tables ().size (); ++t) {
            QJsonObject tab;
            QJsonArray fields;
            foreach (FieldEntity *f, aList->at (i).tables ().at (t)->flist ()) {
                QJsonObject aField;
                aField.insert ("fname", f->name ());
                aField.insert ("ftype", f->fieldType ());
                aField.insert ("flength", (int)f->length ());
                aField.insert ("fprim", f->primary ());
                aField.insert ("frt", f->refTableName ());
                aField.insert ("frf", f->refFieldName ());
                aField.insert ("findexed", f->indexed ());
                fields << aField;
            }
            tab.insert ("tname", aList->at (i).tables ().at (t)->name ());
            tab.insert ("fields", fields);
            tabs << tab;
        }
        aDB.insert ("dbname", QJsonValue(aList->at (i).name ()));
        aDB.insert ("tables", tabs);
        cat << aDB;
        qDebug () << cat;
        QJsonDocument doc(cat);
        QSettings file(filename, QSettings::NativeFormat);
        file.setValue ("catalog", doc.toBinaryData ());
        file.sync ();
    }
}
