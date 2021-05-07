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

    menuLanguage = new QMenu(menuBar);                                      //语言菜单
    menuEdit = new QMenu(menuBar);                                          //编辑菜单
    menuOpt = new QMenu(menuBar);                                           //选项菜单

    QString str = tr("语言");
    menuLanguage->setTitle(str+"▼");
    menuBar->addMenu(menuLanguage);

    menuEdit = menuBar->addMenu(tr("编辑(&Y)"));
    actionChangeSize = menuEdit->addAction(tr("改变大小(&Z)"));

    menuOpt = menuBar->addMenu(tr("选项(&Z)"));
    actionAutoMergeNearGraphic = menuOpt->addAction(tr("打开文件时, 自动合并临近图形(&Y)"));
    actionAutoMergeNearGraphic->setCheckable(true);
    actionAutoMergeNearGraphic->setChecked(true);
    actionOpenNtp = menuOpt->addAction(tr("打开NTP文件时, 图形绝对坐标不变（用于免基准）(&N)"));
    actionOpenNtp->setCheckable(true);
    actionOpenNtp->setChecked(true);
    actionCloseGraphic = menuOpt->addAction(tr("封闭图形首尾间距(&Z)"));

    actionPaint = menuBar->addAction(tr("作图(&D)"));

    menuLanguage->setStyleSheet(MENU_BAR_LANGUAGE);
    menuEdit->setStyleSheet(MENU_BAR_LANGUAGE);
    menuOpt->setStyleSheet(MENU_BAR_LANGUAGE);
}

/* 工具栏初始化 */
void MainWindow::toolBarInit(void)
{
    toolBar = new QToolBar(this);
    toolBar->setMovable(false);

    //按钮
    toolBtnOpenFile = new QToolButton(toolBar);                      //打开文件
    toolBtnSaveAs = new QToolButton(toolBar);                        //另存为按钮
    toolBtnUndo = new QToolButton(toolBar);                          //后退
    toolBtnRedo = new QToolButton(toolBar);                          //前进
    toolBtnZoomUp = new QToolButton(toolBar);                        //放大
    toolBtnZoomDown = new QToolButton(toolBar);                      //缩小
    toolBtnDispRestore = new QToolButton(toolBar);                   //显示恢复
    toolBtnPicDrag = new QToolButton(toolBar);                       //图片拖动
    toolBtnNormalOpt = new QToolButton(toolBar);                     //正常操作
    toolBtnAbout = new QToolButton(toolBar);                         //关于

    QToolButton *toolBtns[10] = {
        toolBtnOpenFile,
        toolBtnSaveAs,
        toolBtnUndo,
        toolBtnRedo,
        toolBtnZoomUp,
        toolBtnZoomDown,
        toolBtnDispRestore,
        toolBtnPicDrag,
        toolBtnNormalOpt,
        toolBtnAbout
    };
    QString strs[10] = {tr("打开(O)"), tr("另存为(S)"), tr("后退"), tr("前进"), tr("放大"), tr("缩小"), tr("显示恢复"), tr("图形拖动"), tr("正常操作"), tr("关于")};
    QString pics[10] = {TOOL_BAR_OPEN_FILE_PIC, TOOL_BAR_SAVE_AS_PIC,
                            TOOL_BAR_UNDO_PIC, TOOL_BAR_REDO_PIC,
                            TOOL_BAR_ZOOM_UP_PIC, TOOL_BAR_ZOOM_DOWN_PIC,
                            TOOL_BAR_DISP_RESTORE_PIC, TOOL_BAR_PIC_DRAG_PIC,
                            TOOL_BAR_NORMAL_OPT_PIC, TOOL_BAR_ABOUT_PIC};
    //最左边那个按钮的位置
    int x = 0;
    int picWidth = fontSize * TOOL_BAR_ICON_INIT_SIZE_DIV_DEF_FONT_SIZE;
    int width;

    for (int i = 0; i < 10; i++) {

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

    QToolButton *toolBtns0[10] = {toolBtnOpenFile, toolBtnSaveAs, toolBtnUndo,
        toolBtnRedo, toolBtnZoomUp, toolBtnZoomDown, toolBtnDispRestore, toolBtnPicDrag,
        toolBtnNormalOpt, toolBtnAbout};
    QString strs[10] = {tr("打开(O)"), tr("另存为(S)"), tr("后退"), tr("前进"), tr("放大"), tr("缩小"), tr("显示恢复"), tr("图形拖动"), tr("正常操作"), tr("关于")};

    int x = 0, y = 0;
    int picWidth = fontSize * TOOL_BAR_ICON_INIT_SIZE_DIV_DEF_FONT_SIZE;
    int width, height = toolBarHeight;
    for (int i = 0; i < 10; i++) {
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
