#include "PZDBMainWindow.h"
#include "ui_PZDBMainWindow.h"
#include "BaseCatalogEntity.h"
#include "DataBaseCatalogSerializer.h"
#include <QStandardItemModel>
#include <QList>

//#define SAVE true

PZDBMainWindow::PZDBMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PZDBMainWindow)
{
    ui->setupUi(this);
    QStandardItemModel * model = new QStandardItemModel();
    DataBaseCatalogSerializer ser ("catalog.ini");
    ui->databaseStructure->setModel(model);
#ifdef SAVE
    BaseCatalogEntity dbs("Databases");
    DataBaseEntity * univ = new DataBaseEntity("University");
    DataBaseEntity * work = new DataBaseEntity("Work");
    DataBaseEntity * free = new DataBaseEntity("Freetime");
    QList<QStandardItem *> tableFields;
    tableFields << new FieldEntity("userid", 1) << new FieldEntity ("password", 2);
    TableEntity *table = new TableEntity ("users", tableFields);
    univ->addTable(table);
    dbs.addDatabase(univ);
    dbs.addDatabase(work);
    dbs.addDatabase(free);
    ser.save(dbs);
#else
    BaseCatalogEntity dbs = ser.load();
#endif
    model->appendRow (new BaseCatalogEntity(dbs));
}

PZDBMainWindow::~PZDBMainWindow()
{
    delete ui;
}

void PZDBMainWindow::on_actionExit_triggered()
{
    emit closeApplication();
}

void PZDBMainWindow::loadFile(const QString &fname)
{
    try {
        QFile *file = new QFile(fname);
        if (file->open(QIODevice::ReadOnly | QIODevice::Text)) {
            if (!_document.setContent(file)) {
                qDebug () << "Error at document loading";
            }
        } else {
            qDebug () << "Error at file loading";
        }

        file->close();
        delete file;
        qDebug () << "ok";
    } catch (std::exception &ex) {
        qDebug () << ex.what();
    }
}

void PZDBMainWindow::on_actionDatabase_triggered()
{

}

void PZDBMainWindow::on_actionDatabase_2_triggered()
{
    DropDatabase *dd = new DropDatabase(this);
    dd->show();
}
