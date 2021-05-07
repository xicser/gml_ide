#ifndef CONFIGMAINWINDOW_H
#define CONFIGMAINWINDOW_H


/* 标题栏 */
//标题栏高度H / 默认字体大小
#define TITLE_BAR_HEIGHT_DIV_DEF_FONT_SIZE                       (2.0)

//标题栏按钮宽度W / 标题栏宽度W
#define TITLE_BAR_BTN_WIDTH_DIV_TITLE_BAR_WIDTH                  (0.023)

//标题栏文本label宽度W / 标题栏宽度W
#define TITLE_BAR_TEXT_LABEL_WIDTH_DIV_TITLE_BAR_WIDTH           (0.4)

//标题栏式样
#define TITLE_BAR_QSS                                     "QWidget {background: rgb(75, 75, 75);}"

//标题栏左上角图标
#define TITLE_BAR_PIC                                     "QLabel {border-image:url(:/icon/mainwindow/resource/mainwindow/01-logo.png);}"

//标题栏文本label内容
#define TITLE_BAR_TEXT_LABEL                              " M++数控编制软件"

//标题栏文本label式样
#define TITLE_BAR_TEXT_LABEL_QSS                          "QLabel {color: white;}"

//退出按钮式样
#define TITLE_BAR_BTN_EXIT_QSS                            "QPushButton {border-image:url(:/icon/mainwindow/resource/mainwindow/22-close_1.png);}"\
                                                          "QPushButton:hover{border-image:url(:/icon/mainwindow/resource/mainwindow/22-close_2.png);}"\
                                                          "QPushButton:pressed{border-image:url(:/icon/mainwindow/resource/mainwindow/22-close_3.png);}"
//最小化按钮式样
#define TITLE_BAR_BTN_MIN_QSS                             "QPushButton {border-image:url(:/icon/mainwindow/resource/mainwindow/20-minimize_1.png);}"\
                                                          "QPushButton:hover{border-image:url(:/icon/mainwindow/resource/mainwindow/20-minimize_2.png);}"\
                                                          "QPushButton:pressed{border-image:url(:/icon/mainwindow/resource/mainwindow/20-minimize_3.png);}"
//还原按钮式样
#define TITLE_BAR_BTN_RESTORE_QSS                         "QLabel {border-image:url(:/icon/mainwindow/resource/mainwindow/21-restore_1.png);}"


/*菜单栏*/
//语言菜单样式
#define MENU_BAR_LANGUAGE                                 "QMenu{"\
                                                                "background:rgba(255,255,255,1);"\
                                                                "border:none;"\
                                                                "}"\
                                                          "QMenu::item{"\
                                                               "background-color: #FFFFFF;"\
                                                               "text-align:left;"\
                                                               "}"\
                                                          "QMenu::item:hover{"\
                                                               "background-color:#296ee1;"\
                                                               "color:#FFFFFF;"\
                                                               "}"\
                                                          "QMenu::item:selected{"\
                                                               "background-color:#296ee1;"\
                                                               "color:#FFFFFF;"\
                                                               "}"\
                                                          "QMenu::item:pressed{"\
                                                               "background-color:#296ee1;"\
                                                               "color:#FFFFFF;"\
                                                               "}"


//语言选择样式
#define MENU_BAR_LANGUAGE_ITEM                          "QLabel {"\
                                                                "width:90px;"\
                                                                "height:40px;"\
                                                                "padding-left:7px;"\
                                                                "}"\
                                                        "QLabel:hover{"\
                                                                "background-color:#296ee1;"\
                                                                "color:#FFFFFF;"\
                                                                "}"\


//语言选中样式
#define MENU_BAR_LANGUAGE_ITEM_CHOSEN                   "QLabel {"\
                                                                "padding-left:7px;"\
                                                                "background-color:#296ee1;"\
                                                                "color:#FFFFFF;"\
                                                                "}"



/* 工具栏 */
//工具栏高度H / 屏幕可用高度H
#define TOOL_BAR_HEIGHT_DIV_SCREEN_HEIGHT                 (0.032)

//工具栏杂项控件高度H / 工具栏高度H
#define TOOL_BAR_MISC_WIDGET_HEIGHT_DIV_TOOL_BAR_HEIGHT   (0.6)

//工具栏缩放下拉框左侧间距C / 屏幕可用宽度W
#define TOOL_BAR_COMBOBOX_LEFT_CLEARANCE_DIV_SCREEN_WIDTH (0.83)

//工具栏下拉框宽度W / 屏幕可用宽度W
#define TOOL_BAR_COMBOBOX_WIDTH_DIV_SCREEN_WIDTH          (0.05)

//工具栏缩放标签宽度W / 屏幕可用宽度W
#define TOOL_BAR_ZOOM_LABEL_WIDTH_DIV_SCREEN_WIDTH        (0.02)

