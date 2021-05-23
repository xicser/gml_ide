#include "gmldatabase.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>

GmlDataBase::GmlDataBase()
{
    dbInit();
}

/* 数据库初始化 */
void GmlDataBase::dbInit()
{
    //打开数据库
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("gml_config.db");
    if (db.open() == false) {
        return;
    }

    //创建最近打开文件表
    QSqlQuery query;
    query.exec("create table RecentFilePath("
                   "id int,"
                   "filepath varchar(512))");
}

/* 读取最近打开文件列表 */
QStringList *GmlDataBase::readRencentFileList(void)
{
    QSqlQuery query;
    QString selectCmd = QString("select filepath from RecentFilePath");
    query.exec(selectCmd);
    recentFilePathList.clear();
    while (query.next()) {
        QString filepath = query.value(0).toString();
        recentFilePathList << filepath;
    }

    return &recentFilePathList;
}

/* 最近打开文件表中的id */
unsigned int GmlDataBase::recentFileId = 1;

/* 往打开文件列表里插入一项 */
void GmlDataBase::insertRencentFileList(QString filepath)
{
    QSqlQuery query;

    //最多支持10条历史记录
    QString rowCntCmd = QString("select count(*) from RecentFilePath");
    query.exec(rowCntCmd);
    int rowCnt;
    while (query.next()) {
        rowCnt = query.value(0).toInt();
    }

    if (rowCnt >= 10) {
        //删除一条最老的记录
        QString deleteCmd = QString("delete from RecentFilePath where id = (select id from(select min(id) id from RecentFilePath) t1)");
        deleteCmd;
        query.exec(deleteCmd);
    }

    //如果这个文件路径已经存在, 就不要再插入了
    query.exec(QString("select filepath from RecentFilePath where filepath = '%1'").arg(filepath));
    while (query.next()) {
        return;
    }

    //生成sql语句
    QString insertCmd = QString("insert into RecentFilePath(id, filepath) values('%1', '%2')").arg(recentFileId++).arg(filepath);
    query.exec(insertCmd);
}
