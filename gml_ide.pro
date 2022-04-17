QT       += core gui sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gml_ide
TEMPLATE = app

DEFINES += QSCINTILLA_DLL

HEADERS += \
    fullscreen/mainwindow.h \
    fullsub/logtextedit.h \
    fullsub/notepadtab.h \
    fullsub/searchdialog.h \
    fullsub/gotolinedialog.h \
    database/gmldatabase.h \
    fullsub/projview.h \
    fullsub/createprojectdialog.h \
    qscitinlla/lexergml.h

SOURCES += \
    fullscreen/mainwindow.cpp \
    main.cpp \
    fullsub/logtextedit.cpp \
    fullsub/notepadtab.cpp \
    fullsub/searchdialog.cpp \
    fullsub/gotolinedialog.cpp \
    database/gmldatabase.cpp \
    fullsub/projview.cpp \
    fullsub/createprojectdialog.cpp \
    qscitinlla/lexergml.cpp

INCLUDEPATH += qscitinlla

FORMS += \
    fullsub/searchdialog.ui \
    fullsub/gotolinedialog.ui \
    fullsub/createprojectdialog.ui

RESOURCES += \
    gml_ide.qrc

CONFIG += c++11 debug_and_release

CONFIG(debug,debug|release){
    win32: {
        LIBS += -L$$PWD/qscitinlla -lqscintilla2_qt5d
    } else {
        LIBS += -L$$PWD/qscitinlla/linuxd -lqscintilla2_qt5
    }
}
CONFIG(release,debug|release){
    win32: {
        LIBS += -L$$PWD/qscitinlla -lqscintilla2_qt5
    } else {
        LIBS += -L$$PWD/qscitinlla/linuxr -lqscintilla2_qt5
    }
}
