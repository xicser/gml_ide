#ifndef PROJVIEW_H
#define PROJVIEW_H

#include <QTreeView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QMouseEvent>
#include <QMenu>
#include <QDebug>
#include <QStringList>

class MainWindow;
class ProjView : public QTreeView
{
    Q_OBJECT
public:
    ProjView(QWidget *parent);
    QSize sizeHint() const;

    bool createProjFile(QString filepath);      //创建gpro工程文件
    bool openProjFile(QString filepath);        //打开gpro工程文件
    void closeProjFile();                       //关闭gpro工程文件
    bool appendGmlFile(QString filepath);       //给工程中追加gml项目文件
    bool removeGmlFile();                       //从工程中移除gml项目文件

    void selectFileNodeAccordingFilePath(QString);   //根据文件路径, 选中对应的文件节点
    QStringList getProjFilePaths();             //获取本工程文件路径列表

    void setMainWindow(MainWindow *);           //设置主窗口
    void setMenuRightBtnProjTree(QMenu *menuRightBtnProjTree); //设置menuRightBtnProjTree
    void setMenuRightBtnFileTree(QMenu *menuRightBtnFileTree); //设置menuRightBtnFileTree

private:
    QString proFilepath;                        //工程文件路径
    QString currentSelectedFilePath;            //当前选中文件节点的路径
    QStandardItemModel   *modelTree;            //树结构模型
    MainWindow *mainWindow;                     //主窗口
    QMenu *menuRightBtnProjTree;                //右键工程菜单
    QMenu *menuRightBtnFileTree;                //右键文件菜单

    bool isBelongToProj(QString filepath);      //检查当前文件是否已经在工程中
    void clearTreeView();                       //清空树显示
    bool refreshProjTreeView();                 //更新项目树结构显示

private slots:
    void slotTreeViewMenuRequested(const QPoint &pos);          //菜单请求
    void slotTreeViewSingleClicked(const QModelIndex &index);   //treeView单击按钮槽函数
    void slotTreeViewDoubleClicked(const QModelIndex &index);   //treeView双击按钮槽函数
};

#endif // PROJVIEW_H
