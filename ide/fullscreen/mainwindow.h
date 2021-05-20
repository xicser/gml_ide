#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QPrinter>
#include <QTabWidget>
#include <QStatusBar>
#include <QCloseEvent>
#include "fullsub/treelayerview.h"
#include "fullsub/logtextedit.h"
#include "fullsub/notepadtab.h"

class MainWindow: public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget * = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *);

private:
    QMenuBar *menuBar;                          //菜单栏
    QToolBar *topToolBar;                       //按钮工具栏
    QToolBar *buildToolBar;                     //编译构建工具栏
    QStatusBar *statusBar;                      //状态栏

    QMenu   *fileMenu;                          //文件菜单
    QAction *openAct;                           //打开文件
    QAction *newAct;                            //新建文件
    QAction *saveAct;                           //保存文件
    QAction *saveAsAct;                         //文件另存为
    QAction *saveAllAct;                        //保存所有
    QAction *printAct;                          //打印
    QAction *printPreviewAct;                   //打印预览
    QAction *exportPdfAct;                      //导出成PDF
    QAction *closeAct;                          //关闭文件
    QAction *closeAllAct;                       //关闭所有文件
    QAction *exitAct;                           //退出

    QMenu   *editMenu;                          //编辑菜单
    QAction *copyAct;                           //复制
    QAction *cutAct;                            //剪切
    QAction *pasteAct;                          //粘贴
    QAction *undoAct;                           //撤销
    QAction *redoAct;                           //重做
    QAction *selectAllAct;                      //全选
    QAction *upperCaseAct;                      //转换为大写
    QAction *lowerCaseAct;                      //转换为小写
    QAction *findAct;                           //查找和替换
    QAction *gotoLineAct;                       //转到行
    QAction *preferenceAct;                     //首选项

    QMenu   *buildMenu;                         //构建菜单
    QAction *compileAct;                        //编译
    QAction *deployAct;                         //部署
    QAction *runAct;                            //运行

    QMenu   *windowMenu;                        //窗口菜单
    QAction *nextAct;                           //下一个窗口
    QAction *previousAct;                       //上一个窗口
    QMenu   *recentlyFilesMenu;                 //最近关闭的窗口
    QMenu   *currentAllMenu;                    //当前所有窗口

    QMenu   *helpMenu;                          //帮助菜单
    QAction *aboutAct;                          //关于本软件

    QDockWidget   *treeDirDock;                 //树文件目录停靠
    TreeLayerView *treeDirView;                 //树文件目录结构
    QDockWidget   *logDock;                     //log输出停靠
    LogTextEdit   *logTextEdit;                 //log输出文本框
    QTabWidget    *tabWidget;                   //文本Tab标签页

    void init();                                //初始化
    void setupFileMenu();                       //文件菜单功能实现
    void setupEditMenu();                       //编辑菜单功能实现
    void setupBuildMenu();                      //构建菜单功能实现
    void setupWindowMenu();                     //窗口菜单功能实现
    void setupHelpMenu();                       //帮助菜单功能实现
    void setupFileActions();                    //文件菜单Action设置
    void setupEditActions();                    //编辑菜单Action设置
    void setupBuildActions();                   //构建菜单Action设置
    void setupWindowActions();                  //窗口菜单Action设置
    void setupHelpActions();                    //帮助菜单Action设置

    //每个tab的信息
    typedef struct {
        QString filePath;                       //打开的文件路径
        NotePadTab *notePadTab;                 //记事本指针
    } Tab_Info_t;
    QList<Tab_Info_t> tabInfoList;              //打开的tab信息list

private slots:
    void openFile();                            //打开文件
    void newFile();                             //新建文件
    void fileSave();                            //保存文件
    void fileSaveAs();                          //文件另存为
    void fileSaveAll();                         //保存所有文件
    void filePrint();                           //打印文件
    void filePrintPreview();                    //打印预览
    void filePrintPdf();                        //输出成PDF
    void printPreview(QPrinter *);              //打印预览子函数
    void fileClose();                           //关闭文件
    bool fileCloseAll();                        //关闭所有文件
    void closeWindow();                         //关闭窗口

    void undo();                                //撤销
    void redo();                                //重做
    void cut();                                 //剪切
    void copy();                                //复制
    void paste();                               //粘贴
    void jumpLine();                            //转到行
    void search();                              //查找

    void nextTab();                             //上一个tab
    void prevTab();                             //下一个tab

    void about();                               //关于本软件

public slots:
    void slotNotePadContentChanged(NotePadTab *notePadTab);     //接收某个notePadTab内容改变的槽
};

#endif // MAINWINDOW_H
