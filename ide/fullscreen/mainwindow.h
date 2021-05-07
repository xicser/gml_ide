#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QResizeEvent>
#include <QCloseEvent>
#include <QDesktopWidget>
#include <QApplication>
#include <QMenuBar>
#include <QDebug>
#include <QToolButton>
#include <QToolBar>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent* event);                      //变换事件
    void resizeEvent(QResizeEvent *);                     //重画大小事件

private:
    /* 尺寸相关 */
    int    screenXSize, screenYSize;             //屏幕可用尺寸
    int    fontSize;                             //字体大小
    int    scrollBarWidth;                       //滚动条宽度
    int    menuBarHeight;                        //菜单栏高度
    int    toolBarHeight;                        //工具栏高度

    /* 菜单栏相关 */
    QMenuBar       *menuBar;                              //菜单栏

    //文件菜单
    QMenu         *menuFile;
    QAction       *actionNew, *actionOpen, *actionSave, *actionSaveAs, *actionExit;

    //编辑菜单
    QMenu         *menuEdit;
    QAction       *actionUndo, *actionRedo, *actionCut, *actionCopy, *actionPaste;
    QMenu         *menuEncoding;
    QAction       *actionUTF8, *actionGB2312;

    //窗口菜单
    QMenu          *menuWindow;
    QAction        *actionClose, *actionCloseAll, *actionNext, *actionPrev;

    //帮助菜单
    QMenu          *MenuHelp;
    QAction        *actionAbout;


    /* 工具栏相关 */
    QToolBar       *toolBar;                              //工具栏
    QToolButton    *toolBtnOpenFile;                      //打开文件按钮
    QToolButton    *toolBtnSaveAs;                        //另存为按钮
    QToolButton    *toolBtnUndo;                          //撤销
    QToolButton    *toolBtnRedo;                          //重做
    QToolButton    *toolBtnBuild;                         //构建
    QToolButton    *toolBtnRun;                           //运行
    QToolButton    *toolBtnAbout;                         //关于

    /* 初始化相关 */
    void dataInit(void);                         //数据初始化
    void mainWindowInit(void);                   //主窗口初始化
    void menuBarInit(void);                      //菜单栏初始化
    void toolBarInit(void);                      //工具栏初始化
    void moveToolBarPosition(void);              //移动工具栏位置

    /* 标题栏与窗口放缩相关 */
    void changeControllerSize(QSize size);       //改变控件大小


private slots:

};

#endif // MAINWINDOW_H
