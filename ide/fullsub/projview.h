#ifndef PROJVIEW_H
#define PROJVIEW_H

#include <QTreeView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QMouseEvent>
#include <QMenu>
#include <QDebug>

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

    void setMainWindow(MainWindow *);           //设置主窗口
    void setMenuRightBtnProjTree(QMenu *menuRightBtnProjTree); //设置menuRightBtnProjTree

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    QString proFilepath;                        //工程文件路径
    QStandardItemModel   *modelTree;            //树结构模型
    MainWindow *mainWindow;                     //主窗口
    QMenu *menuRightBtnProjTree;                //右键菜单

    void clearTreeView();                       //清空树显示
    bool refreshProjTreeView();                 //更新项目树结构显示

private slots:
    void slotTreeViewSingleClicked(const QModelIndex &index);   //treeView单击按钮槽函数
    void slotTreeViewDoubleClicked(const QModelIndex &index);   //treeView双击按钮槽函数
};

#endif // PROJVIEW_H
