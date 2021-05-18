#include "mainwindow.h"
#include <QPrintDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QPrintEngine>
#include <QTextStream>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QTabWidget>
#include <QTextDocumentWriter>
#include <QMessageBox>
#include <QFileDialog>
#include <QKeySequence>
#include <QMenuBar>
#include <QToolBar>
#include <QFont>
#include <QClipboard>
#include <QComboBox>
#include <QFontComboBox>
#include <QFontDatabase>
#include <QActionGroup>
#include <QTextCharFormat>
#include <QMimeData>
#include <QDesktopWidget>
#include <QApplication>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    init();
    setupFileMenu();
    setupEditMenu();
    setupBuildMenu();
    setupWindowMenu();
    setupHelpMenu();


}

MainWindow::~MainWindow()
{

}

//初始化
void MainWindow::init()
{
    //菜单栏, 工具栏, 状态栏
    menuBar = new QMenuBar(this);
    statusBar = new QStatusBar(this);
    topToolBar = new QToolBar(this);
    topToolBar->setAllowedAreas(Qt::TopToolBarArea | Qt::BottomToolBarArea);
    buildToolBar = new QToolBar(this);
    buildToolBar->setAllowedAreas(Qt::TopToolBarArea | Qt::BottomToolBarArea);
    setMenuBar(menuBar);
    setStatusBar(statusBar);
    addToolBar(topToolBar);
    addToolBarBreak(Qt::TopToolBarArea);
    addToolBar(buildToolBar);

    //左侧树停靠结构
    treeDirDock = new QDockWidget(tr("files"), this);
    treeDirDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    treeDirDock->setAllowedAreas(Qt::AllDockWidgetAreas);
    treeDirView = new TreeLayerView(treeDirDock);
    treeDirDock->setWidget(treeDirView);
    this->addDockWidget(Qt::LeftDockWidgetArea, treeDirDock);

    //log输出框停靠结构
    logDock = new QDockWidget(tr("output"), this);
    logDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    logDock->setAllowedAreas(Qt::AllDockWidgetAreas);
    logTextEdit = new LogTextEdit(logDock);
    logDock->setWidget(logTextEdit);
    this->addDockWidget(Qt::BottomDockWidgetArea, logDock);

    //tab标签页
    notepadTabWidget = new NotePadTabWidget(this);
    notepadTabWidget->setMovable(true);
    notepadTabWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    notepadTabWidget->setTabsClosable(true);
    this->setCentralWidget(notepadTabWidget);

    //全屏显示
    setWindowState(Qt::WindowMaximized);

    //设置窗口最小大小
    QDesktopWidget *desktopWidget = QApplication::desktop();
    QRect clientRect = desktopWidget->availableGeometry();
    int screenXSize = clientRect.width();
    int screenYSize = clientRect.height();
    setMinimumSize(screenXSize * 0.5, screenYSize * 0.5);
}

//文件菜单功能实现
void MainWindow::setupFileMenu()
{
    fileMenu = new QMenu(tr("&File"), menuBar);

    //打开文件
    openAct = new QAction(QIcon(tr(":/resource/fileopen.png")), tr("&Open"), this);
    openAct->setShortcut(QKeySequence::Open);
    fileMenu->addAction(openAct);
    topToolBar->addAction(openAct);

    //新建文件
    newAct = new QAction(QIcon(tr(":/resource/filenew.png")), tr("&New"), this);
    newAct->setShortcut(QKeySequence::New);
    fileMenu->addAction(newAct);
    topToolBar->addAction(newAct);

    fileMenu->addSeparator();

    //保存文件
    saveAct = new QAction(QIcon(tr(":/resource/filesave.png")), tr("&Save"), this);
    saveAct->setShortcut(QKeySequence::Save);
    fileMenu->addAction(saveAct);
    topToolBar->addAction(saveAct);

    //文件另存为
    saveAsAct = new QAction(QIcon(tr(":/resource/filesaveas.png")),
                            tr("Save &As..."), this);
    saveAsAct->setShortcut(QKeySequence::SaveAs);
    fileMenu->addAction(saveAsAct);
    topToolBar->addAction(saveAsAct);

    //保存所有
    saveAllAct = new QAction(QIcon(tr(":/resource/saveall.png")), tr("Save All"),
                             this);
    saveAllAct->setShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_S);
    fileMenu->addAction(saveAllAct);
    topToolBar->addAction(saveAllAct);

    fileMenu->addSeparator();

    //打印
    printAct = new QAction(QIcon(tr(":/resource/fileprint.png")), tr("Print"),
                           this);
    printAct->setShortcut(QKeySequence::Print);
    fileMenu->addAction(printAct);
    topToolBar->addAction(printAct);

    //打印预览
    printPreviewAct = new QAction(QIcon(tr(":/resource/printpreview.png")),
                                  tr("Print Pre&view"), this);
    fileMenu->addAction(printPreviewAct);
    topToolBar->addAction(printPreviewAct);

    //导出成PDF
    exportPdfAct = new QAction(QIcon(tr(":/resource/exportpdf.png")),
                               tr("Export Pdf"), this);
    fileMenu->addAction(exportPdfAct);
    topToolBar->addAction(exportPdfAct);

    fileMenu->addSeparator();

    //关闭当前文件
    closeAct = new QAction(QIcon(tr(":/resource/fileclose.png")), tr("Close"),
                           this);
    closeAct->setShortcut(QKeySequence::Close);
    fileMenu->addAction(closeAct);
    topToolBar->addAction(closeAct);

    //关闭所有文件
    closeAllAct = new QAction(QIcon(tr(":/resource/closeall.png")),
                              tr("Close All"), this);
    closeAllAct->setShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_X);
    fileMenu->addAction(closeAllAct);
    topToolBar->addAction(closeAllAct);

    //退出
    exitAct = new QAction(QIcon(tr(":/resource/fileexit.png")), tr("Exit"), this);
    exitAct->setShortcut(QKeySequence::Quit);
    fileMenu->addAction(exitAct);
    topToolBar->addAction(exitAct);

    topToolBar->addSeparator();

    menuBar->addMenu(fileMenu);
}

