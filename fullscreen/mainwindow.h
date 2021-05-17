#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow: public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget * = 0);
    ~MainWindow();

private:
    QTabWidget *tabWidget;                      //Tab栏

    QMenuBar *menuBar;                          //菜单栏
    QToolBar *topToolBar;                       //按钮工具栏
    QToolBar *buildToolBar;                     //编译构建工具栏

    QMenu *fileMenu;                            //文件菜单
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

    QMenu *editMenu;                            //编辑菜单
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

    QMenu *buildMenu;                           //构建菜单
    QAction *compileAct;                        //编译
    QAction *deployAct;                         //部署
    QAction *runAct;                            //运行

    QMenu *windowMenu;                          //窗口菜单
    QAction *nextAct;                           //下一个窗口
    QAction *previousAct;                       //上一个窗口
    QMenu *recentlyFilesMenu;                   //最近关闭的窗口
    QMenu *currentAllMenu;                      //当前所有窗口

    QMenu *helpMenu;                            //帮助菜单
    QAction *aboutAct;                          //关于本软件

    void init();                                //初始化
//    void closeEvent(QCloseEvent *);  //关闭事件
    void setupFileMenu();                       //文件菜单功能实现
    void setupEditMenu();                       //编辑菜单功能实现
    void setupBuildMenu();                      //构建菜单功能实现
    void setupWindowMenu();                     //窗口菜单功能实现
    void fillRecentFileActs();                  //填充recentFileActs
    void setupHelpMenu();                       //帮助菜单功能实现

    void setupFileActions();                    //文件菜单Action设置
    void setupEditActions();                    //编辑菜单Action设置
    void setupBuildActions();                   //构建菜单Action设置
    void setupWindowActions();                  //窗口菜单Action设置
    void setupHelpActions();                    //帮助Action设置

    void about();                               //关于本软件
};

#endif // MAINWINDOW_H
