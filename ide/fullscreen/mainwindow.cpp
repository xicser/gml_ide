#include "mainwindow.h"
#include <QPrintDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QPrintEngine>
#include <QTextStream>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QTabWidget>
#include <QMessageBox>
#include <QFileDialog>
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
    setupFormatMenu();
    setupBuildMenu();
    setupWindowMenu();
    setupHelpMenu();

    setupFileActions();
    setupEditActions();
    setupFormatActions();
    setupBuildActions();
    setupWindowActions();
    setupHelpActions();
}

MainWindow::~MainWindow()
{
    qDebug() << "~MainWindow";
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    bool isCancel = slotFileCloseAll();
    if (isCancel == true) {
        event->ignore();
    }
}

//初始化
void MainWindow::init()
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    tabInfoList.clear();
    enCoding = "utf-8";
    this->font.setFamily("Courier New");
    this->font.setPointSize(12);
    this->font.setWeight(QFont::Normal);

    setWindowIcon(QIcon(":/resource/notepad.png"));
    setWindowTitle("GML Integrated Development Environment");

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
    tabWidget = new QTabWidget(this);
    tabWidget->setMovable(true);
    tabWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    tabWidget->setTabsClosable(true);
    connect(tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::slotTabRequestClose);
    this->setCentralWidget(tabWidget);

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
    topToolBar->addSeparator();

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
    topToolBar->addSeparator();

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

