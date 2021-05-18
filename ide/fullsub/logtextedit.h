#ifndef LOGTEXTEDIT_H
#define LOGTEXTEDIT_H

#include <QTextEdit>

class LogTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    LogTextEdit(QWidget *parent);
    QSize sizeHint() const;
};

#endif // LOGTEXTEDIT_H
