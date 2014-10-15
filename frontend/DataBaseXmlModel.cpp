#include "DataBaseXmlModel.h"

DataBaseXmlModel::DataBaseXmlModel(QDomDocument document, QObject *parent) :
    QAbstractItemModel(parent)
  , _document (document)
{
    rootItem = new DomItem (_document, 0);
}

DataBaseXmlModel::~DataBaseXmlModel()
 {
     delete rootItem;
 }

 int DataBaseXmlModel::columnCount(const QModelIndex &parent) const
 {
     return 3;
 }

 QVariant DataBaseXmlModel::data(const QModelIndex &index, int role) const
 {
     if (!index.isValid())
         return QVariant();

     if (role != Qt::DisplayRole)
         return QVariant();

     DomItem *item = static_cast<DomItem*>(index.internalPointer());

     QDomNode node = item->node();
     QStringList attributes;
     QDomNamedNodeMap attributeMap = node.attributes();

     switch (index.column()) {
         case 0:
             return node.nodeName();
         case 1:
             for (int i = 0; i < attributeMap.count(); ++i) {
                 QDomNode attribute = attributeMap.item(i);
                 attributes << attribute.nodeName() + "=\""
                               +attribute.nodeValue() + "\"";
             }
             return attributes.join(" ");
         case 2:
             return node.nodeValue().split("\n").join(" ");
         default:
             return QVariant();
     }
 }

 Qt::ItemFlags DataBaseXmlModel::flags(const QModelIndex &index) const
 {
     if (!index.isValid())
         return 0;

     return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
 }

 QVariant DataBaseXmlModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
 {
     if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
         switch (section) {
             case 0:
                 return tr("Name");
             case 1:
                 return tr("Attributes");
             case 2:
                 return tr("Value");
             default:
                 return QVariant();
         }
     }

     return QVariant();
 }

 QModelIndex DataBaseXmlModel::index(int row, int column, const QModelIndex &parent)
             const
 {
     if (!hasIndex(row, column, parent))
         return QModelIndex();

     DomItem *parentItem;

     if (!parent.isValid())
         parentItem = rootItem;
     else
         parentItem = static_cast<DomItem*>(parent.internalPointer());

     DomItem *childItem = parentItem->child(row);
     if (childItem)
         return createIndex(row, column, childItem);
     else
         return QModelIndex();
 }

 QModelIndex DataBaseXmlModel::parent(const QModelIndex &child) const
 {
     if (!child.isValid())
         return QModelIndex();

     DomItem *childItem = static_cast<DomItem*>(child.internalPointer());
     DomItem *parentItem = childItem->parent();

     if (!parentItem || parentItem == rootItem)
         return QModelIndex();

     return createIndex(parentItem->row(), 0, parentItem);
 }

 int DataBaseXmlModel::rowCount(const QModelIndex &parent) const
 {
     if (parent.column() > 0)
         return 0;

     DomItem *parentItem;

     if (!parent.isValid())
         parentItem = rootItem;
     else
         parentItem = static_cast<DomItem*>(parent.internalPointer());

     return parentItem->node().childNodes().count();
 }
