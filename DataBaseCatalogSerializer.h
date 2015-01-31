#ifndef DATABACECATALOGSERIALIZER_H
#define DATABACECATALOGSERIALIZER_H

#include <QSettings>
#include <QVariant>
#include <QDebug>

class DataBaseCatalogSerializer
{
public:
    DataBaseCatalogSerializer(const QString fileName);
//    BaseCatalogEntity load () const;
//    void save (const BaseCatalogEntity &ent);
private:
    QSettings m_Settings;
};

#endif // DATABACECATALOGSERIALIZER_H
