#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QTabWidget>
#include <QStatusBar>
#include <QCloseEvent>
#include <QActionGroup>
#include "database/gmldatabase.h"

#include "fullsub/logtextedit.h"
#include "fullsub/notepadtab.h"
#include "fullsub/searchdialog.h"
#include "fullsub/gotolinedialog.h"
#include "fullsub/createprojectdialog.h"

class ProjView;
class MainWindow: public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget * = 0);
    ~MainWindow();

    bool getHasOpenProj();                      //获取hasOpenProj

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
    QAction *newProjAct;                        //新建工程
    QAction *openProjAct;                       //打开工程
    QAction *closeProjAct;                      //关闭工程
    QAction *saveAct;                           //保存文件
    QAction *saveAsAct;                         //文件另存为
    QAction *saveAllAct;                        //保存所有
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
    QAction *findAct;                           //查找
    QAction *gotoLineAct;                       //转到行
    QAction *preferenceAct;                     //首选项

    QMenu   *formatMenu;                        //文本格式菜单
    QAction *fontAct;                           //字体选择
    QMenu   *enCodingMenu;                      //字符编码格式子菜单
    QAction *enCodingUTF8Act;                   //UTF-8
    QAction *enCodingGB2312Act;                 //GB2312

    QMenu   *buildMenu;                         //构建菜单
    QAction *compileAct;                        //编译
    QAction *deployAct;                         //部署
    QAction *runAct;                            //运行

    QMenu   *windowMenu;                        //窗口菜单
    QAction *nextAct;                           //下一个窗口
    QAction *previousAct;                       //上一个窗口
    QMenu   *recentlyFilesMenu;                 //最近使用过文件的窗口
    QAction *clearRecentlyAct;                  //清除最近使用过的文件
    QMenu   *currentWindowsMenu;                //当前所有tab窗口
    QActionGroup *currentWindowsActionGrp;      //Window Menu中Current Windows子Menu里的Action组
    QActionGroup *recentlyFilesActionGrp;       //Window Menu中Recently Files子Menu里的Action组

    QMenu   *helpMenu;                          //帮助菜单
    QAction *aboutAct;                          //关于本软件

    QMenu   *menuRightBtnProjTree;              //工程栏右键菜单
    QAction *addNewFileAct;                     //添加新文件
    QAction *addExistingFileAct;                //添加现有文件

    QDockWidget   *projViewDock;                //工程树结构停靠
    ProjView      *projView;                    //工程树结构
    QDockWidget   *logDock;                     //log输出停靠
    LogTextEdit   *logTextEdit;                 //log输出文本框
    QTabWidget    *tabWidget;                   //文本Tab标签页

    void init();                                //初始化
    void setupFileMenu();                       //文件菜单功能实现
    void setupEditMenu();                       //编辑菜单功能实现
    void setupFormatMenu();                     //格式菜单功能实现
    void setupBuildMenu();                      //构建菜单功能实现
    void setupWindowMenu();                     //窗口菜单功能实现
    void setupHelpMenu();                       //帮助菜单功能实现
    void setupProjTree();                       //工程栏右键菜单功能实现
    void setupFileActions();                    //文件菜单Action设置
    void setupEditActions();                    //编辑菜单Action设置
    void setupFormatActions();                  //格式菜单Action设置
    void setupBuildActions();                   //构建菜单Action设置
    void setupWindowActions();                  //窗口菜单Action设置
    void setupHelpActions();                    //帮助菜单Action设置
    void setupProjTreeActions();                //工程栏右键菜单Action设置

    SearchDialog *searchDialog;                 //查找/替换子窗口
    GotolineDialog *gotolineDialog;             //跳转到行子窗口
    CreateProjectDialog *createProjectDialog;   //创建工程子窗口

    //每个tab的信息
    typedef struct {
        QString filePath;                       //打开的文件路径
        NotePadTab *notePadTab;                 //记事本指针
    } Tab_Info_t;
    QList<Tab_Info_t> tabInfoList;              //打开的tab信息list

    QString enCoding;                           //编码格式(目前支持uft-8和gb2312)
    QFont   font;                               //显示字体
    GmlDataBase  *gmlDataBase;                  //存放配置信息等的数据库
    bool hasOpenProj;                           //是否已经打开了一个gpro工程文件


    void openFileWithFilePath(QString filepath);  //根据文件路径打开文件

private slots:
    void slotCreateProject();                   //创建工程
    void slotOpenProject();                     //打开工程
    void slotCloseProject();                    //关闭工程
    void slotFileOpen();                        //打开文件
    void slotFileNew();                         //新建文件
    void slotFileSave();                        //保存文件
    void slotFileSaveAs();                      //文件另存为
    void slotFileSaveAll();                     //保存所有文件
    void slotFileClose();                       //关闭文件
    bool slotFileCloseAll();                    //关闭所有文件
    void slotCloseWindow();                     //关闭窗口

    void slotUndo();                            //撤销
    void slotRedo();                            //重做
    void slotCut();                             //剪切
    void slotCopy();                            //复制
    void slotPaste();                           //粘贴
    void slotSelectAll();                       //全选
    void slotToUpperCase();                     //转为大写
    void slotToLowerCase();                     //转为小写
    void slotSearchAndReplace();                //查找和替换
    void slotGotoLine();                        //转到行

    void slotFontSelection();                   //字体选择
    void slotEncodingUTF8();                    //选择uft-8编码
    void slotEncodingGB2312();                  //选择gb2312编码

    void slotNextTab();                         //上一个tab
    void slotPrevTab();                         //下一个tab
    void slotCurrentWindows();                  //CurrentWindows
    void slotRecentFiles();                     //最近打开文件
    void slotClearRecentFiles();                //清除最近打开文件记录

    void slotAbout();                           //关于本软件

    void slotProjTreeAddNewFileClicked();       //工程树添加新文件
    void slotProjTreeAddExistingFileClicked();  //工程树添加现有文件

    void slotTabRequestClose(int);              //tab请求关闭

public slots:
    void slotNotePadContentChanged(NotePadTab *notePadTab);     //接收某个notePadTab内容改变的槽
};

#endif // MAINWINDOW_H
