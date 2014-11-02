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
    Gui/Home.cpp \
    Modules/OpenCV/OpenCV.cpp

HEADERS  += Includes/Connection.h \
    Includes/Subscribe.h \
    Includes/Home.h \
    Includes/IGui.h \
    Includes/OpenCV.h

FORMS    += Gui/Ui/Connection.ui \
    Gui/Ui/Subscribe.ui \
    Gui/Ui/Home.ui

INCLUDEPATH += /usr/local/include/opencv2

LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann
LIBS += -lopencv_nonfree
