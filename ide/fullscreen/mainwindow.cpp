#include "mainwindow.h"
#include "fullsub/projview.h"

#include <QColorDialog>
#include <QFontDialog>
#include <QTextStream>
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
    setupProjTree();

    setupFileActions();
    setupEditActions();
    setupFormatActions();
    setupBuildActions();
    setupWindowActions();
    setupHelpActions();
    setupProjTreeActions();
}

MainWindow::~MainWindow()
{
    if (gotolineDialog != nullptr) {
        delete gotolineDialog;
    }
    if (searchDialog != nullptr) {
        delete searchDialog;
    }
    if (gmlDataBase != nullptr) {
        delete gmlDataBase;
    }
    if (createProjectDialog != nullptr) {
        delete createProjectDialog;
    }
}

/* 获取hasOpenProj */
bool MainWindow::getHasOpenProj()
{
    return this->hasOpenProj;
}

/* 根据文件路径, 跳转到其对应的tab */
void MainWindow::jumpToTabAccordingFilePath(QString filepath)
{
    for (int i = 0; i < this->tabInfoList.size(); i++) {
        if (tabInfoList[i].filePath == filepath) {
            NotePadTab *notePadTab = tabInfoList[i].notePadTab;
            this->tabWidget->setCurrentWidget(notePadTab);
            break;
        }
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    bool isCancel = slotFileCloseAll();
    if (isCancel == true) {
        event->ignore();
    }
}

/* 初始化 */
void MainWindow::init()
{
    hasOpenProj = false;
    gmlDataBase = nullptr;
    gmlDataBase = new GmlDataBase();
    searchDialog = nullptr;
    gotolineDialog = nullptr;
    createProjectDialog = nullptr;
    tabInfoList.clear();
    enCoding = "utf-8";
    this->font.setFamily("Courier New");
    this->font.setPointSize(12);
    this->font.setWeight(QFont::Normal);

    this->setAttribute(Qt::WA_DeleteOnClose);
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

    //左侧项目树停靠结构
    projViewDock = new QDockWidget("Files", this);
    projViewDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    projViewDock->setAllowedAreas(Qt::AllDockWidgetAreas);
    projView = new ProjView(projViewDock);
    projViewDock->setWidget(projView);
    this->addDockWidget(Qt::LeftDockWidgetArea, projViewDock);
    projView->setMainWindow(this);

    //log输出框停靠结构
    logDock = new QDockWidget("Output", this);
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
    connect(tabWidget, &QTabWidget::tabBarClicked, this, &MainWindow::slotTabBarClicked);
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

/* 文件菜单功能实现 */
void MainWindow::setupFileMenu()
{
    fileMenu = new QMenu("&File", menuBar);

    //新建工程
    newProjAct = new QAction(QIcon(":/resource/filenew.png"), "&Create Project", this);
    fileMenu->addAction(newProjAct);
    topToolBar->addAction(newProjAct);

    //打开工程
    openProjAct = new QAction(QIcon(":/resource/filenew.png"), "&Open Project", this);
    fileMenu->addAction(openProjAct);
    topToolBar->addAction(openProjAct);

    //关闭工程
    closeProjAct = new QAction(QIcon(":/resource/filenew.png"), "&Close Project", this);
    fileMenu->addAction(closeProjAct);
    topToolBar->addAction(closeProjAct);
    topToolBar->addSeparator();

    fileMenu->addSeparator();

    //打开文件
    openAct = new QAction(QIcon(":/resource/fileopen.png"), "&Open Files", this);
    openAct->setShortcut(QKeySequence::Open);
    fileMenu->addAction(openAct);
    topToolBar->addAction(openAct);

    //新建文件
    newAct = new QAction(QIcon(":/resource/filenew.png"), "&New File", this);
    newAct->setShortcut(QKeySequence::New);
    fileMenu->addAction(newAct);
    topToolBar->addAction(newAct);

    fileMenu->addSeparator();

    //保存文件
    saveAct = new QAction(QIcon(":/resource/filesave.png"), "&Save", this);
    saveAct->setShortcut(QKeySequence::Save);
    fileMenu->addAction(saveAct);
    topToolBar->addAction(saveAct);

    //文件另存为
    saveAsAct = new QAction(QIcon(":/resource/filesaveas.png"), "Save &As...", this);
    saveAsAct->setShortcut(QKeySequence::SaveAs);
    fileMenu->addAction(saveAsAct);
    topToolBar->addAction(saveAsAct);

    //保存所有
    saveAllAct = new QAction(QIcon(":/resource/saveall.png"), "Save All", this);
    saveAllAct->setShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_S);
    fileMenu->addAction(saveAllAct);
    topToolBar->addAction(saveAllAct);
    topToolBar->addSeparator();

    fileMenu->addSeparator();

    //关闭当前文件
    closeAct = new QAction(QIcon(":/resource/fileclose.png"), "Close", this);
    closeAct->setShortcut(QKeySequence::Close);
    fileMenu->addAction(closeAct);
    topToolBar->addAction(closeAct);

    //关闭所有文件
    closeAllAct = new QAction(QIcon(":/resource/closeall.png"), "Close All", this);
    closeAllAct->setShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_X);
    fileMenu->addAction(closeAllAct);
    topToolBar->addAction(closeAllAct);

    //退出
    exitAct = new QAction(QIcon(":/resource/fileexit.png"), "Exit", this);
    exitAct->setShortcut(QKeySequence::Quit);
    fileMenu->addAction(exitAct);
    topToolBar->addAction(exitAct);
    topToolBar->addSeparator();

    menuBar->addMenu(fileMenu);
}

