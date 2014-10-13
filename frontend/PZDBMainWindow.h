#ifndef PZDBMAINWINDOW_H
#define PZDBMAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::PZDBMainWindow *ui;

signals:
    void closeApplication(const int &status = 0);
};

#endif // PZDBMAINWINDOW_H
