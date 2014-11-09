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

TARGET          =       Server

TEMPLATE        =       app

INCLUDEPATH     +=      .

SOURCES +=      main.cpp        \
                Packet.cpp      \
                PacketInfo.cpp  \
                Parser.cpp      \
                Serialize.cpp   \
                Server.cpp      \
                ServerNetwork.cpp       \
                UserAction.cpp  \
                User.cpp        \
                UserInfo.cpp    \
                XMLParser.cpp   \
                ../Modules/Network/UClientInfo.cpp      \
                ../Modules/Network/UNetwork.cpp         \
                SCommandsValue.cpp      \


HEADERS  +=     IPacket.hpp             \
                IParser.hpp             \
                PacketInfo.hh           \
                Server.hh               \
                User.hh                 \
                XMLParser.h             \
                IPacketInfo.hpp         \
                ISerialize.hpp          \
                Packet.hh               \
                Parser.hh               \
                Serialize.hh            \
                UserAction.hh           \
                UserInfo.hh             \
                ../Modules/testpacket/ACommandsValue.hpp        \
                ../Includes/UClientInfo.hh               \
                ../Includes/Network.hh                          \
                ../Includes/INetwork.hh                         \
                SCommandsValue.hh       \