/* 格式菜单功能实现 */
void MainWindow::setupFormatMenu()
{
    formatMenu = new QMenu(tr("&Format"), menuBar);
    enCodingMenu = new QMenu(tr("Encoding"), formatMenu);

    //字体
    fontAct = new QAction(QIcon(tr(":/resource/textfont.png")), tr("Font"), formatMenu);
    topToolBar->addAction(fontAct);
    topToolBar->addSeparator();

    //UTF-8
    enCodingUTF8Act = new QAction(tr("UTF-8"), enCodingMenu);
    enCodingUTF8Act->setCheckable(true);
    enCodingUTF8Act->setChecked(true);

    //GB2312
    enCodingGB2312Act = new QAction(tr("GB2312"), enCodingMenu);
    enCodingGB2312Act->setCheckable(true);
    enCodingGB2312Act->setChecked(false);

    formatMenu->addMenu(enCodingMenu);
    enCodingMenu->addAction(enCodingUTF8Act);
    enCodingMenu->addAction(enCodingGB2312Act);
    formatMenu->addSeparator();
    formatMenu->addAction(fontAct);

    menuBar->addMenu(formatMenu);
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

//窗口菜单功能实现
void MainWindow::setupWindowMenu()
{
    windowMenu = new QMenu(tr("&Window"), menuBar);

    //上一个窗口
    previousAct = new QAction(QIcon(tr(":/resource/previous.png")),
                              tr("Previous Window"), this);
    previousAct->setShortcut(Qt::CTRL + Qt::Key_Left);
    windowMenu->addAction(previousAct);
    topToolBar->addAction(previousAct);

    //下一个窗口
    nextAct = new QAction(QIcon(tr(":/resource/next.png")), tr("Next Window"), this);
    nextAct->setShortcut(Qt::CTRL + Qt::Key_Right);
    windowMenu->addAction(nextAct);
    topToolBar->addAction(nextAct);

    //最近关闭的文件
    recentlyFilesMenu = new QMenu(tr("Recently Files"), windowMenu);
    windowMenu->addMenu(recentlyFilesMenu);

    //当前所有窗口
    currentAllMenu = new QMenu(tr("Current Windows"), windowMenu);
    windowMenu->addMenu(currentAllMenu);
    topToolBar->addSeparator();
    menuBar->addMenu(windowMenu);
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

//文件菜单Action设置
void MainWindow::setupFileActions()
{
    connect(openAct, &QAction::triggered, this, &MainWindow::slotFileOpen);
    connect(newAct, &QAction::triggered, this, &MainWindow::slotFileNew);
    connect(saveAct, &QAction::triggered, this, &MainWindow::slotFileSave);
    connect(saveAsAct, &QAction::triggered, this, &MainWindow::slotFileSaveAs);
    connect(saveAllAct, &QAction::triggered, this, &MainWindow::slotFileSaveAll);
//#ifndef QT_NO_PRINTER
//    connect(printAct, SIGNAL(triggered()), this, SLOT(filePrint()));
//    connect(printPreviewAct, SIGNAL(triggered()), this,
//            SLOT(filePrintPreview()));
//    connect(exportPdfAct, SIGNAL(triggered()), this, SLOT(filePrintPdf()));
//#endif
    connect(closeAct, &QAction::triggered, this, &MainWindow::slotFileClose);
    connect(closeAllAct, &QAction::triggered, this, &MainWindow::slotFileCloseAll);
    connect(exitAct, &QAction::triggered, this, &MainWindow::slotCloseWindow);
}

//编辑菜单Action设置
void MainWindow::setupEditActions()
{
    connect(undoAct, &QAction::triggered, this, &MainWindow::slotUndo);
    connect(redoAct, &QAction::triggered, this, &MainWindow::slotRedo);
    connect(cutAct, &QAction::triggered, this, &MainWindow::slotCut);
    connect(copyAct, &QAction::triggered, this, &MainWindow::slotCopy);
    connect(pasteAct, &QAction::triggered, this, &MainWindow::slotPaste);
    connect(selectAllAct, &QAction::triggered, this, &MainWindow::slotSelectAll);
//    connect(upperCaseAct,SIGNAL(triggered()),EDITOR,SLOT(toUpperCase()));
//    connect(lowerCaseAct,SIGNAL(triggered()),EDITOR,SLOT(toLowerCase()));
//    connect(gotoLineAct,SIGNAL(triggered()),this,SLOT(gotoLine()));
//    connect(findAct,SIGNAL(triggered()),this,SLOT(search()));
}

/* 格式菜单Action设置 */
void MainWindow::setupFormatActions()
{
    connect(fontAct, &QAction::triggered, this, &MainWindow::slotFontSelection);
    connect(enCodingUTF8Act, &QAction::triggered, this, &MainWindow::slotEncodingUTF8);
    connect(enCodingGB2312Act, &QAction::triggered, this, &MainWindow::slotEncodingGB2312);
}

/* 构建菜单Action设置 */
void MainWindow::setupBuildActions()
{
//    connect(compileAct, SIGNAL(triggered()), EDITOR,SLOT(copy()));
//    connect(deployAct,SIGNAL(triggered()),EDITOR,SLOT(paste()));
//    connect(runAct,SIGNAL(triggered()),EDITOR,SLOT(undo()));
}

//窗口菜单Action设置
void MainWindow::setupWindowActions()
{
    connect(nextAct, &QAction::triggered, this, &MainWindow::slotNextTab);
    connect(previousAct, &QAction::triggered, this, &MainWindow::slotPrevTab);
//    connect(currentAllMenu, SIGNAL(aboutToShow()), SLOT(currentAllWindow()));
//    connect(recentlyFilesMenu, SIGNAL(aboutToShow()), SLOT(updateRecentFiles()));
}

//帮助Action设置
void MainWindow::setupHelpActions()
{
    connect(aboutAct, &QAction::triggered, this, &MainWindow::slotAbout);
}

/* 打开文件 */
void MainWindow::slotFileOpen()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("选择文本文件"), ".",
             "text(*.cpp *.h *.txt);;all(*.*)");

    if (filename.isEmpty()) {
        return;
    }

    //判断该文件是否已经被打开?
    bool hasOpened = false;
    int index;
    for (int i = 0; i < tabInfoList.size(); i++) {
        if (tabInfoList[i].filePath == filename) {
            hasOpened = true;
            index = i;
            break;
        }
    }
    if (hasOpened == true) {
        //聚焦到之前已经打开的文件tab上
        this->tabWidget->setCurrentWidget(tabInfoList[index].notePadTab);
        return;
    }

    //创建一个新的tab
    Tab_Info_t tabInfo;
    tabInfo.notePadTab = new NotePadTab(tabWidget);
    tabInfo.notePadTab->setEncoding(this->enCoding);
    tabInfo.notePadTab->setLexerFont(this->font);
    tabInfo.notePadTab->setEditStatus(false);
    tabInfo.notePadTab->setFilePath(filename);
    tabInfo.filePath = filename;
    tabInfoList << tabInfo;

    //获取文件名
    QFileInfo info(filename);
    QString title = info.fileName();

    //打开文件(用流的方式)
    QFile file(this);
    file.setFileName(filename);
    bool ret = file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (ret == false) {
        QMessageBox::warning(this, "错误", "打开出错！");
        return;
    }
    QTextStream inStream(&file);
    if (this->enCoding == "utf-8") {
        inStream.setCodec("UTF-8");
    } else {
        inStream.setCodec("GB18030");
    }
    tabInfo.notePadTab->setText(inStream.readAll());
    file.close();

    this->tabWidget->addTab(tabInfo.notePadTab, title);
    connect(tabInfo.notePadTab, &QsciScintilla::textChanged, tabInfo.notePadTab, &NotePadTab::slotContentChanged);
    connect(tabInfo.notePadTab, &NotePadTab::signalContentHasChanged, this, &MainWindow::slotNotePadContentChanged);

    //聚焦到刚刚打开的文件tab上
    this->tabWidget->setCurrentWidget(tabInfo.notePadTab);
    tabInfo.notePadTab->setFocus();
}

