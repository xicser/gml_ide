#include "fullscreen/mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QCoreApplication>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    //设置程序的工作目录为可执行文件所在目录
    QDir::setCurrent(QCoreApplication::applicationDirPath());

    setbuf(stdout, NULL); //让printf, qDebug立即输出, 不要缓存
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();

    return a.exec();
}
