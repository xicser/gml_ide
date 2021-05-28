#include "projview.h"
#include "fullscreen/mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDomDocument>
#include <QDomProcessingInstruction>
#include <QDomElement>
#include <QDebug>
#include <QDateTime>
#include <QFileInfo>

//树形结构叶子结点
typedef struct {
    QString name;
    QString path;
} TreeFileNode_t;
Q_DECLARE_METATYPE(TreeFileNode_t)

ProjView::ProjView(QWidget *parent) : QTreeView(parent)
{
    modelTree = new QStandardItemModel(this);
    this->setModel(modelTree);
    this->header()->setVisible(false);

    // 为treeView添加右键菜单
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &QTreeView::customContextMenuRequested, this, &ProjView::slotTreeViewMenuRequested);
    connect(this, &ProjView::clicked, this, &ProjView::slotTreeViewSingleClicked);
    connect(this, &ProjView::doubleClicked, this, &ProjView::slotTreeViewDoubleClicked);
}

QSize ProjView::sizeHint() const
{
    return QSize(200, 200); /* 在这里定义dock的初始大小 */
}

/* 创建gpro工程文件 */
bool ProjView::createProjFile(QString filepath)
{
    QFile file(filepath);
    if (file.exists()) {
        QMessageBox::warning(this, "Error", QString("Project file %1 already exists !").arg(filepath));
        return false;
    }

    //以只写方式打开文件
    bool isOK = file.open((QIODevice::WriteOnly));
    if (isOK == false) {
        QMessageBox::warning(this, "Error", QString("Project file %1 create failed !").arg(filepath));
        return false;
    }

    this->proFilepath = filepath;

    //创建xml文档
    QDomDocument doc;

    //创建xml头部格式(<?xml version="1.0" encoding="UTF-8"?>)
    QDomProcessingInstruction header;
    header = doc.createProcessingInstruction("xml", "version=\'1.0\' encoding=\'utf-8\'");

    //追加元素
    doc.appendChild(header);

    //追加根节点元素
    QDomElement root = doc.createElement(QString("preject"));
    doc.appendChild(root);
    QFileInfo info(this->proFilepath);
    QString title = info.fileName();
    //给根节点添加属性
    root.setAttribute("path", this->proFilepath);      //工程文件路径
    root.setAttribute("name", title);                  //工程文件名

    //保存
    QTextStream stream(&file);
    doc.save(stream, 4);

    file.close();

    //刷新工程树结构
    return refreshProjTreeView();
}

/* 打开gpro工程文件 */
bool ProjView::openProjFile(QString filepath)
{
    this->proFilepath = filepath;

    //刷新工程树结构
    return refreshProjTreeView();
}

/* 关闭gpro工程文件 */
void ProjView::closeProjFile()
{
    this->proFilepath.clear();
    this->clearTreeView();
}

/* 给工程中追加gml项目文件 */
bool ProjView::appendGmlFile(QString filepath)
{
    //先检查这个文件是否已经属于本工程
    if (isBelongToProj(filepath) == true) {
        QMessageBox::warning(this, "Error", QString("File %1 already belongs to this project !").arg(filepath));
        return false;
    }

    QFileInfo info(filepath);
    QString title = info.fileName();

    //关联
    QFile file(this->proFilepath);
    file.open(QIODevice::ReadOnly);
    QDomDocument doc;
    if (doc.setContent(&file) == false) {
        QMessageBox::warning(this, "Error", QString("Append gml file failed !"));
        return false;
    }
    file.close();

    //获取根节点元素
    QDomElement root = doc.documentElement();

    QDomElement child = doc.createElement(QString("gml"));
    child.setAttribute("path", filepath);
    child.setAttribute("name", title);
    root.appendChild(child);

    //保存文件
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);
    doc.save(stream, 4);
    file.close();

    //刷新工程树结构
    return refreshProjTreeView();
}

