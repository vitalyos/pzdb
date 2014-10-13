#include "PZDBMainWindow.h"
#include "ui_PZDBMainWindow.h"

PZDBMainWindow::PZDBMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PZDBMainWindow)
{
    ui->setupUi(this);
}

PZDBMainWindow::~PZDBMainWindow()
{
    delete ui;
}
