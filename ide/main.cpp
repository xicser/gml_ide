#include <QApplication>
#include "mainwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Config config;
    MainWindow mainWin(&config);
    mainWin.show();
    return app.exec();
}
