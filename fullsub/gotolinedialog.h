#ifndef GOTOLINEDIALOG_H
#define GOTOLINEDIALOG_H

#include <QWidget>
#include "fullsub/notepadtab.h"

namespace Ui {
class GotolineDialog;
}

class GotolineDialog : public QWidget
{
    Q_OBJECT

public:
    GotolineDialog(NotePadTab *notePadTabActive);
    ~GotolineDialog();

private:
    Ui::GotolineDialog *ui;
    NotePadTab *notePadTabActive;

signals:
    void signalGoToLineDone();              //跳转执行结束信号

private slots:
    void slotGoBtnClicked();                //go按钮按下
};

#endif // GOTOLINEDIALOG_H
