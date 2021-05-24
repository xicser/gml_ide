#include "projview.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDomDocument>
#include <QDomProcessingInstruction>
#include <QDomElement>
#include <QDebug>
#include <QDateTime>
#include <QFileInfo>


ProjView::ProjView(QWidget *parent) : QTreeView(parent)
{
    modelTree = new QStandardItemModel(this);
    this->setModel(modelTree);
    this->header()->setVisible(false);
}

QSize ProjView::sizeHint() const
{
    return QSize(200, 200); /* 在这里定义dock的初始大小 */
}

/* 创建gpro工程文件 */
void ProjView::createProjFile(QString filepath)
{
    QFile file(filepath);
    if (file.exists()) {
        QMessageBox::warning(this, "Error", QString("Project file %1 already exists !").arg(filepath));
        return;
    }

    //以只写方式打开文件
    bool isOK = file.open((QIODevice::WriteOnly));
    if (isOK == false) {
        QMessageBox::warning(this, "Error", QString("Project file %1 create failed !").arg(filepath));
        return;
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
    refreshProjTreeView();
}

/* 打开gpro工程文件 */
void ProjView::openProjFile(QString filepath)
{
    this->proFilepath = filepath;

    //刷新工程树结构
    refreshProjTreeView();
}

/* 关闭gpro工程文件 */
void ProjView::closeProjFile()
{
    this->clearTreeView();
}

/* 给工程中追加gml项目文件 */
void ProjView::appendGmlFile(QString filepath)
{
    QFileInfo info(filepath);
    QString title = info.fileName();

    //关联
    QFile file(this->proFilepath);
    file.open(QIODevice::ReadOnly);
    QDomDocument doc;
    doc.setContent(&file);
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
    refreshProjTreeView();
}

/* 更新项目树结构显示 */
void ProjView::refreshProjTreeView()
{
    //先清空之前的显示
    clearTreeView();

    QFile file(this->proFilepath);
    file.open(QIODevice::ReadOnly);

    //文件file要和xml文档对象关联
    QDomDocument doc;
    doc.setContent(&file);

    //关联成功后就可以关闭文件了
    file.close();

    //获取根节点元素
    QDomElement root = doc.documentElement();

    //添加工程顶层节点
    QStandardItem *proTopNode = new QStandardItem(QIcon(":/resource/filenew.png"), root.attribute("name"));
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
            proFileNode->setEditable(false);
            proTopNode->appendRow(proFileNode);
        }
    }

    this->expandAll();
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