//编辑菜单功能实现
void MainWindow::setupEditMenu()
{
    editMenu = new QMenu(tr("&Edit"), menuBar);

    //复制
    copyAct = new QAction(QIcon(tr(":/resource/editcopy.png")), tr("&Copy"), this);
    copyAct->setShortcut(QKeySequence::Copy);
    editMenu->addAction(copyAct);
    topToolBar->addAction(copyAct);

    //剪切
    cutAct = new QAction(QIcon(tr(":/resource/editcut.png")), tr("&Cut"), this);
    cutAct->setShortcut(QKeySequence::Cut);
    editMenu->addAction(cutAct);
    topToolBar->addAction(cutAct);

    //粘贴
    pasteAct = new QAction(QIcon(tr(":/resource/editpaste.png")), tr("&Paste"), this);
    pasteAct->setShortcut(QKeySequence::Paste);
    editMenu->addAction(pasteAct);
    topToolBar->addAction(pasteAct);

    editMenu->addSeparator();

    //撤销
    undoAct = new QAction(QIcon(tr(":/resource/editundo.png")), tr("&Undo"), this);
    undoAct->setShortcut(QKeySequence::Undo);
    editMenu->addAction(undoAct);
    topToolBar->addAction(undoAct);

    //重做
    redoAct = new QAction(QIcon(tr(":/resource/editredo.png")), tr("&Redo"), this);
    redoAct->setShortcut(QKeySequence::Redo);
    editMenu->addAction(redoAct);
    topToolBar->addAction(redoAct);

    editMenu->addSeparator();

    //全选
    selectAllAct = new QAction(QIcon(tr(":/resource/editselectall.png")),
                               tr("&Select all"), this);
    selectAllAct->setShortcut(QKeySequence::SelectAll);
    editMenu->addAction(selectAllAct);
    topToolBar->addAction(selectAllAct);

    //转为大写
    upperCaseAct = new QAction(QIcon(tr(":/resource/uppercase.png")), tr("UpperCase"),
                               this);
    editMenu->addAction(upperCaseAct);
    topToolBar->addAction(upperCaseAct);

    //转为小写
    lowerCaseAct = new QAction(QIcon(tr(":/resource/lowercase.png")), tr("LowerCase"),
                               this);
    editMenu->addAction(lowerCaseAct);
    topToolBar->addAction(lowerCaseAct);

    editMenu->addSeparator();

    //转到行
    gotoLineAct = new QAction(tr("Goto Line..."), this);
    gotoLineAct->setShortcut(Qt::CTRL + Qt::Key_G);
    editMenu->addAction(gotoLineAct);

    //查找和替换
    findAct = new QAction(QIcon(tr(":/resource/editfind.png")), tr("&Find/Replace"),
                          this);
    findAct->setShortcut(QKeySequence::Find);
    editMenu->addAction(findAct);
    topToolBar->addAction(findAct);

    topToolBar->addSeparator();

    menuBar->addMenu(editMenu);
}

//文件菜单Action设置
void MainWindow::setupFileActions()
{
    connect(openAct, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(fileSave()));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(fileSaveAs()));
    connect(saveAllAct, SIGNAL(triggered()), this, SLOT(fileSaveAll()));
#ifndef QT_NO_PRINTER
    connect(printAct, SIGNAL(triggered()), this, SLOT(filePrint()));
    connect(printPreviewAct, SIGNAL(triggered()), this,
            SLOT(filePrintPreview()));
    connect(exportPdfAct, SIGNAL(triggered()), this, SLOT(filePrintPdf()));
