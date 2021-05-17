#ifndef PERFERENCEDIALOG_H
#define PERFERENCEDIALOG_H

#include <QDialog>
#include "ui_perferencedialog.h"
#include "config.h"
#include "notepad.h"

class PerferenceDialog: public QDialog, private Ui::PerferenceDialog
{
    Q_OBJECT
public:
    explicit PerferenceDialog(Config *config, QWidget *parent = 0);
    void closeEvent(QCloseEvent *e);        //用于窗口关闭
    ~PerferenceDialog();
signals:

public slots:
private slots:
    void accept();  //确认按钮单击时触发的槽
    void apply();   //应用按钮单击时触发的槽
private:
    Config *config; //配置
};

#endif // PERFERENCEDIALOG_H
