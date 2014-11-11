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

TARGET          =       Serveur

TEMPLATE        =       app

INCLUDEPATH     +=      ../Includes

SOURCES +=      main.cpp        \
                Server.cpp      \
                ServerNetwork.cpp       \
                UserAction.cpp  \
                User.cpp        \
                UserInfo.cpp    \
                ../Modules/Packet/Packet.cpp      \
                ../Modules/Packet/PacketInfo.cpp  \
                ../Modules/Packet/Parser.cpp      \
                ../Modules/Packet/Serialize.cpp   \
                ../Modules/XML/XMLParser.cpp            \
                ../Modules/Network/UClientInfo.cpp      \
                ../Modules/Network/UNetwork.cpp         \
                SCommandsValue.cpp      \


HEADERS  +=     ../Includes/IPacket.hpp             \
                ../Includes/IParser.hpp             \
                ../Includes/PacketInfo.hh           \
                ../Includes/Server.hh               \
                ../Includes/User.hh                 \
                ../Includes/XMLParser.hh            \
                ../Includes/IPacketInfo.hpp         \
                ../Includes/ISerialize.hpp          \
                ../Includes/Packet.hh               \
                ../Includes/Parser.hh               \
                ../Includes/Serialize.hh            \
                ../Includes/UserInfo.hh             \
                ../Includes/ACommandsValue.hpp      \
                ../Includes/UClientInfo.hh          \
                ../Includes/Network.hh              \
                ../Includes/INetwork.hh             \
                ../Includes/SCommandsValue.hh       \
