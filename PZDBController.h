#ifndef PZDBCONTROLLER_H
#define PZDBCONTROLLER_H

#include <QObject>

class MongoService;

class PZDBController
        : public QObject
{
    Q_OBJECT
public:
    PZDBController(QObject * parentObject = 0);
    ~PZDBController();
private:
//    MongoService * m_MongoService;

public slots:
    void loadDatabaseCatalog ();
    void deleteRowByKey (const QString & aKey);
    void insertRow(const QStringList & aDataRow);
signals:
    void databeseCatalogLoaded ();
    void deleteRow(const QString & aKey);
    void rowInserted(const QStringList & aDataRow);
};

#endif // PZDBCONTROLLER_H
