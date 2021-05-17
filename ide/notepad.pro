QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Notepad
TEMPLATE = app

RESOURCES+= \
    notepad.qrc

HEADERS+=\
config.h \
    notepad.h \
    mainwindow.h \
    searchdialog.h \
    gotolinedialog.h \
    perferencedialog.h

SOURCES+=\
config.cpp \
    notepad.cpp \
    mainwindow.cpp \
    main.cpp \
    searchdialog.cpp \
    gotolinedialog.cpp \
    perferencedialog.cpp

FORMS += \
    searchdialog.ui \
    gotolinedialog.ui \
    perferencedialog.ui
