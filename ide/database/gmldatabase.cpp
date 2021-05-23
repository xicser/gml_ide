#include "gmldatabase.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>

GmlDataBase::GmlDataBase()
{
    recentFilePathList.clear();
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
    if (query.exec("create table RecentFilePath("
                   "filepath varchar(512))") == false) {
        qDebug() << db.lastError().text();
        readRencentFileList();
    } else {
        recentFilePathList.clear();
    }
}

/* 读取最近打开文件列表 */
QStringList *GmlDataBase::readRencentFileList(void)
{
    QSqlQuery query;
    QString selectCmd = QString("select * from RecentFilePath");
    query.exec(selectCmd);
    recentFilePathList.clear();
    while (query.next()) {
        QString filepath = query.value(0).toString();
        recentFilePathList << filepath;
        qDebug() << filepath;
    }

    return &recentFilePathList;
}

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
//        QString delete_cmd = QString("delete from RecentFilePath where number = '%1'").arg(number);
//        qDebug() << delete_cmd;
//        QString tmp_str;

//        //执行
//        QSqlQuery query;
//        if (query.exec(delete_cmd) == true) {
//            tmp_str = QString("学生(%1)删除成功！").arg(number);
//            ui->textEdit->append(tmp_str);
//        } else {
//            tmp_str = QString("学生(%1)删除失败！").arg(number);
//            ui->textEdit->append(tmp_str);
//        }
    }

    //生成sql语句
    QString insertCmd = QString("insert into RecentFilePath(filepath)"
                                "values('" + filepath + "')") ;
    qDebug() << insertCmd;
    query.exec(insertCmd);
}