//工具栏颜色示例标签宽度W / 屏幕可用宽度W
#define TOOL_BAR_COLOR_DEMO_LABEL_WIDTH_DIV_SCREEN_WIDTH  (0.05)

//工具栏颜色显示标签宽度W / 屏幕可用宽度W
#define TOOL_BAR_COLOR_DISP_LABEL_WIDTH_DIV_SCREEN_WIDTH  (0.05)

//工具栏各杂项控件之内间距C / 工具栏高度H
#define TOOL_BAR_MISC_WIDGET_INTERNAL_CLEARANCE_DIV_TOOL_BAR_HEIGHT (0.1)

//工具栏各杂项控件之外间距C / 工具栏高度H
#define TOOL_BAR_MISC_WIDGET_EXTERNAL_CLEARANCE_DIV_TOOL_BAR_HEIGHT (0.5)

//工具栏图标初始大小S / 默认字体大小S
#define TOOL_BAR_ICON_INIT_SIZE_DIV_DEF_FONT_SIZE                   (1.5)

//工具栏图标: 打开文件
#define TOOL_BAR_OPEN_FILE_PIC                            ":/icon/mainwindow/resource/mainwindow/02-openFile.png"

//工具栏图标: 另存为
#define TOOL_BAR_SAVE_AS_PIC                              ":/icon/mainwindow/resource/mainwindow/03-saveAs.png"

//工具栏图标: 作图
#define TOOL_BAR_PAINT_PIC                                ":/icon/mainwindow/resource/mainwindow/23-edit.png"

//工具栏图标: 后退
#define TOOL_BAR_UNDO_PIC                                 ":/icon/mainwindow/resource/mainwindow/04-undo.png"

//工具栏图标: 前进
#define TOOL_BAR_REDO_PIC                                 ":/icon/mainwindow/resource/mainwindow/05-redo.png"

//工具栏图标: 放大
#define TOOL_BAR_ZOOM_UP_PIC                              ":/icon/mainwindow/resource/mainwindow/06-zoomUp.png"

//工具栏图标: 缩小
#define TOOL_BAR_ZOOM_DOWN_PIC                            ":/icon/mainwindow/resource/mainwindow/07-zoomDown.png"

//工具栏图标: 显示恢复
#define TOOL_BAR_DISP_RESTORE_PIC                         ":/icon/mainwindow/resource/mainwindow/08-displayRestore.png"

//工具栏图标: 图形拖动
#define TOOL_BAR_PIC_DRAG_PIC                             ":/icon/mainwindow/resource/mainwindow/09-picDrag.png"

//工具栏图标: 正常操作
#define TOOL_BAR_NORMAL_OPT_PIC                           ":/icon/mainwindow/resource/mainwindow/10-normalOpt.png"

//工具栏图标: 关于
#define TOOL_BAR_ABOUT_PIC                                ":/icon/mainwindow/resource/mainwindow/11-about.png"




/* 左侧panel */
//左侧panel式样
#define PANEL_LEFT_OBJ_NAME                               "frameLeftPanel"
#define PANEL_LEFT_QSS                                    "#frameLeftPanel {background: #FFFFFF;"\
                                                          "border: none;}"

//左侧图层表格样式
#define PANEL_LEFT_LATER                                  "QTableWidget {"\
                                                                 "border:none;"\
                                                                 "border-bottom: 1px solid #959595;"\
                                                                 "border-right: 1px solid #959595;"\
                                                                 "selection-background-color: #296ee1;"\
                                                                 "}"



//左侧图形/缝纫点表格样式
#define PANEL_LEFT_GRAPHIC                                "QTableWidget {"\
                                                                 "border:none;"\
                                                                 "border-bottom: 1px solid #959595;"\
                                                                 "selection-background-color: #296ee1;"\
                                                                 "}"


//左侧panel中: 移动图层图形Frame式样
#define PANEL_LEFT_MOVE_LAYER_GRAPHIC_FRAME_QSS           "QFrame {background: #FFFFFF;}"

//左侧panel中: 移动距离GroupBox式样
#define PANEL_LEFT_MOVE_DISTANCE_GBOX_QSS                 "QGroupBox {"\
                                                              "border-color: #959595;"\
                                                              "border-width: 1px;"\
                                                              "border-style: solid;"\
                                                              "margin-top: 0.5ex;"\
                                                          "}"\
                                                          "QGroupBox::title {"\
                                                              "subcontrol-origin: margin;"\
                                                              "subcontrol-position: top left;"\
                                                              "left: 8px;"\
                                                              "margin-left: 2px;"\
                                                              "padding: 0  0px;"\
                                                              "font-family: PingFangSC-Regular, sans-serif;"\
                                                              "font-size: 14px;"\
                                                          "}"
