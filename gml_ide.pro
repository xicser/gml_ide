QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gml_ide
TEMPLATE = app

HEADERS += \
    fullscreen/mainwindow.h

SOURCES += \
    fullscreen/mainwindow.cpp \
    main.cpp

FORMS +=

RESOURCES += \
    gml_ide.qrc

