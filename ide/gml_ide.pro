#-------------------------------------------------
#
# Project created by QtCreator 2021-04-30T09:51:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gml_ide
TEMPLATE = app


SOURCES += fullscreen/mainwindow.cpp \
    main.cpp

HEADERS  += config/configmainwin.h \
    fullscreen/mainwindow.h

RESOURCES += \
    resource.qrc
