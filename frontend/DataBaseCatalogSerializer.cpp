#include "DataBaseCatalogSerializer.h"

DataBaseCatalogSerializer::DataBaseCatalogSerializer(const QString fileName)
    : m_Settings (fileName, QSettings::Format::NativeFormat)
{
}

BaseCatalogEntity DataBaseCatalogSerializer::load() const
{
    qDebug () << "load...";
    QVariant var=  m_Settings.value("main/catalog");
    qDebug () << var.canConvert<BaseCatalogEntity>();
    return qvariant_cast<BaseCatalogEntity>(var);
}

void DataBaseCatalogSerializer::save(const BaseCatalogEntity &ent)
{
    QVariant variant  = qVariantFromValue(ent);
    qDebug () << "save.." << ent.rowCount() << "elements";
    m_Settings.clear();
    m_Settings.sync();
    m_Settings.beginGroup("main");
    m_Settings.setValue("catalog", variant);
    m_Settings.endGroup();
    m_Settings.sync();
}