/* 编辑菜单功能实现 */
void MainWindow::setupEditMenu()
{
    editMenu = new QMenu("&Edit", menuBar);

    //复制
    copyAct = new QAction(QIcon(":/resource/editcopy.png"), "&Copy", this);
    copyAct->setShortcut(QKeySequence::Copy);
    editMenu->addAction(copyAct);
    topToolBar->addAction(copyAct);

    //剪切
    cutAct = new QAction(QIcon(":/resource/editcut.png"), "&Cut", this);
    cutAct->setShortcut(QKeySequence::Cut);
    editMenu->addAction(cutAct);
    topToolBar->addAction(cutAct);

    //粘贴
    pasteAct = new QAction(QIcon(":/resource/editpaste.png"), "&Paste", this);
    pasteAct->setShortcut(QKeySequence::Paste);
    editMenu->addAction(pasteAct);
    topToolBar->addAction(pasteAct);

    editMenu->addSeparator();

    //撤销
    undoAct = new QAction(QIcon(":/resource/editundo.png"), "&Undo", this);
    undoAct->setShortcut(QKeySequence::Undo);
    editMenu->addAction(undoAct);
    topToolBar->addAction(undoAct);

    //重做
    redoAct = new QAction(QIcon(":/resource/editredo.png"), "&Redo", this);
    redoAct->setShortcut(QKeySequence::Redo);
    editMenu->addAction(redoAct);
    topToolBar->addAction(redoAct);

    editMenu->addSeparator();

    //全选
    selectAllAct = new QAction(QIcon(":/resource/editselectall.png"), "&Select all", this);
    selectAllAct->setShortcut(QKeySequence::SelectAll);
    editMenu->addAction(selectAllAct);
    topToolBar->addAction(selectAllAct);

    //转为大写
    upperCaseAct = new QAction(QIcon(":/resource/uppercase.png"), "UpperCase", this);
    editMenu->addAction(upperCaseAct);
    topToolBar->addAction(upperCaseAct);

    //转为小写
    lowerCaseAct = new QAction(QIcon(":/resource/lowercase.png"), "LowerCase", this);
    editMenu->addAction(lowerCaseAct);
    topToolBar->addAction(lowerCaseAct);

    editMenu->addSeparator();

    //转到行
    gotoLineAct = new QAction(QIcon(":/resource/gotoline.png"), "Goto Line", this);
    gotoLineAct->setShortcut(Qt::CTRL + Qt::Key_G);
    editMenu->addAction(gotoLineAct);
    topToolBar->addAction(gotoLineAct);

    //查找
    findAct = new QAction(QIcon(":/resource/editfind.png"), "Find/Replace", this);
    findAct->setShortcut(QKeySequence::Find);
    editMenu->addAction(findAct);
    topToolBar->addAction(findAct);

    topToolBar->addSeparator();

    menuBar->addMenu(editMenu);
}

