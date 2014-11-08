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

INCLUDEPATH     +=      ./Includes
INCLUDEPATH     +=      /usr/local/include/opencv2

LIBS            +=      -lopus -ljack -lasound -lrt -lm -lportaudio
LIBS            +=      -L/usr/local/lib -lopencv_core -lopencv_imgproc
LIBS            +=      -lopencv_highgui -lopencv_ml -lopencv_video
LIBS            +=      -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib
LIBS            +=      -lopencv_legacy -lopencv_flann -lopencv_nonfree

SOURCES +=      Gui/main.cpp                            \
                Gui/Connection.cpp                      \
                Gui/Subscribe.cpp                       \
                Gui/Home.cpp                            \
                Modules/Network/UClientInfo.cpp         \
                Modules/Network/UNetwork.cpp            \
                Modules/Opus/BabelEncoder.cpp           \
                Modules/PortAudio/BabelSound.cpp        \
                Modules/OpenCV/OpenCV.cpp               \
                Modules/Network/WNetwork.cpp            \
                Modules/Network/WClientInfo.cpp


HEADERS  +=     Includes/Connection.hh                   \
                Includes/Subscribe.hh                    \
                Includes/Home.hh                         \
                Includes/IGui.hh                         \
                Includes/BabelEncoder.hh                 \
                Includes/IBabelEncoder.hh                \
                Includes/Network.hh                      \
                Includes/BabelSound.hh                   \
                Includes/IBabelSound.hh                  \
                Includes/IModule.hh                      \
                Includes/INetwork.hh                     \
                Includes/UClientInfo.hh                  \
                Includes/OpenCV.hh                      \
                Includes/WClientInfo.hh

FORMS    +=     Gui/Ui/Connection.ui                    \
                Gui/Ui/Subscribe.ui                     \
                Gui/Ui/Home.ui
