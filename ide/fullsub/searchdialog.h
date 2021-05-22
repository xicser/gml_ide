#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QWidget>
#include "fullsub/notepadtab.h"

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QWidget
{
    Q_OBJECT

public:
    explicit SearchDialog(NotePadTab *);
    ~SearchDialog();

private:
    Ui::SearchDialog *ui;
    NotePadTab *notePadTabActive;

private slots:
    void slotSearchForward();     //向前查找
    void slotSearchBackward();    //向后查找
    void slotReplace();           //替换
    void slotReplaceAll();        //替换所有
};

#endif // SEARCHDIALOG_H