/* 从工程中移除gml项目文件 */
bool ProjView::removeGmlFile()
{
    QFile file(this->proFilepath);
    if (file.open(QIODevice::ReadOnly) == false) {
        QMessageBox::warning(this, "Error", QString("Remove file failed(1) !"));
        return false;
    }

    //文件file要和xml文档对象关联
    QDomDocument doc;
    if (doc.setContent(&file) == false) {
        QMessageBox::warning(this, "Error", QString("Remove file failed(2) !"));
        return false;
    }

    //关联成功后就可以关闭文件了
    file.close();

    //获取根节点元素
    QDomElement root = doc.documentElement();

    //判断有没有子节点
    if (root.hasChildNodes()) {

        //找到文件路径相同的那个节点, 从工程文件中删除它
        QDomNodeList list = root.childNodes();
        for (int i = 0; i < list.size(); i++) {

            QDomElement domElemt = list.at(i).toElement();
            if (domElemt.attribute("path") == currentSelectedFilePath) {
                root.removeChild(list.at(i));

                //保存文件
                file.open(QIODevice::WriteOnly);
                QTextStream stream(&file);
                doc.save(stream, 4);
                file.close();
                break;
            }
        }
    }

    //刷新工程树结构
    return refreshProjTreeView();
}

/* 根据文件路径, 选中对应的文件节点 */
void ProjView::selectFileNodeAccordingFilePath(QString filepath)
{
    //先清除之前的选中情况
    this->selectionModel()->clear();

    //遍历根节点下的所有节点
    QStandardItem *itemRoot = modelTree->item(0);

    for (int i = 0; i < itemRoot->rowCount(); i++) {

        QStandardItem *childitem = itemRoot->child(i);
        TreeFileNode_t fileNode;
        fileNode = childitem->data(Qt::UserRole + 1).value<TreeFileNode_t>();

        //找到这个节点
        if (fileNode.path == filepath) {
            QModelIndex headModelIndex = childitem->model()->index(i, 0, itemRoot->index());
            QModelIndex tailModelIndex = childitem->model()->index(i, 0, itemRoot->index());

            QItemSelectionModel *selectionModel = this->selectionModel();
            QItemSelection itemSelection(headModelIndex, tailModelIndex);
            selectionModel->select(itemSelection, QItemSelectionModel::Select);

            break;
        }
    }
    this->expandAll();
}

/* 获取本工程文件路径列表 */
QStringList ProjView::getProjFilePaths()
{
    QStringList pathList;

    QFile file(this->proFilepath);
    file.open(QIODevice::ReadOnly);

    //文件file要和xml文档对象关联
    QDomDocument doc;
    doc.setContent(&file);

    //关联成功后就可以关闭文件了
    file.close();

    //获取根节点元素
    QDomElement root = doc.documentElement();

    //判断有没有子节点
    if (root.hasChildNodes()) {

        //遍历所有子节点
        QDomNodeList list = root.childNodes();
        for (int i = 0; i < list.size(); i++) {

            QDomElement domElemt = list.at(i).toElement();
            pathList << domElemt.attribute("path");
        }
    }

    return pathList;
}

/* 设置主窗口 */
void ProjView::setMainWindow(MainWindow *mainWindow)
{
    this->mainWindow = mainWindow;
}

/* 设置menuRightBtnProjTree */
void ProjView::setMenuRightBtnProjTree(QMenu *menuRightBtnProjTree)
{
    this->menuRightBtnProjTree = menuRightBtnProjTree;
}

/* 设置menuRightBtnFileTree */
void ProjView::setMenuRightBtnFileTree(QMenu *menuRightBtnFileTree)
{
    this->menuRightBtnFileTree = menuRightBtnFileTree;
}

