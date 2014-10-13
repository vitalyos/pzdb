#include "PZDBMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PZDBMainWindow w;
    w.show();

    QObject::connect(&w, &PZDBMainWindow::closeApplication, &a, QApplication::exit);

    return a.exec();
}
