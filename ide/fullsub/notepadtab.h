#ifndef NOTEPADTAB_H
#define NOTEPADTAB_H

#include <QTextEdit>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexerpython.h>
#include <Qsci/qsciapis.h>

class NotePadTab : public QsciScintilla
{
    Q_OBJECT
public:
    NotePadTab(QWidget *parent);
    QSize sizeHint() const;

    void setEditStatus(bool status);            //设置编辑状态
    bool getEditStatus(void);                   //获取编辑状态
    void setFilePath(QString filePath);         //设置文件路径
    QString getFilePath(void);                  //获取文件路径
    QString getFileName(void);                  //获取文件名称

private:
    bool isEditing;                 //表征当前文本是否处于编辑状态
    QString filePath;               //打开的文件路径
    QString fileName;               //打开的文件名称

public slots:
    void slotContentChanged(void);                  //文本内容改变时, 调用该槽发送signalContentHasChanged信号

signals:
    void signalContentHasChanged(NotePadTab *tab);  //文本内容改变时, 释放该信号

};

#endif // NOTEPADTABWIDGET_H
