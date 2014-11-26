#include "PZDBMainWindow.h"
#include "ui_PZDBMainWindow.h"

#include <BaseCatalogEntity.h>

PZDBMainWindow::PZDBMainWindow(QStandardItemModel * model, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PZDBMainWindow)
{
    ui->setupUi(this);
    ui->databaseStructure->setModel(model);
    ui->databaseStructure->setContextMenuPolicy(Qt::CustomContextMenu);
    m_Righclick = new QMenu(ui->databaseStructure);
    QObject::connect(ui->databaseStructure, &QTreeView::customContextMenuRequested,
                     this, &PZDBMainWindow::onCustomContextMenu);
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
    QVariant content = index.data();
    if (content.canConvert<BaseCatalogEntity>()) {
        qDebug () << "nyert ugyunk van :*";
    }
    if (index.isValid()) {
        m_Righclick->exec(ui->databaseStructure->mapToGlobal(point));
    }
}
