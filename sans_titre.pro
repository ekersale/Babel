#-------------------------------------------------
#
# Project created by QtCreator 2014-11-01T15:41:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Babel
TEMPLATE = app


SOURCES += Gui/main.cpp\
        Gui/Connection.cpp \
    Gui/Subscribe.cpp \
    Gui/Home.cpp

HEADERS  += Includes/Connection.h \
    Includes/Subscribe.h \
    Includes/Home.h \
    Includes/IGui.h

FORMS    += Gui/Ui/Connection.ui \
    Gui/Ui/Subscribe.ui \
    Gui/Ui/Home.ui