/* 新建文件 */
void MainWindow::slotFileNew()
{
    //创建一个新的tab
    Tab_Info_t tabInfo;
    tabInfo.notePadTab = new NotePadTab(tabWidget);
    tabInfo.notePadTab->setEncoding(this->enCoding);
    tabInfo.notePadTab->setLexerFont(this->font);
    tabInfo.notePadTab->setEditStatus(true);
    tabInfo.filePath = "new";
    tabInfo.notePadTab->setFilePath(tabInfo.filePath);
    tabInfoList << tabInfo;

    this->tabWidget->addTab(tabInfo.notePadTab, tr("new *"));
    connect(tabInfo.notePadTab, &QsciScintilla::textChanged, tabInfo.notePadTab, &NotePadTab::slotContentChanged);
    connect(tabInfo.notePadTab, &NotePadTab::signalContentHasChanged, this, &MainWindow::slotNotePadContentChanged);

    //聚焦到刚刚新建的文件tab上
    this->tabWidget->setCurrentWidget(tabInfo.notePadTab);
    tabInfo.notePadTab->setFocus();
}

/* 保存文件 */
void MainWindow::slotFileSave()
{
    //根本没有打开的子窗体, 直接返回
    if (tabInfoList.isEmpty() == true) {
        return;
    }

    //先获取当前活动的子窗体
    NotePadTab *notePadTabActive = static_cast<NotePadTab *>(this->tabWidget->currentWidget());
    int index = this->tabWidget->indexOf(notePadTabActive);

    //为new, 表示是新建的文件
    if (notePadTabActive->getFileName() == "new") {
        QString tmpStr = "保存";
        tmpStr.append(notePadTabActive->getFileName());

        QString filepath = QFileDialog::getSaveFileName(this, tmpStr, ".", "text(*.cpp *.h *.txt);;all(*.*)");
        if (filepath.isEmpty() == false) {

            //把字窗口中的内容写进文件
            QFile file(this);
            file.setFileName(filepath);
            bool ret = file.open(QIODevice::WriteOnly | QIODevice::Text);
            if (ret == false) {
                QMessageBox::warning(this, "错误", "保存出错！");
                return;
            }
            QTextStream stream(&file);
            //设置流的编码格式
            if (this->enCoding == "utf-8") {
                stream.setCodec("UTF-8");
            } else {
                stream.setCodec("GB18030");
            }
            stream << notePadTabActive->text();
            stream.flush();
            file.close();

            //提示保存成功
            QMessageBox::information(this, "提示", "保存成功！");

            //设置新的title
            QFileInfo info(filepath);
            QString title = info.fileName();
            this->tabWidget->setTabText(index, title);
            notePadTabActive->setEditStatus(false);
            notePadTabActive->setFilePath(filepath);

            //修改list里面对应的名字
            for (int i = 0; i < tabInfoList.size(); i++) {
                if (tabInfoList[i].notePadTab == notePadTabActive) {
                    tabInfoList[i].filePath = filepath;
                    return;
                }
            }
        }
    }
    //保存之前打开的文件
    else {

        //从未改变过的文件, 根本不需要保存
        if (notePadTabActive->getEditStatus() == false) {
            return;
        }

        //把字窗口中的内容写进文件
        QFile file(this);
        file.setFileName(notePadTabActive->getFilePath());
        bool ret = file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
        if (ret == false) {
            QMessageBox::warning(this, "错误", "保存出错！");
            return;
        }
        QTextStream stream(&file);
        //设置流的编码格式
        if (this->enCoding == "utf-8") {
            stream.setCodec("UTF-8");
        } else {
            stream.setCodec("GB18030");
        }
        stream << notePadTabActive->text();
        stream.flush();
        file.close();

        QFileInfo info(notePadTabActive->getFilePath());
        QString title = info.fileName();
        this->tabWidget->setTabText(index, title);
        notePadTabActive->setEditStatus(false);
    }
}

