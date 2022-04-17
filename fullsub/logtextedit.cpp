#include "logtextedit.h"

LogTextEdit::LogTextEdit(QWidget *parent) : QTextEdit(parent)
{
    QFont font("Courier New", 12, QFont::Normal);
    this->setFont(font);
    this->setReadOnly(true);
}

QSize LogTextEdit::sizeHint() const
{
    return QSize(200, 200); /* 在这里定义dock的初始大小 */
}

/* 清空log显示 */
void LogTextEdit::clearLog(void)
{
    this->setText("");
}

/* 追加一行显示 */
void LogTextEdit::appendLine(QString line)
{
    this->appendLine(line);
}

/* 设置显示内容 */
void LogTextEdit::setText(QString text)
{
    this->QTextEdit::setText(text);
}
