#include "DataBaseCatalogSerializer.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>

QString DataBaseCatalogSerializer::filename = "/home/zsvitalyos/.pzdb/catalog.json";

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
        file.setValue ("cat/catalog", doc.toJson ());
        file.sync ();
    }
}

QList<DataBaseEntity> DataBaseCatalogSerializer::load ()
{
    QSettings file(filename, QSettings::NativeFormat);
    QList<DataBaseEntity> cat;
    QJsonDocument doc = QJsonDocument::fromJson (file.value ("cat/catalog").toByteArray ());
    QJsonArray dbs = doc.array ();
    foreach (const QJsonValue &o, doc.array ()) {
        DataBaseEntity db(o.toObject ().value ("dbname").toString ());
        QJsonArray ts = o.toObject ().value ("tables").toArray ();
        QList<TableEntity*> tables;
        foreach (const QJsonValue &at, ts) {
            TableEntity * t = new TableEntity;
            QJsonArray fj = at.toObject ().value ("fields").toArray ();
            QList<FieldEntity*> fields;
            foreach (const QJsonValue &fval, fj) {
                FieldEntity *field = new FieldEntity;
                QJsonObject o = fval.toObject ();
                field->setName (o.value ("fname").toString ());
                field->setFieldType (o.value ("ftype").toInt ());
                field->setLength (o.value ("flength").toInt ());
                field->setPrimary (o.value ("fprim").toBool ());
                field->setRefTableName (o.value ("frt").toString ());
                field->setRefFieldName (o.value ("frt").toString ());
                field->setIndexed (o.value ("findexed").toBool ());
                fields << field;
            }
            t->setName (at.toObject ().value ("tname").toString ());
            t->setFields (fields);
            tables << t;
        }
        db.setTables (tables);
        cat << db;
    }
    return cat;
}
