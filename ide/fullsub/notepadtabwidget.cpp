#include "notepadtabwidget.h"

NotePadTabWidget::NotePadTabWidget(QWidget *parent) : QTabWidget(parent)
{

}

QSize NotePadTabWidget::sizeHint() const
{
    return QSize(200, 200); /* 在这里定义dock的初始大小 */
}