/* 文件另存为 */
void MainWindow::slotFileSaveAs()
{
    //根本没有打开的子窗体, 直接返回
    if (tabInfoList.isEmpty() == true) {
        return;
    }

    //先获取当前活动的子窗体
    NotePadTab *notePadTabActive = static_cast<NotePadTab *>(this->tabWidget->currentWidget());

    QString tmpStr = "另存为";
    tmpStr = tmpStr.append(notePadTabActive->getFileName());
    QString filepath = QFileDialog::getSaveFileName(this, tmpStr, ".", "text(*.cpp *.h *.txt);;all(*.*)");
    if (filepath.isEmpty() == false) {

        //新开一个tab, 显示刚才另存为的文件
        Tab_Info_t tabInfo;
        tabInfo.notePadTab = new NotePadTab(tabWidget);
        tabInfo.notePadTab->setEncoding(this->enCoding);
        tabInfo.notePadTab->setLexerFont(this->font);
        tabInfo.notePadTab->setEditStatus(false);
        tabInfo.filePath = filepath;
        tabInfo.notePadTab->setFilePath(tabInfo.filePath);
        tabInfoList << tabInfo;

        tabInfo.notePadTab->setText(notePadTabActive->text()); //拷贝之前那个tab的文本内容
        this->tabWidget->addTab(tabInfo.notePadTab, tabInfo.notePadTab->getFileName());
        connect(tabInfo.notePadTab, &QsciScintilla::textChanged, tabInfo.notePadTab, &NotePadTab::slotContentChanged);
        connect(tabInfo.notePadTab, &NotePadTab::signalContentHasChanged, this, &MainWindow::slotNotePadContentChanged);

        //聚焦到刚刚新建的文件tab上
        this->tabWidget->setCurrentWidget(tabInfo.notePadTab);
        tabInfo.notePadTab->setFocus();

        //保存到磁盘
        QFile file(this);
        file.setFileName(filepath);
        bool ret = file.open(QIODevice::WriteOnly | QIODevice::Text);
        if (ret == false) {
            QMessageBox::warning(this, "错误", "保存出错！");
            return;
        }
        QTextStream stream(&file);
        //设置流的编码格式
        if (this->enCoding == "utf-8") {
            stream.setCodec("UTF-8");
        } else {
            stream.setCodec("GB18030");
        }
        stream << notePadTabActive->text();
        stream.flush();
        file.close();

        //提示另存为成功
        QMessageBox::information(this, "提示", "另存为成功！");
    }
}

/* 保存所有文件 */
void MainWindow::slotFileSaveAll()
{
    //遍历所有tab, 如果某个tab满足保存条件, 就保存它
    for (int i = 0; i < tabInfoList.size(); i++) {
        this->tabWidget->setCurrentWidget(tabInfoList[i].notePadTab);
        slotFileSave();
    }
}

/* 打印文件 */
void MainWindow::slotFilePrint()
{

}

/* 打印预览 */
void MainWindow::slotFilePrintPreview()
{

}

/* 输出成PDF */
void MainWindow::slotFilePrintPdf()
{

}

/* 打印预览子函数 */
void MainWindow::slotPrintPreview(QPrinter *)
{

}

