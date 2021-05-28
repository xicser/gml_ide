#ifndef NOTEPADTAB_H
#define NOTEPADTAB_H

#include "qscitinlla/lexergml.h"
#include <Qsci/qsciscintilla.h>
#include <Qsci/qsciapis.h>


class NotePadTab : public QsciScintilla
{
    Q_OBJECT
public:
    NotePadTab(QWidget *parent);
    ~NotePadTab();

    QSize sizeHint() const;

    void setEditStatus(bool status);            //设置编辑状态
    bool getEditStatus(void);                   //获取编辑状态
    void setFilePath(QString filePath);         //设置文件路径
    QString getFilePath(void);                  //获取文件路径
    QString getFileName(void);                  //获取文件名称
    void setEncoding(QString);                  //设置编码格式
    QString getEncoding(void);                  //获取编码格式
    void setLexerFont(QFont);                   //设置显示字体
    QFont getLexerFont(void);                   //设置显示字体

private:
    bool    isEditing;              //表征当前文本是否处于编辑状态
    QString filePath;               //打开的文件路径
    QString fileName;               //打开的文件名称
    QString enCoding;               //编码格式(目前支持uft-8和gb2312)
    QFont   font;                   //显示字体

    LexerGML *textLexer;            //解析器
    QsciAPIs *apis;                 //代码提示

    void editorInit(void);          //编辑器初始化
    void addSelfDefineCueWord(QsciAPIs *apis);      //添加自定义提示词

public slots:
    void slotContentChanged(void);                  //文本内容改变时, 调用该槽发送signalContentHasChanged信号

signals:
    void signalContentHasChanged(NotePadTab *tab);  //文本内容改变时, 释放该信号

};

#endif // NOTEPADTABWIDGET_H
