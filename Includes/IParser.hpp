#if !defined(__Packet_Management_IParser_hpp)
#define __Packet_Management_IParser_hpp

#include "Packet.hh"
#include "PacketInfo.hh"

class IParser
{
public:
	virtual ~IParser() {};
	virtual IPacket* encode(IPacketInfo* packet_info) = 0;
	virtual IPacketInfo* decode(IPacket* packet) = 0;
};

#endif