/* 关闭文件 */
void MainWindow::slotFileClose()
{
    //根本没有打开的子窗体, 直接返回
    if (tabInfoList.isEmpty() == true) {
        return;
    }

    //先获取当前活动的子窗体
    NotePadTab *notePadTabActive = static_cast<NotePadTab *>(this->tabWidget->currentWidget());
    int index = this->tabWidget->indexOf(notePadTabActive);

    //如果该窗体正在被编辑, 则要提示是否保存
    if (notePadTabActive->getEditStatus() == true) {
        QString tmpStr = "是否保存 ";
        tmpStr.append(notePadTabActive->getFileName());
        tmpStr.append(" ?");
        QMessageBox::StandardButton ret = QMessageBox::information(this, "保存提示", tmpStr,
                                 QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        switch (ret) {
            case QMessageBox::Yes: {

                //保存文件
                this->slotFileSave();

                //保存完成后, 关闭该窗体
                this->tabWidget->removeTab(index);
                //从list里面去除
                for (int i = 0; i < tabInfoList.size(); i++) {
                    if (notePadTabActive == tabInfoList[i].notePadTab) {
                        tabInfoList.removeAt(i);
                    }
                }
                delete notePadTabActive;

                break;
            }
            case QMessageBox::No: {
                this->tabWidget->removeTab(index);
                //从list里面去除
                for (int i = 0; i < tabInfoList.size(); i++) {
                    if (notePadTabActive == tabInfoList[i].notePadTab) {
                        tabInfoList.removeAt(i);
                    }
                }
                delete notePadTabActive;
                break;
            }
            case QMessageBox::Cancel: break;
            default: break;
        }
    }
    //否则直接关闭即可
    else {
        this->tabWidget->removeTab(index);
        //从list里面去除
        for (int i = 0; i < tabInfoList.size(); i++) {
            if (notePadTabActive == tabInfoList[i].notePadTab) {
                tabInfoList.removeAt(i);
            }
        }
        delete notePadTabActive;
    }
}

/* 关闭所有文件 */
bool MainWindow::slotFileCloseAll()
{
    //遍历所有tab, 如果某个tab满足保存条件, 就关闭它
    while (tabInfoList.size() > 0) {

        //先获取当前活动的子窗体
        NotePadTab *notePadTabActive = static_cast<NotePadTab *>(this->tabWidget->currentWidget());
        int index = this->tabWidget->indexOf(notePadTabActive);

        //如果该窗体正在被编辑, 则要提示是否保存
        if (notePadTabActive->getEditStatus() == true) {
            QString tmpStr = "是否保存 ";
            tmpStr.append(notePadTabActive->getFileName());
            tmpStr.append(" ?");
            QMessageBox::StandardButton ret = QMessageBox::information(this, "保存提示", tmpStr,
                                     QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
            switch (ret) {
                case QMessageBox::Yes: {

                    //保存文件
                    this->slotFileSave();

                    //保存完成后, 关闭该窗体
                    this->tabWidget->removeTab(index);
                    //从list里面去除
                    for (int i = 0; i < tabInfoList.size(); i++) {
                        if (notePadTabActive == tabInfoList[i].notePadTab) {
                            tabInfoList.removeAt(i);
                        }
                    }
                    delete notePadTabActive;

                    break;
                }
                case QMessageBox::No: {
                    this->tabWidget->removeTab(index);
                    //从list里面去除
                    for (int i = 0; i < tabInfoList.size(); i++) {
                        if (notePadTabActive == tabInfoList[i].notePadTab) {
                            tabInfoList.removeAt(i);
                        }
                    }
                    delete notePadTabActive;
                    break;
                }
                case QMessageBox::Cancel: return true;
                default: break;
            }
        }
        //否则直接关闭即可
        else {
            this->tabWidget->removeTab(index);
            //从list里面去除
            for (int i = 0; i < tabInfoList.size(); i++) {
                if (notePadTabActive == tabInfoList[i].notePadTab) {
                    tabInfoList.removeAt(i);
                }
            }
            delete notePadTabActive;
        }
    }

    return false;
}

/* 关闭窗口 */
void MainWindow::slotCloseWindow()
{
    this->close();
}

/* 撤销 */
void MainWindow::slotUndo(void)
{
    //根本没有打开的子窗体, 直接返回
    if (tabInfoList.isEmpty() == true) {
        return;
    }

    //先获取当前活动的子窗体
    NotePadTab *notePadTabActive = static_cast<NotePadTab *>(this->tabWidget->currentWidget());
    notePadTabActive->undo();
}

/* 重做 */
void MainWindow::slotRedo(void)
{
    //根本没有打开的子窗体, 直接返回
    if (tabInfoList.isEmpty() == true) {
        return;
    }

    //先获取当前活动的子窗体
    NotePadTab *notePadTabActive = static_cast<NotePadTab *>(this->tabWidget->currentWidget());
    notePadTabActive->redo();
}

/* 剪切 */
void MainWindow::slotCut(void)
{
    //根本没有打开的子窗体, 直接返回
    if (tabInfoList.isEmpty() == true) {
        return;
    }

    //先获取当前活动的子窗体
    NotePadTab *notePadTabActive = static_cast<NotePadTab *>(this->tabWidget->currentWidget());
    notePadTabActive->cut();
}

/* 复制 */
void MainWindow::slotCopy(void)
{
    //根本没有打开的子窗体, 直接返回
    if (tabInfoList.isEmpty() == true) {
        return;
    }

    //先获取当前活动的子窗体
    NotePadTab *notePadTabActive = static_cast<NotePadTab *>(this->tabWidget->currentWidget());
    notePadTabActive->copy();
}

/* 粘贴 */
void MainWindow::slotPaste(void)
{
    //根本没有打开的子窗体, 直接返回
    if (tabInfoList.isEmpty() == true) {
        return;
    }

    //先获取当前活动的子窗体
    NotePadTab *notePadTabActive = static_cast<NotePadTab *>(this->tabWidget->currentWidget());
    notePadTabActive->paste();
}

/* 全选 */
void MainWindow::slotSelectAll()
{
    //根本没有打开的子窗体, 直接返回
    if (tabInfoList.isEmpty() == true) {
        return;
    }

    //先获取当前活动的子窗体
    NotePadTab *notePadTabActive = static_cast<NotePadTab *>(this->tabWidget->currentWidget());
    notePadTabActive->selectAll();
}

/* 转到行 */
void MainWindow::slotJumpLine()
{

}

/* 查找 */
void MainWindow::slotSearch()
{

}

/* 字体选择 */
void MainWindow::slotFontSelection()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this->font, this);
    if (ok == false) {
        return;
    }

    this->font = font;
    for (int i = 0; i < this->tabInfoList.size(); i++) {
        this->tabInfoList[i].notePadTab->setLexerFont(font);
    }
}

