#ifndef STREAMOVERLOADS_H
#define STREAMOVERLOADS_H
#include <QList>
#include <QDataStream>
#include <QString>
#include <QDebug>

QDataStream& operator << (QDataStream &out, const QList<QString> &strings);
QDataStream& operator >> (QDataStream &in, QList<QString> &strings);

#endif // STREAMOVERLOADS_H
