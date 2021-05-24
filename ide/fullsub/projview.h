#ifndef PROJVIEW_H
#define PROJVIEW_H

#include <QTreeView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QMouseEvent>
#include <QMenu>
#include <QDebug>

//树形结构一级结点
typedef struct {
    int layerId;
    QStandardItem *item;
    QList<QStandardItem *> subItemsList;
} TreeNodeFirst_t;

//树形结构叶子结点
typedef struct {
    int layerId;
    int itemId;
} TreeLeafNode_t;
Q_DECLARE_METATYPE(TreeLeafNode_t)

class ProjView : public QTreeView
{
    Q_OBJECT
public:
    ProjView(QWidget *parent);
    QSize sizeHint() const;

    void createProjFile(QString filepath);      //创建gpro工程文件
    void openProjFile(QString filepath);        //打开gpro工程文件
    void closeProjFile();                       //关闭gpro工程文件
    void appendGmlFile(QString filepath);       //给工程中追加gml项目文件

private:
    QString proFilepath;                        //工程文件路径
    QStandardItemModel   *modelTree;            //树结构模型

    void clearTreeView();                       //清空树显示
    void refreshProjTreeView();                 //更新项目树结构显示

};

#endif // PROJVIEW_H