/* 选择uft-8编码 */
void MainWindow::slotEncodingUTF8(void)
{
    this->enCodingUTF8Act->setChecked(true);
    this->enCodingGB2312Act->setChecked(false);
    this->enCoding = "utf-8";
}

/* 选择gb2312编码 */
void MainWindow::slotEncodingGB2312(void)
{
    this->enCodingUTF8Act->setChecked(false);
    this->enCodingGB2312Act->setChecked(true);
    this->enCoding = "gb2312";
}

/* 上一个tab */
void MainWindow::slotNextTab()
{
    //先获取当前活动的子窗体
    NotePadTab *notePadTabActive = static_cast<NotePadTab *>(this->tabWidget->currentWidget());

    for (int i = 0; i < tabInfoList.size(); i++) {
        if (notePadTabActive == tabInfoList[i].notePadTab) {
            if (i < tabInfoList.size() - 1) {
                this->tabWidget->setCurrentWidget(tabInfoList[i + 1].notePadTab);
            }
        }
    }
}

/* 下一个tab */
void MainWindow::slotPrevTab()
{
    //先获取当前活动的子窗体
    NotePadTab *notePadTabActive = static_cast<NotePadTab *>(this->tabWidget->currentWidget());

    for (int i = 0; i < tabInfoList.size(); i++) {
        if (notePadTabActive == tabInfoList[i].notePadTab) {
            if (i > 0) {
                this->tabWidget->setCurrentWidget(tabInfoList[i - 1].notePadTab);
            }
        }
    }
}

//关于本软件
void MainWindow::slotAbout()
{
    QMessageBox::about(this, tr("About"), tr("This example demonstrates Qt's "
                                             "rich text editing facilities in action, providing an example "
                                             "document for you to experiment with."));
}

/* tab请求关闭 */
void MainWindow::slotTabRequestClose(int index)
{
    this->tabWidget->setCurrentIndex(index);
    this->slotFileClose();
}

/* 接收某个notePadTab内容改变的槽 */
void MainWindow::slotNotePadContentChanged(NotePadTab *notePadTab)
{
    int index = this->tabWidget->indexOf(notePadTab);
    QString tabStr = notePadTab->getFileName() + " *";
    this->tabWidget->setTabText(index, tabStr);
}
