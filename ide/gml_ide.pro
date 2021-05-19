QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gml_ide
TEMPLATE = app

HEADERS += \
    fullscreen/mainwindow.h \
    fullsub/treelayerview.h \
    fullsub/logtextedit.h \
    fullsub/notepadtab.h

SOURCES += \
    fullscreen/mainwindow.cpp \
    main.cpp \
    fullsub/treelayerview.cpp \
    fullsub/logtextedit.cpp \
    fullsub/notepadtab.cpp

FORMS +=

RESOURCES += \
    gml_ide.qrc

