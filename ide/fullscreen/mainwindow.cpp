#include "mainwindow.h"
#include "config/configmainwin.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    dataInit();
    mainWindowInit();
    menuBarInit();
    toolBarInit();

    changeControllerSize(QSize(screenXSize, screenYSize));
    setWindowState(Qt::WindowMaximized);  //全屏
}

MainWindow::~MainWindow()
{

}

/* 数据初始化 */
void MainWindow::dataInit(void)
{
//    openedfileType = "null";
//    openedfilePath = "null";
//    isShowSerialNumber = false;
//    showAllLayer = true;

//    designWindow = nullptr;
//    changeLayerWindow = nullptr;
//    shapeCloneWindow = nullptr;
//    editShapeWindow = nullptr;
//    massOperatingWindow = nullptr;
//    layerParameterSetWindow = nullptr;
//    sewingSimulationWindow = nullptr;
//    specialSewingWindow = nullptr;
//    zigzagNeedleWindow = nullptr;
//    sewingPointCodeWindow = nullptr;
//    setBasePointWindow = nullptr;
//    translator = nullptr;
//    changeShapeSizeWindow = nullptr;
//    spacingOfClosedShapeWindow = nullptr;
//    aboutWindow = nullptr;
//    warningChinese = nullptr;
//    warningEnglish = nullptr;
//    warningItalian = nullptr;
//    warningJapanese = nullptr;
//    warningRussian = nullptr;
//    warningSpanish = nullptr;
//    warningTurkish = nullptr;
//    warningVietnam = nullptr;
}

/* 初始化主窗口 */
void MainWindow::mainWindowInit(void)
{
    //获取除去任务栏的窗口大小
    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect clientRect = desktopWidget->availableGeometry();
    screenXSize = clientRect.width() * 0.75;
    screenYSize = clientRect.height() * 0.8;

    setWindowIcon(QIcon(":/icon/mainwindow/resource/mainwindow/01_logo14x14.png"));
    this->resize(screenXSize, screenYSize);     //设置窗体大小
    setMinimumSize(screenXSize * 0.85, screenYSize * 0.85);       //设置窗口最小大小
    setWindowTitle(tr("TITLE_BAR_TEXT_LABEL"));
}

/* 菜单栏初始化 */
void MainWindow::menuBarInit(void)
{
    QFont font;
    QFontInfo fontInfo(font);
    fontSize = fontInfo.pixelSize();  //获取默认字体大小

    menuBarHeight = fontSize * TITLE_BAR_HEIGHT_DIV_DEF_FONT_SIZE;;        //菜单栏高度

    menuBar = new QMenuBar(this);
    menuBar->setGeometry(0, 0, screenXSize, menuBarHeight);

    menuFile = new QMenu(menuBar);                                          //文件菜单
    menuFile->setTitle(tr("文件(&F)"));
    menuBar->addMenu(menuFile);
        actionNew = new QAction(tr("新建(&N)"), menuFile);
        actionOpen = new QAction(tr("打开(&O)"), menuFile);
        actionSave = new QAction(tr("保存(&S)"), menuFile);
        actionSaveAs = new QAction(tr("另存为(&A)"), menuFile);
        actionExit = new QAction(tr("退出(&N)"), menuFile);
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

    menuEdit = new QMenu(menuBar);                                          //编辑菜单
    menuEdit->setTitle(tr("编辑(&E)"));
    menuBar->addMenu(menuEdit);
        actionUndo = new QAction(tr("撤销(&U)"), menuEdit);
        actionRedo = new QAction(tr("重做(&R)"), menuEdit);
        actionCut = new QAction(tr("剪切(&T)"), menuEdit);
        actionCopy = new QAction(tr("复制(&C)"), menuEdit);
        actionPaste = new QAction(tr("粘贴(&P)"), menuEdit);
        menuEncoding = new QMenu(tr("编码格式(&S)"), menuEdit);
        actionUTF8 = new QAction(tr("UTF-8"), menuEncoding);
        actionGB2312 = new QAction(tr("GB2312"), menuEncoding);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addMenu(menuEncoding);
        menuEncoding->addAction(actionUTF8);
        menuEncoding->addAction(actionGB2312);

    menuWindow = new QMenu(menuBar);                                          //窗口菜单
    menuWindow->setTitle(tr("窗口(&W)"));
    menuBar->addMenu(menuWindow);
        actionClose = new QAction(tr("关闭(&C)"), menuWindow);
        actionCloseAll = new QAction(tr("关闭所有(&U)"), menuWindow);
        actionNext = new QAction(tr("下一个(&N)"), menuWindow);
        actionPrev = new QAction(tr("上一个(&P)"), menuWindow);
        menuWindow->addAction(actionClose);
        menuWindow->addAction(actionCloseAll);
        menuWindow->addSeparator();
        menuWindow->addAction(actionNext);
        menuWindow->addAction(actionPrev);

    MenuHelp = new QMenu(menuBar);    //帮助菜单
    MenuHelp->setTitle(tr("帮助(&H)"));
    menuBar->addMenu(MenuHelp);
        actionAbout = new QAction(tr("关于(&A)"), MenuHelp);
        MenuHelp->addAction(actionAbout);

    //设置式样
    menuFile->setStyleSheet(MENU_BAR_LANGUAGE);
    menuEdit->setStyleSheet(MENU_BAR_LANGUAGE);
    menuWindow->setStyleSheet(MENU_BAR_LANGUAGE);
    MenuHelp->setStyleSheet(MENU_BAR_LANGUAGE);
}

