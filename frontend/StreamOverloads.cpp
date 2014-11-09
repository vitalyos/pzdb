#include "StreamOverloads.h"

QDataStream& operator << (QDataStream &out, const QList<QString> &strings)
{
    out << strings.size();
    for (QString string : strings) {
        out << string;
    }
    return out;
}

QDataStream& operator >> (QDataStream &in, QList<QString> &strings)
{
    strings.clear();
    quint8 size;
    in >> size;
    QString string;
    for (quint8 i = 0; i < size; ++i) {
        in >> string;
        strings.append(string);
    }
    return in;
}
