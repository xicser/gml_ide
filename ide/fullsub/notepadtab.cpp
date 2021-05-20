#include "notepadtab.h"
#include <QDebug>
#include <QFileInfo>

NotePadTab::NotePadTab(QWidget *parent) : QTextEdit(parent)
{



}

QSize NotePadTab::sizeHint() const
{
    return QSize(200, 200); /* 在这里定义dock的初始大小 */
}

/* 设置编辑状态 */
void NotePadTab::setEditStatus(bool status)
{
    this->isEditing = status;
}

/* 获取编辑状态 */
bool NotePadTab::getEditStatus(void)
{
    return this->isEditing;
}

/* 设置文件路径 */
void NotePadTab::setFilePath(QString filePath)
{
    this->filePath = filePath;

    //获取文件名
    QFileInfo info(filePath);
    this->fileName = info.fileName();
}

/* 获取文件路径 */
QString NotePadTab::getFilePath(void)
{
    return this->filePath;
}

/* 获取文件名称 */
QString NotePadTab::getFileName(void)
{
    return this->fileName;
}

/* 文本内容改变时, 调用该槽发送signalContentHasChanged信号 */
void NotePadTab::slotContentChanged(void)
{
    this->isEditing = true;
    emit signalContentHasChanged(this);
}
