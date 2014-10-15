#include "PZDBMainWindow.h"
#include "ui_PZDBMainWindow.h"
#include "XmlEditor.h"

PZDBMainWindow::PZDBMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PZDBMainWindow)
{
    ui->setupUi(this);
    loadFile("DataBases.xml");
    try {
        QAbstractItemModel *model = new DataBaseXmlModel (_document);
        ui->databaseStructure->setModel(model);
    } catch (std::exception *ex) {
        qDebug () << ex->what();
    }
    XmlEditor editor ("DataBases.xml");
//    editor.dropDatabase("Premium");
    editor.createDatabase("Zsolt");
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
        if (file->open(QIODevice::ReadOnly)) {
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
