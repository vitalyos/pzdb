#ifndef DROPDATABASE_H
#define DROPDATABASE_H

#include <QDialog>
#include <QDebug>
#include <QAbstractButton>
#include <iostream>

namespace Ui {
class DropDatabase;
}

class DropDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit DropDatabase(QWidget *parent = 0);
    ~DropDatabase();

private slots:
    void on_deleteButton_clicked();

private:
    Ui::DropDatabase *ui;
};

#endif // DROPDATABASE_H
