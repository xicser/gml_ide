#include "notepadtab.h"
#include <QDebug>
#include <QFileInfo>
#include <QVBoxLayout>

NotePadTab::NotePadTab(QWidget *parent) : QsciScintilla(parent)
{
    //设置语法
    QsciLexerPython *textLexer = new QsciLexerPython;       //创建一个词法分析器
    this->setLexer(textLexer);                            //给QsciScintilla设置词法分析器

    //行号提示
    this->setMarginType(0,QsciScintilla::NumberMargin);   //设置编号为0的页边显示行号。
    this->setMarginLineNumbers(0, true);                  //对该页边启用行号
    this->setMarginWidth(0, 15);                          //设置页边宽度

    //代码提示
    QsciAPIs *apis = new QsciAPIs(textLexer);
    apis->add(QString("import"));
    apis->prepare();

    this->setAutoCompletionSource(QsciScintilla::AcsAll);   //设置源, 自动补全所有地方出现的
    this->setAutoCompletionCaseSensitivity(true);           //设置自动补全大小写敏感
    this->setAutoCompletionThreshold(3);                    //设置每输入3个字符就会出现自动补全的提示
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