//左侧panel中: 移动距离向上按钮式样
#define PANEL_LEFT_MOVE_DISTANCE_UP_BTN_QSS               "QPushButton {border-image:url(:/icon/mainwindow/resource/mainwindow/12-moveDistanceUp_1.png);}"\
                                                          "QPushButton:hover {border-image:url(:/icon/mainwindow/resource/mainwindow/12-moveDistanceUp_2.png);}"\
                                                          "QPushButton:pressed {border-image:url(:/icon/mainwindow/resource/mainwindow/12-moveDistanceUp_3.png);}"
//左侧panel中: 移动距离向下按钮式样
#define PANEL_LEFT_MOVE_DISTANCE_DOWN_BTN_QSS             "QPushButton {border-image:url(:/icon/mainwindow/resource/mainwindow/13-moveDistanceDown_1.png);}"\
                                                          "QPushButton:hover {border-image:url(:/icon/mainwindow/resource/mainwindow/13-moveDistanceDown_2.png);}"\
                                                          "QPushButton:pressed {border-image:url(:/icon/mainwindow/resource/mainwindow/13-moveDistanceDown_3.png);}"
//左侧panel中: 移动距离向左按钮式样
#define PANEL_LEFT_MOVE_DISTANCE_LEFT_BTN_QSS             "QPushButton {border-image:url(:/icon/mainwindow/resource/mainwindow/14-moveDistanceLeft_1.png);}"\
                                                          "QPushButton:hover {border-image:url(:/icon/mainwindow/resource/mainwindow/14-moveDistanceLeft_2.png);}"\
                                                          "QPushButton:pressed {border-image:url(:/icon/mainwindow/resource/mainwindow/14-moveDistanceLeft_3.png);}"
//左侧panel中: 移动距离向右按钮式样
#define PANEL_LEFT_MOVE_DISTANCE_RIGHT_BTN_QSS            "QPushButton {border-image:url(:/icon/mainwindow/resource/mainwindow/15-moveDistanceRight_1.png);}"\
                                                          "QPushButton:hover {border-image:url(:/icon/mainwindow/resource/mainwindow/15-moveDistanceRight_2.png);}"\
                                                          "QPushButton:pressed {border-image:url(:/icon/mainwindow/resource/mainwindow/15-moveDistanceRight_3.png);}"
//左侧panel中: 移动距离向删除按钮式样
#define PANEL_LEFT_MOVE_DISTANCE_DELETE_BTN_QSS           "QPushButton {border-image:url(:/icon/mainwindow/resource/mainwindow/16-moveDistanceDelete_1.png);}"\
                                                          "QPushButton:hover {border-image:url(:/icon/mainwindow/resource/mainwindow/16-moveDistanceDelete_2.png);}"\
                                                          "QPushButton:pressed {border-image:url(:/icon/mainwindow/resource/mainwindow/16-moveDistanceDelete_3.png);}"

//左侧panel中: 设置GroupBox式样
#define PANEL_LEFT_SETTING_GBOX_QSS                       PANEL_LEFT_MOVE_DISTANCE_GBOX_QSS

//左侧panel中: 变换GroupBox式样
#define PANEL_LEFT_TANSFORM_GBOX_QSS                      PANEL_LEFT_MOVE_DISTANCE_GBOX_QSS

//左侧panel中: 缝纫模式GroupBox式样
#define PANEL_LEFT_SEWING_MODE_GBOX_QSS                   PANEL_LEFT_MOVE_DISTANCE_GBOX_QSS


//左侧panel高度H / 屏幕可用高度H
#define PANEL_LEFT_HIGHT_DIV_SCREEN_HEIGHT                (0.9)

//左侧panel宽度W / 屏幕可用宽度W
#define PANEL_LEFT_WIDTH_DIV_SCREEN_WIDTH                 (0.17)

//左侧panel各个模块的间距C / PANEL高度H
#define PANEL_LEFT_MODULE_CLEARANCE_DIV_PANEL_LEFT_HEIGHT            (0.005)

//左侧panel中: 各个GroupBox宽度W / panel宽度W
#define PANEL_LEFT_GBOX_MODULE_WIDTH_DIV_PANEL_LEFT_WIDTH            (0.95)

//左侧panel中: 图形图层高度H / PANEL高度H
#define PANEL_LEFT_LAYER_GRAPHIC_HEIGHT_DIV_PANEL_LEFT_HEIGHT        (0.28)

//左侧panel中: 图层列宽W / 总列数宽度W
#define PANEL_LEFT_LAYER_COL_WIDTH_DIV_ALL_COLS_WIDTH                (0.4)