#endif
    connect(closeAct, SIGNAL(triggered()), this, SLOT(fileClose()));
    connect(closeAllAct, SIGNAL(triggered()), this, SLOT(fileCloseAll()));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
}

//编辑菜单Action设置
void MainWindow::setupEditActions()
{
//    connect(copyAct, SIGNAL(triggered()), EDITOR,SLOT(copy()));
//    connect(pasteAct,SIGNAL(triggered()),EDITOR,SLOT(paste()));
//    connect(undoAct,SIGNAL(triggered()),EDITOR,SLOT(undo()));
//    connect(redoAct,SIGNAL(triggered()),EDITOR,SLOT(redo()));
//    connect(selectAllAct,SIGNAL(triggered()),EDITOR,SLOT(selectAll()));
//    connect(upperCaseAct,SIGNAL(triggered()),EDITOR,SLOT(toUpperCase()));
//    connect(lowerCaseAct,SIGNAL(triggered()),EDITOR,SLOT(toLowerCase()));
//    connect(gotoLineAct,SIGNAL(triggered()),this,SLOT(gotoLine()));
//    connect(findAct,SIGNAL(triggered()),this,SLOT(search()));
}

/* 构建菜单功能实现 */
void MainWindow::setupBuildMenu()
{
    buildMenu = new QMenu(tr("&Build"), menuBar);
    menuBar->addMenu(buildMenu);

    //编译
    compileAct = new QAction(QIcon(tr(":/resource/compile.png")), tr("&Compile"), this);
    buildMenu->addAction(compileAct);
    buildToolBar->addAction(compileAct);

    //部署
    deployAct = new QAction(QIcon(tr(":/resource/deploy.png")), tr("&Deploy"), this);
    buildMenu->addAction(deployAct);
    buildToolBar->addAction(deployAct);

    //运行
    runAct = new QAction(QIcon(tr(":/resource/run.png")), tr("&Run"), this);
    buildMenu->addAction(runAct);
    buildToolBar->addAction(runAct);
}

/* 构建菜单Action设置 */
void MainWindow::setupBuildActions()
{
//    connect(compileAct, SIGNAL(triggered()), EDITOR,SLOT(copy()));
//    connect(deployAct,SIGNAL(triggered()),EDITOR,SLOT(paste()));
//    connect(runAct,SIGNAL(triggered()),EDITOR,SLOT(undo()));
}

//窗口菜单功能实现
void MainWindow::setupWindowMenu()
{
    windowMenu = new QMenu(tr("&Window"), menuBar);

    //下一个窗口
    nextAct = new QAction(QIcon(tr(":/resource/next.png")), tr("Next Window"), this);
    nextAct->setShortcut(Qt::CTRL + Qt::Key_Right);
    windowMenu->addAction(nextAct);
    topToolBar->addAction(nextAct);

    //上一个窗口
    previousAct = new QAction(QIcon(tr(":/resource/previous.png")),
                              tr("Previous Window"), this);
    previousAct->setShortcut(Qt::CTRL + Qt::Key_Left);
    windowMenu->addAction(previousAct);
    topToolBar->addAction(previousAct);

    //最近关闭的文件
    recentlyFilesMenu = new QMenu(tr("Recently Files"), windowMenu);
    //fillRecentFileActs();
    windowMenu->addMenu(recentlyFilesMenu);

    //当前所有窗口
    currentAllMenu = new QMenu(tr("Current Windows"), windowMenu);
    windowMenu->addMenu(currentAllMenu);
    //openedFilesGrp = new QActionGroup(this);

    topToolBar->addSeparator();
    menuBar->addMenu(windowMenu);
}

//窗口菜单Action设置
void MainWindow::setupWindowActions()
{
    connect(nextAct, SIGNAL(triggered()), SLOT(nextWindow()));
    connect(previousAct, SIGNAL(triggered()), SLOT(previousWindow()));
    connect(currentAllMenu, SIGNAL(aboutToShow()), SLOT(currentAllWindow()));
    connect(recentlyFilesMenu, SIGNAL(aboutToShow()), SLOT(updateRecentFiles()));
}

//帮助菜单功能实现
void MainWindow::setupHelpMenu()
{
    helpMenu = new QMenu(tr("&Help"), menuBar);

    //关于本软件
    aboutAct = new QAction(QIcon(tr(":/resource/helpabout.png")), tr("About"), this);
    helpMenu->addAction(aboutAct);
    topToolBar->addAction(aboutAct);

    menuBar->addMenu(helpMenu);
}

//帮助Action设置
void MainWindow::setupHelpActions()
{
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
}

//关于本软件
void MainWindow::about()
{
    QMessageBox::about(this, tr("About"), tr("This example demonstrates Qt's "
                                             "rich text editing facilities in action, providing an example "
                                             "document for you to experiment with."));
}
