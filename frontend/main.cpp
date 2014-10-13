#include "PZDBMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PZDBMainWindow w;
    w.show();

    return a.exec();
}