//左侧panel中: 移动图层图形高度H / PANEL高度H
#define PANEL_LEFT_MOVE_LAYER_GRAPHIC_HEIGHT_DIV_PANEL_LEFT_HEIGHT   (0.1)

//左侧panel中: 移动图层图形按钮宽度W / 按钮高度
#define PANEL_LEFT_MOVE_LAYER_GRAPHIC_MOVE_BTN_WIDTH_DIV_BTN_HEIGHT  (1.4)

//按钮宽度W / PANEL宽度W
#define PANEL_LEFT_BTN_WIDTH_DIV_PANEL_LEFT_WIDTH                    (0.4)

//按钮高度H / 移动图层图形高度H
#define PANEL_LEFT_BTN_HEIGHT_DIV_MOVE_LAYER_GRAPHIC_HEIGHT          (0.35)

//按钮水平间距C / 按钮宽度W
#define PANEL_LEFT_BTN_H_CLEARANCE_DIV_BTN_WIDTH                     (0.15)

//按钮竖直间距C / 按钮高度
#define PANEL_LEFT_BTN_V_CLEARANCE_DIV_BTN_HEIGHT                    (0.3)

//左侧panel中: 移动距离高度H / PANEL高度H
#define PANEL_LEFT_MOVE_DISTANCE_HEIGHT_DIV_PANEL_LEFT_HEIGHT        (0.13)

//左侧panel中: 移动距离lineEdit左侧间距C / GroupBox宽度W
#define PANEL_LEFT_MOVE_DISTANCE_LINEEDIT_LEFT_CLEARANE_DIV_GBOX_WIDTH          (0.05)

//左侧panel中: 移动距离lineEdit上侧间距C / PANEL高度H
#define PANEL_LEFT_MOVE_DISTANCE_LINEEDIT_TOP_CLEARANE_DIV_MOVE_DISTANCE_HEIGHT (0.2)

//左侧panel中: 设置高度H / PANEL高度H
#define PANEL_LEFT_SETTING_HEIGHT_DIV_PANEL_LEFT_HEIGHT              (0.17)

//左侧panel中: 编辑高度H / PANEL高度H
#define PANEL_LEFT_EDIT_HEIGHT_DIV_PANEL_LEFT_HEIGHT                 (0.08)

//左侧panel中: 变换高度H / PANEL高度H
#define PANEL_LEFT_TANSFORM_HEIGHT_DIV_PANEL_LEFT_HEIGHT             (0.12)

//左侧panel中: 缝纫模式高度H / PANEL高度H
#define PANEL_LEFT_SEWING_MODE_HEIGHT_DIV_PANEL_LEFT_HEIGHT          (0.12)



/*底部panel */
//底部panel式样
#define PANEL_BOTTOM_QSS_OBJ_NAME                                    "frameBottomPanel"
#define PANEL_BOTTOM_QSS                                             "#frameBottomPanel {background: #FFFFFF;"\
                                                                     "border: none;border-left:1px solid #959595;}"
//底部panel中: 最左侧间距C / 底部panel宽度W
#define PANEL_BOTTOM_LEFTEST_CLEARANE_DIV_PANEL_BOTTOM_WIDTH         (0.02)

//底部panel中: 可选控件间距C / 底部panel宽度W
#define PANEL_BOTTOM_CHECKABLE_CLEARANCE_DIV_PANEL_BOTTOM_WIDTH      (0.03)

//底部panel中: 最右侧间距C / 底部panel宽度W
#define PANEL_BOTTOM_RIGHTEST_CLEARANE_DIV_PANEL_BOTTOM_WIDTH        (0.01)

//底部panel中: 可选控件与label间距C / 底部panel宽度W
#define PANEL_BOTTOM_CHECKABLE_LABEL_CLEARANE_DIV_PANEL_BOTTOM_WIDTH (0.3)

//底部panel中: 版本号label宽度W / 底部panel宽度W
#define PANEL_BOTTOM_VERSION_LABEL_WIDTH_DIV_PANEL_BOTTOM_WIDTH      (0.15)

//底部panel中: 版本号
#define PANEL_BOTTOM_VERSION_LABEL                                   "版本号Ver 1.1(21-2-3)"




/* 画板 */
//画板式样
#define CANVAS_QSS_OBJ_NAME                                    "canvasView"
#define CANVAS_BOTTOM_QSS                                      "#canvasView {background: rgb(255, 255, 255);"\
                                                               "border: none;border-left:1px solid #959595;}"
//画板默认宽度
#define CANVAS_DEFAULT_WIDTH                                   (10000)

//画板默认高度
#define CANVAS_DEFAULT_HEIGHT                                  (10000)





/* 杂项 */
//颜色示例
#define MISC_COLOR_DEMO_QSS                                    "QLabel {background: black;}"






#endif // CONFIG_H

