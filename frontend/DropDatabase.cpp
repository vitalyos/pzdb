#include "DropDatabase.h"
#include "ui_DropDatabase.h"

DropDatabase::DropDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DropDatabase)
{
    ui->setupUi(this);
}

DropDatabase::~DropDatabase()
{
    delete ui;
}

void DropDatabase::on_deleteButton_clicked()
{
    qDebug () << "Drop db";
}