/* 工具栏初始化 */
void MainWindow::toolBarInit(void)
{
    toolBar = new QToolBar(this);
    toolBar->setMovable(false);

    //按钮
    toolBtnOpenFile = new QToolButton(toolBar);                      //打开文件
    toolBtnSaveAs = new QToolButton(toolBar);                        //另存为按钮
    toolBtnUndo = new QToolButton(toolBar);                          //撤销
    toolBtnRedo = new QToolButton(toolBar);                          //重做
    toolBtnBuild = new QToolButton(toolBar);                         //构建
    toolBtnRun = new QToolButton(toolBar);                           //运行
    toolBtnAbout = new QToolButton(toolBar);                         //关于

    QToolButton *toolBtns[7] = {
        toolBtnOpenFile,
        toolBtnSaveAs,
        toolBtnUndo,
        toolBtnRedo,
        toolBtnBuild,
        toolBtnRun,
        toolBtnAbout
    };
    QString strs[7] = {tr("打开(O)"), tr("另存为(S)"), tr("撤销"), tr("重做"), tr("构建"), tr("运行"), tr("关于")};
    QString pics[7] = {TOOL_BAR_OPEN_FILE_PIC, TOOL_BAR_SAVE_AS_PIC,
                            TOOL_BAR_UNDO_PIC, TOOL_BAR_REDO_PIC,
                            TOOL_BAR_PIC_DRAG_PIC, TOOL_BAR_NORMAL_OPT_PIC, TOOL_BAR_ABOUT_PIC};
    //最左边那个按钮的位置
    int x = 0;
    int picWidth = fontSize * TOOL_BAR_ICON_INIT_SIZE_DIV_DEF_FONT_SIZE;
    int width;

    for (int i = 0; i < 7; i++) {

        int len = strs[i].length();

        if (len == 5 || len == 6) {
            width = fontSize * len + picWidth;
        }
        else {
            width = fontSize * (len + 2) + picWidth;
        }

        toolBtns[i]->setText(strs[i]);
        toolBtns[i]->setIcon(QIcon(pics[i]));
        toolBtns[i]->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        x += width;
    }
}

/* 移动工具栏位置 */
void MainWindow::moveToolBarPosition(void)
{
    toolBarHeight = screenYSize * TOOL_BAR_HEIGHT_DIV_SCREEN_HEIGHT;            //工具栏高度

    toolBar->setGeometry(0, menuBarHeight, screenXSize, toolBarHeight);

    QToolButton *toolBtns0[7] = {toolBtnOpenFile, toolBtnSaveAs, toolBtnUndo,
        toolBtnRedo, toolBtnBuild, toolBtnRun, toolBtnAbout};
    QString strs[7] = {tr("打开(O)"), tr("另存为(S)"), tr("撤销"), tr("重做"), tr("构建"), tr("运行"), tr("关于")};

    int x = 0, y = 0;
    int picWidth = fontSize * TOOL_BAR_ICON_INIT_SIZE_DIV_DEF_FONT_SIZE;
    int width, height = toolBarHeight;
    for (int i = 0; i < 7; i++) {
        int len = strs[i].length();
        if (len == 5 || len == 6) {
            width = fontSize * len + picWidth;
        }
        else {
            width = fontSize * (len + 2) + picWidth;
        }
        toolBtns0[i]->setGeometry(x, y, width, height);
        x += width;
    }
}


/* 改变控件大小 */
void MainWindow::changeControllerSize(QSize size)
{
    //界面大小
    screenXSize = size.width();
    screenYSize = size.height();
    resize(screenXSize, screenYSize);

    //菜单
    menuBar->setGeometry(0, 0, screenXSize, menuBarHeight);

    //工具栏
    moveToolBarPosition();

//    //左侧操作panel
//    moveLeftPanelPosition();
//    //左侧panel图形图层
//    moveLeftPanelLayerGraphicScroll();
//    //左侧panel移动图层图形Frame
//    moveLeftPanelMoveLayerGraphicFrame();
//    //左侧panel移动距离
//    moveLeftPanelMoveDistance();
//    //左侧panel设置
//    moveLeftPanelSetting();
//    //左侧panel变换
//    moveLeftPanelTransform();
//    //左侧panel缝纫模式
//    moveLeftPanelSewingMode();

//    //画板
//    int x = leftPanelWidth;                               //位置
//    int y = menuBarHeight + toolBarHeight;
//    canvasViewWidth = screenXSize - leftPanelWidth;       //画板view宽度
//    canvasViewHeight = screenYSize * 0.83;    //画板view高度
//    canvasViewPattern->setGeometry(x, y, canvasViewWidth, canvasViewHeight); //设置位置

//    //状态栏
//    statusBarWidth = screenXSize - leftPanelWidth;
//    statusBarHeight = toolBarHeight;        //状态栏高度等于工具栏高度
//    x = leftPanelWidth;
//    y = menuBarHeight + toolBarHeight + screenYSize * 0.83;
//    lineEditStatusBar->setGeometry(x, y, statusBarWidth, statusBarHeight);

//    //底部操作panel
//    moveBottomPanel();

//    //剩余杂项控件
//    moveMiscWidget();
}


/* 变换事件 */
void MainWindow::changeEvent(QEvent *event)
{
    //窗口状态改变，改变窗口size
    if (event->type() == QEvent::WindowStateChange) {
        if (this->windowState() != Qt::WindowMinimized) {
            changeControllerSize(this->size());
        }
    }
}

/* 重画大小事件 */
void MainWindow::resizeEvent(QResizeEvent *)
{
    changeControllerSize(this->size());
}
