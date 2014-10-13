#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug ("Hello PZDB");
    return a.exec();
}
