#include "logtextedit.h"

LogTextEdit::LogTextEdit(QWidget *parent) : QTextEdit(parent)
{

}

QSize LogTextEdit::sizeHint() const
{
    return QSize(200, 200); /* 在这里定义dock的初始大小 */
}