/* 格式菜单功能实现 */
void MainWindow::setupFormatMenu()
{
    formatMenu = new QMenu("&Format", menuBar);
    enCodingMenu = new QMenu("Encoding", formatMenu);

    //字体
    fontAct = new QAction(QIcon(":/resource/textfont.png"), "Font", formatMenu);
    topToolBar->addAction(fontAct);
    topToolBar->addSeparator();

    //UTF-8
    enCodingUTF8Act = new QAction("UTF-8", enCodingMenu);
    enCodingUTF8Act->setCheckable(true);
    enCodingUTF8Act->setChecked(true);

    //GB2312
    enCodingGB2312Act = new QAction("GB2312", enCodingMenu);
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
    buildMenu = new QMenu("&Build", menuBar);
    menuBar->addMenu(buildMenu);

    //编译
    compileAct = new QAction(QIcon(":/resource/compile.png"), "&Compile", this);
    buildMenu->addAction(compileAct);
    buildToolBar->addAction(compileAct);

    //部署
    deployAct = new QAction(QIcon(":/resource/deploy.png"), "&Deploy", this);
    buildMenu->addAction(deployAct);
    buildToolBar->addAction(deployAct);

    //运行
    runAct = new QAction(QIcon(":/resource/run.png"), "&Run", this);
    buildMenu->addAction(runAct);
    buildToolBar->addAction(runAct);
}

/* 窗口菜单功能实现 */
void MainWindow::setupWindowMenu()
{
    windowMenu = new QMenu("&Window", menuBar);

    //上一个窗口
    previousAct = new QAction(QIcon(":/resource/previous.png"), "Previous Window", windowMenu);
    previousAct->setShortcut(Qt::CTRL + Qt::Key_Left);
    windowMenu->addAction(previousAct);
    topToolBar->addAction(previousAct);

    //下一个窗口
    nextAct = new QAction(QIcon(":/resource/next.png"), "Next Window", windowMenu);
    nextAct->setShortcut(Qt::CTRL + Qt::Key_Right);
    windowMenu->addAction(nextAct);
    topToolBar->addAction(nextAct);

    //最近使用过的文件窗口
    recentlyFilesMenu = new QMenu("Recently Files", windowMenu);
    windowMenu->addMenu(recentlyFilesMenu);
    clearRecentlyAct = new QAction("Clear History", recentlyFilesMenu);
    recentlyFilesMenu->addAction(clearRecentlyAct);

    //当前所有窗口
    currentWindowsMenu = new QMenu("Current Windows", windowMenu);
    windowMenu->addMenu(currentWindowsMenu);
    topToolBar->addSeparator();
    menuBar->addMenu(windowMenu);
}

/* 帮助菜单功能实现 */
void MainWindow::setupHelpMenu()
{
    helpMenu = new QMenu("&Help", menuBar);

    //关于本软件
    aboutAct = new QAction(QIcon(":/resource/helpabout.png"), "About", this);
    helpMenu->addAction(aboutAct);
    topToolBar->addAction(aboutAct);

    menuBar->addMenu(helpMenu);
}

/* 工程栏右键菜单功能实现 */
void MainWindow::setupProjTree()
{
    menuRightBtnProjTree = new QMenu(this);

    addNewFileAct = new QAction("Add new gml files...", menuRightBtnProjTree);
    addExistingFileAct = new QAction("Add existing gml files...", menuRightBtnProjTree);
    menuRightBtnProjTree->addAction(addNewFileAct);
    menuRightBtnProjTree->addAction(addExistingFileAct);
    menuRightBtnProjTree->hide();

    menuRightBtnFileTree = new QMenu(this);
    addRemoveFileAct = new QAction("Remove this file", menuRightBtnFileTree);
    menuRightBtnFileTree->addAction(addRemoveFileAct);
    menuRightBtnFileTree->hide();

    this->projView->setMenuRightBtnProjTree(menuRightBtnProjTree);
    this->projView->setMenuRightBtnFileTree(menuRightBtnFileTree);
}

