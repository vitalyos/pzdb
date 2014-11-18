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
    ui->databaseStructure->setContextMenuPolicy(Qt::CustomContextMenu);
    m_Righclick = new QMenu(ui->databaseStructure);
//    m_Action = new QAction("Drop table", m_Righclick);
//    ui->databaseStructure->addAction(m_Action);
//    ui->databaseStructure->addAction(new QAction("Drop Database", m_Righclick));
    QObject::connect(ui->databaseStructure, &QTreeView::customContextMenuRequested,
                     this, &PZDBMainWindow::onCustomContextMenu);
#ifdef SAVE
    BaseCatalogEntity dbs("Databases");
    DataBaseEntity * univ = new DataBaseEntity("University");
    DataBaseEntity * work = new DataBaseEntity("Work");
    DataBaseEntity * free = new DataBaseEntity("Freetime");
    QList<QStandardItem *> tableFields;
    tableFields << new FieldEntity ("userid", 1, 20, true)
                << new FieldEntity ("password", 2, 30, false)
                << new FieldEntity ("phone", 1, 15, false);
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

void PZDBMainWindow::on_actionDatabase_triggered()
{

}

void PZDBMainWindow::on_actionDatabase_2_triggered()
{
    DropDatabase *dd = new DropDatabase(this);
    dd->show();
}

void PZDBMainWindow::onCustomContextMenu(const QPoint &point)
{
    QModelIndex index = ui->databaseStructure->indexAt(point);
    qDebug () << "row:" << index.row() << "column:" << index.column();
    QAction * act = new QAction("Drop table", m_Righclick);
    m_Righclick->addAction(act);
    if (index.isValid()) {
        m_Righclick->exec(ui->databaseStructure->mapToGlobal(point));
    }
}
