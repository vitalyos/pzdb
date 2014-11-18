#ifndef PZDBMAINWINDOW_H
#define PZDBMAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QFile>
#include <QDomDocument>
#include <QDebug>
#include <QWindow>
#include <QUiLoader>
#include <QMenu>
#include <QAction>
#include <QObject>
#include <QPoint>
#include "DropDatabase.h"

namespace Ui {
class PZDBMainWindow;
}

class PZDBMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PZDBMainWindow(QStandardItemModel *model, QWidget *parent = 0);
    ~PZDBMainWindow();

private slots:
    void on_actionExit_triggered();

    void on_actionDatabase_triggered();

    void on_actionDatabase_2_triggered();

    void onCustomContextMenu (const QPoint &point);

private:
    Ui::PZDBMainWindow *ui;

    QMenu * m_Righclick;
    QAction * m_Action;
signals:
    void closeApplication(const int &status = 0);
};

#endif // PZDBMAINWINDOW_H