/* 文件菜单Action设置 */
void MainWindow::setupFileActions()
{
    connect(newProjAct, &QAction::triggered, this, &MainWindow::slotCreateProject);
    connect(openProjAct, &QAction::triggered, this, &MainWindow::slotOpenProject);
    connect(closeProjAct, &QAction::triggered, this, &MainWindow::slotCloseProject);
    connect(openAct, &QAction::triggered, this, &MainWindow::slotFileOpen);
    connect(newAct, &QAction::triggered, this, &MainWindow::slotFileNew);
    connect(saveAct, &QAction::triggered, this, &MainWindow::slotFileSave);
    connect(saveAsAct, &QAction::triggered, this, &MainWindow::slotFileSaveAs);
    connect(saveAllAct, &QAction::triggered, this, &MainWindow::slotFileSaveAll);
    connect(closeAct, &QAction::triggered, this, &MainWindow::slotFileClose);
    connect(closeAllAct, &QAction::triggered, this, &MainWindow::slotFileCloseAll);
    connect(exitAct, &QAction::triggered, this, &MainWindow::slotCloseWindow);
}

/* 编辑菜单Action设置 */
void MainWindow::setupEditActions()
{
    connect(undoAct, &QAction::triggered, this, &MainWindow::slotUndo);
    connect(redoAct, &QAction::triggered, this, &MainWindow::slotRedo);
    connect(cutAct, &QAction::triggered, this, &MainWindow::slotCut);
    connect(copyAct, &QAction::triggered, this, &MainWindow::slotCopy);
    connect(pasteAct, &QAction::triggered, this, &MainWindow::slotPaste);
    connect(selectAllAct, &QAction::triggered, this, &MainWindow::slotSelectAll);
    connect(upperCaseAct, &QAction::triggered, this, &MainWindow::slotToUpperCase);
    connect(lowerCaseAct, &QAction::triggered, this, &MainWindow::slotToLowerCase);
    connect(findAct, &QAction::triggered, this, &MainWindow::slotSearchAndReplace);
    connect(gotoLineAct, &QAction::triggered, this, &MainWindow::slotGotoLine);
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

/* 窗口菜单Action设置 */
void MainWindow::setupWindowActions()
{
    this->currentWindowsActionGrp = new QActionGroup(this);
    this->recentlyFilesActionGrp = new QActionGroup(this);
    connect(nextAct, &QAction::triggered, this, &MainWindow::slotNextTab);
    connect(previousAct, &QAction::triggered, this, &MainWindow::slotPrevTab);
    connect(currentWindowsMenu, &QMenu::aboutToShow, this, &MainWindow::slotCurrentWindows);
    connect(recentlyFilesMenu, &QMenu::aboutToShow, this, &MainWindow::slotRecentFiles);
    connect(clearRecentlyAct, &QAction::triggered, this, &MainWindow::slotClearRecentFiles);
}

/* 帮助Action设置 */
void MainWindow::setupHelpActions()
{
    connect(aboutAct, &QAction::triggered, this, &MainWindow::slotAbout);
}

/* 工程栏右键菜单Action设置 */
void MainWindow::setupProjTreeActions()
{
    connect(addNewFileAct, &QAction::triggered, this, &MainWindow::slotProjTreeAddNewFileClicked);
    connect(addExistingFileAct, &QAction::triggered, this, &MainWindow::slotProjTreeAddExistingFileClicked);
    connect(addRemoveFileAct, &QAction::triggered, this, &MainWindow::slotProjTreeRemoveFileClicked);
}

/* 根据文件路径打开文件 */
void MainWindow::openFileWithFilePath(QString filepath)
{
    if (filepath.isEmpty()) {
        return;
    }

    //判断该文件是否已经被打开?
    bool hasOpened = false;
    int index;
    for (int i = 0; i < tabInfoList.size(); i++) {
        if (tabInfoList[i].filePath == filepath) {
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

    //保存这个文件路径到最近打开文件列表
    gmlDataBase->insertRencentFileList(filepath);

    //创建一个新的tab
    Tab_Info_t tabInfo;
    tabInfo.notePadTab = new NotePadTab(tabWidget);
    tabInfo.notePadTab->setEncoding(this->enCoding);
    tabInfo.notePadTab->setLexerFont(this->font);
    tabInfo.notePadTab->setEditStatus(false);
    tabInfo.notePadTab->setFilePath(filepath);
    tabInfo.filePath = filepath;
    tabInfoList << tabInfo;

    //获取文件名
    QFileInfo info(filepath);
    QString title = info.fileName();

    //打开文件(用流的方式)
    QFile file(this);
    file.setFileName(filepath);
    bool ret = file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (ret == false) {
        QMessageBox::warning(this, "Error", "Open failed !");
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

/* 创建工程 */
void MainWindow::slotCreateProject()
{
    //从用户那里获取要创建的工程名, 所在路径
    if (createProjectDialog != nullptr) {
        delete createProjectDialog;
        createProjectDialog = nullptr;
    }
    createProjectDialog = new CreateProjectDialog();
    createProjectDialog->show();

    connect(createProjectDialog, &CreateProjectDialog::signalConfirmBtnClicked , [=]() {

        //创建工程
        bool isSuccess = projView->createProjFile(createProjectDialog->getProjectFilePath() + "/"
                                 + createProjectDialog->getProjectFileName() + ".gpro");
        if (isSuccess == true) {
            this->hasOpenProj = true;
        } else {
            this->hasOpenProj = false;
        }
    });
}

/* 打开工程 */
void MainWindow::slotOpenProject()
{
    QString gproPath = QFileDialog::getOpenFileName(this, "Select project...", ".",
             "gml project(*.gpro);;all(*.*)");

    if (gproPath.isEmpty() == false) {
        bool isSuccess = projView->openProjFile(gproPath);
        if (isSuccess == true) {
            this->hasOpenProj = true;
        } else {
            this->hasOpenProj = false;
        }
    }
}

/* 关闭工程 */
void MainWindow::slotCloseProject()
{
    projView->closeProjFile();
    this->hasOpenProj = false;
}

/* 打开文件 */
void MainWindow::slotFileOpen()
{
    QStringList filepaths = QFileDialog::getOpenFileNames(this, "Select files...", ".",
             "gml source(*.gml);;all(*.*)");

    for (int i = 0; i < filepaths.size(); i++) {
        openFileWithFilePath(filepaths[i]);
    }
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

    this->tabWidget->addTab(tabInfo.notePadTab, "new *");
    connect(tabInfo.notePadTab, &QsciScintilla::textChanged, tabInfo.notePadTab, &NotePadTab::slotContentChanged);
    connect(tabInfo.notePadTab, &NotePadTab::signalContentHasChanged, this, &MainWindow::slotNotePadContentChanged);

    //聚焦到刚刚新建的文件tab上
    this->tabWidget->setCurrentWidget(tabInfo.notePadTab);
    tabInfo.notePadTab->setFocus();

    //如果当前有打开的工程, 则提示是否添加到工程中
    if (hasOpenProj == true) {

        QMessageBox::StandardButton ret = QMessageBox::information(this, "Info", "Do you want to add this new file to the current project ?",
                                                                    QMessageBox::Yes | QMessageBox::No);
        if (ret == QMessageBox::Yes) {

            //获取保存路径
            QString filepath = QFileDialog::getSaveFileName(this, "Save file", ".", "gml source(*.gml);;all(*.*)");
            if (filepath.isEmpty() == true) {
                return;
            }

            disconnect(tabInfo.notePadTab, &QsciScintilla::textChanged, tabInfo.notePadTab, &NotePadTab::slotContentChanged);
            disconnect(tabInfo.notePadTab, &NotePadTab::signalContentHasChanged, this, &MainWindow::slotNotePadContentChanged);

            //保存这个文件路径到最近打开文件列表
            gmlDataBase->insertRencentFileList(filepath);

            //先获取当前活动的子窗体
            NotePadTab *notePadTabActive = static_cast<NotePadTab *>(this->tabWidget->currentWidget());
            int index = this->tabWidget->indexOf(notePadTabActive);

            //设置新的title
            tabInfo.notePadTab->setFilePath(filepath);
            tabInfo.notePadTab->setEditStatus(false);
            this->tabWidget->setTabText(index, tabInfo.notePadTab->getFileName());

            //修改list里面对应的文件路径
            for (int i = 0; i < tabInfoList.size(); i++) {
                if (tabInfoList[i].notePadTab == notePadTabActive) {
                    tabInfoList[i].filePath = filepath;
                    break;
                }
            }

            //创建文件
            QFile file(this);
            file.setFileName(filepath);
            bool ret = file.open(QIODevice::WriteOnly | QIODevice::Text);
            if (ret == false) {
                QMessageBox::warning(this, "Error", "Add failed !");
                return;
            }
            file.close();

            //左侧项目树添加节点
            projView->appendGmlFile(tabInfo.notePadTab->getFilePath());

            connect(tabInfo.notePadTab, &QsciScintilla::textChanged, tabInfo.notePadTab, &NotePadTab::slotContentChanged);
            connect(tabInfo.notePadTab, &NotePadTab::signalContentHasChanged, this, &MainWindow::slotNotePadContentChanged);
        }
    }
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
        QString tmpStr = "Save ";
        tmpStr.append(notePadTabActive->getFileName());

        QString filepath = QFileDialog::getSaveFileName(this, tmpStr, ".", "gml source(*.gml);;all(*.*)");
        if (filepath.isEmpty() == false) {

            //保存这个文件路径到最近打开文件列表
            gmlDataBase->insertRencentFileList(filepath);

            //把字窗口中的内容写进文件
            QFile file(this);
            file.setFileName(filepath);
            bool ret = file.open(QIODevice::WriteOnly | QIODevice::Text);
            if (ret == false) {
                QMessageBox::warning(this, "Error", "Save failed !");
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
            QMessageBox::information(this, "Info", "Save successfully !");

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
            QMessageBox::warning(this, "Error", "Save failed !");
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

    QString tmpStr = "Save As ";
    tmpStr = tmpStr.append(notePadTabActive->getFileName());
    QString filepath = QFileDialog::getSaveFileName(this, tmpStr, ".", "gml source(*.gml);;all(*.*)");
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
            QMessageBox::warning(this, "Error", "Save failed !");
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
        QMessageBox::information(this, "Info", "Save successfully !");
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
        QString tmpStr = "Save ";
        tmpStr.append(notePadTabActive->getFileName());
        tmpStr.append(" ?");
        QMessageBox::StandardButton ret = QMessageBox::information(this, "Info", tmpStr,
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
            QString tmpStr = "Save ";
            tmpStr.append(notePadTabActive->getFileName());
            tmpStr.append(" ?");
            QMessageBox::StandardButton ret = QMessageBox::information(this, "Info", tmpStr,
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

/* 转为大写 */
void MainWindow::slotToUpperCase()
{
    //根本没有打开的子窗体, 直接返回
    if (tabInfoList.isEmpty() == true) {
        return;
    }

    //先获取当前活动的子窗体
    NotePadTab *notePadTabActive = static_cast<NotePadTab *>(this->tabWidget->currentWidget());
    QString selectedStr = notePadTabActive->selectedText().toUpper();
    notePadTabActive->replaceSelectedText(selectedStr);
}

/* 转为小写 */
void MainWindow::slotToLowerCase()
{
    //根本没有打开的子窗体, 直接返回
    if (tabInfoList.isEmpty() == true) {
        return;
    }

    //先获取当前活动的子窗体
    NotePadTab *notePadTabActive = static_cast<NotePadTab *>(this->tabWidget->currentWidget());
    QString selectedStr = notePadTabActive->selectedText().toLower();
    notePadTabActive->replaceSelectedText(selectedStr);
}

/* 查找和替换 */
void MainWindow::slotSearchAndReplace()
{
    //根本没有打开的子窗体, 直接返回
    if (tabInfoList.isEmpty() == true) {
        return;
    }

    //先获取当前活动的子窗体
    NotePadTab *notePadTabActive = static_cast<NotePadTab *>(this->tabWidget->currentWidget());
    if (searchDialog != nullptr) {
        delete searchDialog;
        searchDialog = nullptr;
    }
    searchDialog = new SearchDialog(notePadTabActive);
    searchDialog->show();
}

/* 转到行 */
void MainWindow::slotGotoLine()
{
    //根本没有打开的子窗体, 直接返回
    if (tabInfoList.isEmpty() == true) {
        return;
    }

    //先获取当前活动的子窗体
    NotePadTab *notePadTabActive = static_cast<NotePadTab *>(this->tabWidget->currentWidget());
    if (gotolineDialog != nullptr) {
        delete gotolineDialog;
        gotolineDialog = nullptr;
    }
    gotolineDialog = new GotolineDialog(notePadTabActive);
    gotolineDialog->show();
    connect(gotolineDialog, &GotolineDialog::signalGoToLineDone, [=]() {
        delete gotolineDialog;
        gotolineDialog = nullptr;
    });
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

/* CurrentWindows */
void MainWindow::slotCurrentWindows()
{
    if (tabInfoList.isEmpty() == true) {
        return;
    }

    //先把之前的action清除掉
    QList<QAction *> actionList = currentWindowsMenu->actions();
    for (int i = 0; i < actionList.size(); i++) {
        currentWindowsActionGrp->removeAction(actionList[i]);
        delete actionList[i];
    }

    NotePadTab *currentNotePadTab = static_cast<NotePadTab *>(tabWidget->currentWidget());

    for (int i = 0; i < tabInfoList.size(); i++) {

        QFileInfo info(tabInfoList[i].filePath);
        QString title = info.fileName();
        QAction *actionItem = new QAction(title, currentWindowsMenu);
        actionItem->setCheckable(true);

        if (tabInfoList[i].notePadTab == currentNotePadTab) {
            actionItem->setChecked(true);
        }

        QVariant var = QVariant::fromValue(tabInfoList[i].notePadTab);
        actionItem->setProperty("notePadTab *", var);
        currentWindowsMenu->addAction(actionItem);
        currentWindowsActionGrp->addAction(actionItem);
    }

    connect(currentWindowsActionGrp, &QActionGroup::triggered, [=](QAction *triggeredAction) {
        QVariant var = triggeredAction->property("notePadTab *");
        NotePadTab *notePadTab = var.value<NotePadTab *>();
        tabWidget->setCurrentWidget(notePadTab);
    });
}

/* 最近打开文件 */
void MainWindow::slotRecentFiles()
{
    //从数据库里读取
    QStringList *recentFilePathList = gmlDataBase->readRencentFileList();
    if (recentFilePathList->isEmpty() == true) {

        recentlyFilesMenu->removeAction(clearRecentlyAct);

        //把之前的action清除掉
        QList<QAction *> actionList = recentlyFilesMenu->actions();
        for (int i = 0; i < actionList.size(); i++) {
            recentlyFilesActionGrp->removeAction(actionList[i]);
            delete actionList[i];
        }

        recentlyFilesMenu->addAction(clearRecentlyAct);
    }

    recentlyFilesMenu->removeAction(clearRecentlyAct);

    //先把之前的action清除掉
    QList<QAction *> actionList = recentlyFilesMenu->actions();
    for (int i = 0; i < actionList.size(); i++) {
        recentlyFilesActionGrp->removeAction(actionList[i]);
        delete actionList[i];
    }

    //遍历, 重新添加
    for (int i = 0; i < recentFilePathList->size(); i++) {
        QString filePath = recentFilePathList->at(i);
        QAction *actionItem = new QAction(filePath, recentlyFilesMenu);

        recentlyFilesActionGrp->addAction(actionItem);
        recentlyFilesMenu->addAction(actionItem);
    }

    recentlyFilesMenu->addSeparator();
    recentlyFilesMenu->addAction(clearRecentlyAct);

    connect(recentlyFilesActionGrp, &QActionGroup::triggered, [=](QAction *triggeredAction) {
        QString filepath = triggeredAction->text();
        openFileWithFilePath(filepath); //打开
    });
}

/* 清除最近打开文件记录 */
void MainWindow::slotClearRecentFiles()
{
    gmlDataBase->clearRencentFileList();
}

/* 关于本软件 */
void MainWindow::slotAbout()
{
    QMessageBox::about(this, "About", "This software is used to compile UAV cluster description language GML, "
                                      "all rights reserved by Northwestern Polytechnical University");
}

/* 工程树添加新文件 */
void MainWindow::slotProjTreeAddNewFileClicked()
{
    QString filepath = QFileDialog::getSaveFileName(this, "Add new file", ".", "gml source(*.gml);;all(*.*)");
    if (filepath.isEmpty() == true) {
        return;
    }

    //保存这个文件路径到最近打开文件列表
    gmlDataBase->insertRencentFileList(filepath);

    //创建一个新的tab
    Tab_Info_t tabInfo;
    tabInfo.notePadTab = new NotePadTab(tabWidget);
    tabInfo.notePadTab->setEncoding(this->enCoding);
    tabInfo.notePadTab->setLexerFont(this->font);
    tabInfo.notePadTab->setEditStatus(false);
    tabInfo.filePath = filepath;
    tabInfo.notePadTab->setFilePath(tabInfo.filePath);
    tabInfoList << tabInfo;

    this->tabWidget->addTab(tabInfo.notePadTab, tabInfo.notePadTab->getFileName());
    connect(tabInfo.notePadTab, &QsciScintilla::textChanged, tabInfo.notePadTab, &NotePadTab::slotContentChanged);
    connect(tabInfo.notePadTab, &NotePadTab::signalContentHasChanged, this, &MainWindow::slotNotePadContentChanged);

    //聚焦到刚刚新建的文件tab上
    this->tabWidget->setCurrentWidget(tabInfo.notePadTab);
    tabInfo.notePadTab->setFocus();

    //把窗口中的内容写进文件
    QFile file(this);
    file.setFileName(filepath);
    bool ret = file.open(QIODevice::WriteOnly | QIODevice::Text);
    if (ret == false) {
        QMessageBox::warning(this, "Error", "Add failed !");
        return;
    }
    file.close();

    //左侧项目树添加节点
    projView->appendGmlFile(tabInfo.notePadTab->getFilePath());
}

/* 工程树添加现有文件 */
void MainWindow::slotProjTreeAddExistingFileClicked()
{
    QStringList filepaths = QFileDialog::getOpenFileNames(this, "Add existing files...", ".",
             "gml source(*.gml);;all(*.*)");

    for (int i = 0; i < filepaths.size(); i++) {
        projView->appendGmlFile(filepaths[i]);
    }
}

/* 工程树移除文件 */
void MainWindow::slotProjTreeRemoveFileClicked()
{
    projView->removeGmlFile();
}

/* tab请求关闭 */
void MainWindow::slotTabRequestClose(int index)
{
    this->tabWidget->setCurrentIndex(index);
    this->slotFileClose();
}

/* tab被点击 */
void MainWindow::slotTabBarClicked(int index)
{
    //先获取当前活动的子窗体
    NotePadTab *notePadTabActive = static_cast<NotePadTab *>(this->tabWidget->widget(index));

    //选中左侧工程树中对应的文件
    projView->selectFileNodeAccordingFilePath(notePadTabActive->getFilePath());
}

/* 接收某个notePadTab内容改变的槽 */
void MainWindow::slotNotePadContentChanged(NotePadTab *notePadTab)
{
    int index = this->tabWidget->indexOf(notePadTab);
    QString tabStr = notePadTab->getFileName() + " *";
    this->tabWidget->setTabText(index, tabStr);
}
