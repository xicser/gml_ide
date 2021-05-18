#ifndef TREELAYERVIEW_H
#define TREELAYERVIEW_H

#include <QTreeView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QMouseEvent>
#include <QMenu>
#include <QDebug>

//树形结构一级结点
typedef struct {
    int layerId;
    QStandardItem *item;
    QList<QStandardItem *> subItemsList;
} TreeNodeFirst_t;

//树形结构叶子结点
typedef struct {
    int layerId;
    int itemId;
} TreeLeafNode_t;
Q_DECLARE_METATYPE(TreeLeafNode_t)

class TreeLayerView : public QTreeView
{
    Q_OBJECT
public:
    TreeLayerView(QWidget *parent);
    QSize sizeHint() const;

};

#endif // TREELAYERVIEW_H
