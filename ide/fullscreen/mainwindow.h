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

    //语言菜单
    QMenu         *menuLanguage;

    //编辑菜单
    QMenu          *menuEdit;
    QAction        *actionChangeSize;

    //选项菜单
    QMenu          *menuOpt;
    QAction        *actionAutoMergeNearGraphic, *actionOpenNtp, *actionCloseGraphic;

    //作图菜单
    QAction        *actionPaint;


    /* 工具栏相关 */
    QToolBar       *toolBar;                              //工具栏
    QToolButton    *toolBtnOpenFile;                      //打开文件按钮
    QToolButton    *toolBtnSaveAs;                        //另存为按钮
    QToolButton    *toolBtnUndo;                          //后退
    QToolButton    *toolBtnRedo;                          //前进
    QToolButton    *toolBtnZoomUp;                        //放大
    QToolButton    *toolBtnZoomDown;                      //缩小
    QToolButton    *toolBtnDispRestore;                   //显示恢复
    QToolButton    *toolBtnPicDrag;                       //图形拖动
    QToolButton    *toolBtnNormalOpt;                     //正常操作
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