/* 更新项目树结构显示 */
bool ProjView::refreshProjTreeView()
{
    //先清空之前的显示
    clearTreeView();

    QFile file(this->proFilepath);
    if (file.open(QIODevice::ReadOnly) == false) {
        QMessageBox::warning(this, "Error", QString("Refresh project tree view failed(1) !"));
        return false;
    }

    //文件file要和xml文档对象关联
    QDomDocument doc;
    if (doc.setContent(&file) == false) {
        QMessageBox::warning(this, "Error", QString("Refresh project tree view failed(2) !"));
        return false;
    }

    //关联成功后就可以关闭文件了
    file.close();

    //获取根节点元素
    QDomElement root = doc.documentElement();

    //添加工程根节点
    QStandardItem *proTopNode = new QStandardItem(QIcon(":/resource/notepad.png"), root.attribute("name"));
    proTopNode->setEditable(false);
    modelTree->appendRow(proTopNode);

    //判断有没有子节点
    if (root.hasChildNodes()) {

        //找出当前日期下所有时间子节点
        QDomNodeList list = root.childNodes();
        for (int i = 0; i < list.size(); i++) {

            QDomElement domElemt = list.at(i).toElement();

            //添加文件节点
            QStandardItem *proFileNode = new QStandardItem(QIcon(":/resource/filenew.png"), domElemt.attribute("name"));

            //给这个叶子结点设置数据
            TreeFileNode_t fileNode;
            fileNode.name = domElemt.attribute("name");
            fileNode.path = domElemt.attribute("path");
            QVariant variant;
            variant.setValue(fileNode);
            proFileNode->setData(variant, Qt::UserRole + 1);
            proFileNode->setEditable(false);
            proTopNode->appendRow(proFileNode);
        }
    }

    this->expandAll();

    return true;
}

/* 检查当前文件是否已经在工程中 */
bool ProjView::isBelongToProj(QString filepath)
{
    QFile file(this->proFilepath);
    file.open(QIODevice::ReadOnly);

    //文件file要和xml文档对象关联
    QDomDocument doc;
    doc.setContent(&file);

    //关联成功后就可以关闭文件了
    file.close();

    //获取根节点元素
    QDomElement root = doc.documentElement();

    //判断有没有子节点
    if (root.hasChildNodes()) {

        //遍历所有子节点
        QDomNodeList list = root.childNodes();
        for (int i = 0; i < list.size(); i++) {

            QDomElement domElemt = list.at(i).toElement();
            if (domElemt.attribute("path") == filepath) {
                return true;
            }
        }
    }

    return false;
}

/* 清空树显示 */
void ProjView::clearTreeView()
{
    int rowCnt = modelTree->rowCount();
    int colCnt = modelTree->columnCount();
    for (int i = 0; i < rowCnt; i++) {
        for (int j = 0; j < colCnt; j++) {
            QStandardItem *standardItem = modelTree->takeItem(i, j);
            delete standardItem;
        }
    }

    modelTree->clear();
}

/* 菜单请求 */
void ProjView::slotTreeViewMenuRequested(const QPoint &pos)
{
    QModelIndex curIndex = this->indexAt(pos);
    TreeFileNode_t fileNode;
    fileNode = curIndex.data(Qt::UserRole + 1).value<TreeFileNode_t>();
    currentSelectedFilePath = fileNode.path;

    //右键选中了有效index
    if (curIndex.isValid()) {
        QString text = curIndex.data().toString();

        //右键单击在工程节点上
        if (text.contains("gpro") == true) {
            menuRightBtnProjTree->exec(QCursor::pos());
            return;
        }
        //右键单击在文件节点上
        if (text.contains("gpro") == false) {
            menuRightBtnFileTree->exec(QCursor::pos());
            return;
        }
    }
}

/* treeView单击按钮槽函数 */
void ProjView::slotTreeViewSingleClicked(const QModelIndex &index)
{
    QString text = index.data().toString();

    //左键单击在文件节点上
    if (text.contains("gpro") == false) {
        TreeFileNode_t fileNode;
        fileNode = index.data(Qt::UserRole + 1).value<TreeFileNode_t>();

        //跳转到这个文件对应的tab
        mainWindow->jumpToTabAccordingFilePath(fileNode.path);
    }

    TreeFileNode_t fileNode;
    fileNode = index.data(Qt::UserRole + 1).value<TreeFileNode_t>();
    currentSelectedFilePath = fileNode.path;
}

/* treeView双击按钮槽函数 */
void ProjView::slotTreeViewDoubleClicked(const QModelIndex &index)
{
    QString text = index.data().toString();

    //工程根节点不处理
    if (text.contains("gpro") == true) {
        return;
    }

    TreeFileNode_t fileNode;
    fileNode = index.data(Qt::UserRole + 1).value<TreeFileNode_t>();
    currentSelectedFilePath = fileNode.path;

    //打开这个文件
    mainWindow->openFileWithFilePath(fileNode.path);
}
