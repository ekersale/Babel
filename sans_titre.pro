#-------------------------------------------------
#
# Project created by QtCreator 2014-11-01T15:41:30
#
#-------------------------------------------------

QT       +=     core                            \
                gui                             \
                widgets                         \
                xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET          =       Babel

TEMPLATE        =       app

DEPENDPATH      += 

INCLUDEPATH     +=      ./Includes

LIBS            +=      -lopus -ljack -lasound -lrt -lm -lportaudio

SOURCES +=      Gui/main.cpp                    \
                Gui/Connection.cpp              \
                Gui/Subscribe.cpp               \
                Gui/Home.cpp                    \
                Modules/Network/ClientInfo.cpp  \
                Modules/Network/UNetwork.cpp    \
                Modules/Opus/BabelEncoder.cpp   \
                Modules/PortAudio/BabelSound.cpp

HEADERS  +=     Includes/Connection.h           \
                Includes/Subscribe.h            \
                Includes/Home.h                 \
                Includes/IGui.h                 \
                Includes/BabelEncoder.h         \
                Includes/IBabelEncoder.h        \
                Includes/UNetwork.h             \
                Includes/BabelSound.h           \
                Includes/IBabelSound.h          \
                Includes/IModule.h              \
                Includes/INetwork.h             \
                Includes/ClientInfo.h

FORMS    +=     Gui/Ui/Connection.ui            \
                Gui/Ui/Subscribe.ui             \
                Gui/Ui/Home.ui
