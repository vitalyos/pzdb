#ifndef PZDBMAINWINDOW_H
#define PZDBMAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemModel>
#include <QFile>
#include <QDomDocument>
#include <QDebug>
#include <QWindow>
#include <QUiLoader>
#include "DropDatabase.h"

namespace Ui {
class PZDBMainWindow;
}

class PZDBMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PZDBMainWindow(QWidget *parent = 0);
    ~PZDBMainWindow();

private slots:
    void on_actionExit_triggered();

    void on_actionDatabase_triggered();

    void on_actionDatabase_2_triggered();

private:
    Ui::PZDBMainWindow *ui;
    QDomDocument _document;
    void loadFile (const QString &fname);

signals:
    void closeApplication(const int &status = 0);
};

#endif // PZDBMAINWINDOW_H
