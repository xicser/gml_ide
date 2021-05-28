#ifndef LOGTEXTEDIT_H
#define LOGTEXTEDIT_H

#include <QTextEdit>

class LogTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    LogTextEdit(QWidget *parent);
    QSize sizeHint() const;

    void clearLog(void);                //清空log显示
    void appendLine(QString line);      //追加一行显示
    void setText(QString text);         //设置显示内容
};

#endif // LOGTEXTEDIT_H
