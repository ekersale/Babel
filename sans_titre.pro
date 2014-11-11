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
                Modules/Network/WClientInfo.cpp         \
                Client/ThreadCom.cpp                    \
                Client/UserInfo.cpp                     \
                Client/CCommandsValue.cpp               \
                Modules/XML/XMLParser.cpp               \
                Modules/Packet/PacketInfo.cpp           \
                Modules/Packet/Packet.cpp               \
                Modules/Packet/Serialize.cpp            \
                Modules/Packet/Parser.cpp


HEADERS  +=     Includes/Subscribe.hh                    \
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
                Includes/WClientInfo.hh                 \
                Includes/Packet.hh                      \
                Includes/IPacket.hpp                    \
                Includes/IPacketInfo.hpp                \
                Includes/PacketInfo.hh                  \
                Includes/Parser.hh                      \
                Includes/ThreadCom.hh                   \
                Includes/ACommandsValue.hpp             \
                Includes/CCommandsValue.hh              \
                Includes/ISerialize.hpp                 \
                Includes/Serialize.hh                   \
                Includes/Connection.hh                  \

FORMS    +=     Gui/Ui/Connection.ui                    \
                Gui/Ui/Subscribe.ui                     \
                Gui/Ui/Home.ui
