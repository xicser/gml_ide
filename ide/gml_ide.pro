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
    fullsub/projview.h

SOURCES += \
    fullscreen/mainwindow.cpp \
    main.cpp \
    fullsub/logtextedit.cpp \
    fullsub/notepadtab.cpp \
    fullsub/searchdialog.cpp \
    fullsub/gotolinedialog.cpp \
    database/gmldatabase.cpp \
    fullsub/projview.cpp

INCLUDEPATH += qscitinlla
LIBS += -L$$PWD/qscitinlla -lqscintilla2_qt5d

FORMS += \
    fullsub/searchdialog.ui \
    fullsub/gotolinedialog.ui

RESOURCES += \
    gml_ide.qrc

CONFIG += c++11
