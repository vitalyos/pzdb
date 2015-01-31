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

signals:
    void databeseCatalogLoaded ();
};

#endif // PZDBCONTROLLER_H
