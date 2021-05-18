#include "treelayerview.h"

TreeLayerView::TreeLayerView(QWidget *parent) : QTreeView(parent)
{

}

QSize TreeLayerView::sizeHint() const
{
    return QSize(200, 200); /* 在这里定义dock的初始大小 */
}
