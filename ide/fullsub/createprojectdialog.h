#ifndef CREATEPROJECTDIALOG_H
#define CREATEPROJECTDIALOG_H

#include <QWidget>

namespace Ui {
class CreateProjectDialog;
}

class CreateProjectDialog : public QWidget
{
    Q_OBJECT

public:
     CreateProjectDialog();
    ~CreateProjectDialog();

     QString getProjectFilePath(void);      //获取工程文件路径
     QString getProjectFileName(void);      //获取工程文件名称

private:
    Ui::CreateProjectDialog *ui;
    QString proPath, proName;               //工程路径和名称

private slots:
    void slotChoosePathBtnClicked();
    void slotConfirmBtnClicked();
    void slotCancelBtnClicked();

signals:
    void signalConfirmBtnClicked(void);
};

#endif // CREATEPROJECTDIALOG_H
