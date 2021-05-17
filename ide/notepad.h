#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QPlainTextEdit>
#include <QTextBlock>
#include "config.h"

QT_BEGIN_NAMESPACE

QT_FORWARD_DECLARE_CLASS(QEvent)
QT_FORWARD_DECLARE_CLASS (QPaintEvent)
QT_FORWARD_DECLARE_CLASS (QKeyEvent)
QT_FORWARD_DECLARE_CLASS (QMouseEvent)
QT_FORWARD_DECLARE_CLASS (QResizeEvent)
QT_FORWARD_DECLARE_CLASS (QContextMenuEvent)
QT_FORWARD_DECLARE_CLASS (QAction)

QT_END_NAMESPACE

#define FOLDBOXRECT(cy) QRect(lineNumWidth + foldBoxIndent, cy - foldBoxWidth / 2, foldBoxWidth, foldBoxWidth)
#define FULLRESIZE      resizeEvent(new QResizeEvent(QSize(0, 0), size()))
#define FONTWIDTH       fontMetrics().width(QLatin1Char('X'))

class NotePad: public QPlainTextEdit
{
    Q_OBJECT

public:
    //block 类型
    enum BlockState
    {
        End = 1,
        Begin = 2,
        String = 4,
        Comment = 8,
        Nested = 16,
        Folded = 32,
        Error = 64,
        Rehighligh = 128,
        Empty = -1
    };

    const static int StateShift = 8;
public:
    NotePad(Config *, QWidget *parent = 0);
    ~NotePad();

public slots:
    int search(QString, bool, bool, bool); //查找
    void replace(QString, QString, bool, bool, bool);   //替换
    void replaceAll(QString, QString, bool, bool);  //替换所有
    void gotoLine(int lineNumber);  //转到行
private slots:
    void deleteSelected()
    {	textCursor().removeSelectedText();}    //删除所选内容
    void toUpperCase()
    {
        convertCase();
    }    //转为大写
    void toLowerCase()
    {
        convertCase(false);
    }   //转为小写

    void blockCountChanged(int count)
    {
        lineNumDigits = qMax(2, QString::number(count).length());
    } //文本的段落数发生改变时触发的槽
    void contentsChange(int, int, int); //文本内容发生改变触发的槽
    void ensureCursorVisible(); //光标可见

    void reconfig(int = (Config::Init | Config::Editor));   //重新配置

private:
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);

    void keyPressEvent(QKeyEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void contextMenuEvent(QContextMenuEvent *);

    bool eventFilter(QObject *, QEvent *);
    void extraAreaPaintEvent();
    void extraAreaMouseEvent(QMouseEvent *);

    int setBlockState(QTextBlock&); //设置段落状态
    QTextBlock findBlockByY(int); //查找段落

    void convertCase(bool toUpper = true)
    {
        textCursor().insertText(
                    toUpper ?
                        textCursor().selectedText().toUpper() :
                        textCursor().selectedText().toLower());
    }

    QTextBlock pointedBlock;

    QWidget *extraArea;   //显示行号的区域

    int lineNumDigits;   //行号位数
    int lineNumWidth;    //行号的宽度

    int foldBoxWidth;
    int foldBoxIndent;
    int foldBoxLength;

    Config *config;
};

#endif // NOTEPAD_H
