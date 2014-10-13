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

private:
    Ui::PZDBMainWindow *ui;
};

#endif // PZDBMAINWINDOW_H
