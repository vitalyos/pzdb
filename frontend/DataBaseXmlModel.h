#ifndef DATABASEXMLMODEL_H
#define DATABASEXMLMODEL_H

#include <QAbstractItemModel>
#include <QDomDocument>
#include "DomItem.h"

class DataBaseXmlModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit DataBaseXmlModel(QDomDocument document, QObject *parent = 0);
    ~DataBaseXmlModel();

    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

private:
    DomItem *rootItem;
    QDomDocument _document;


signals:

public slots:

};

#endif // DATABASEXMLMODEL_H
