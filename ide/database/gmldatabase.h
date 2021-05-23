#ifndef GMLDATABASE_H
#define GMLDATABASE_H

#include <QStringList>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class GmlDataBase
{
public:
    GmlDataBase();

    QStringList *readRencentFileList(void);         //读取最近打开文件列表
    void insertRencentFileList(QString filepath);   //往最近打开文件列表里插入一项

private:
    QSqlDatabase db;
    QStringList recentFilePathList;         //最近打开文件string list

    void dbInit();                          //数据库初始化

};

#endif // GMLDATABASE_H