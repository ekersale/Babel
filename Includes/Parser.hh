#if !defined(__Packet_Management_Parser_hh)
#define __Packet_Management_Parser_hh

#include "IParser.hpp"
#include "PacketInfo.hh"
#include "Packet.hh"
#include <vector>
#include <map>


class Parser : public IParser
{
public:
	Parser(std::map<char, std::vector<unsigned char> >);
	~Parser();
	IPacket	*encode(IPacketInfo* packet_info);
	IPacketInfo	*decode(IPacket* packet);
	char* getBuffer() const;
	void setBuffer(char* buffer);
	const std::map<char, std::vector<unsigned char> >& getRef() const;
	void setRef(const std::map<char, std::vector<unsigned char> >& ref);
	/*
	const IPacketInfo*& getCurrentPacket() const;
	void setCurrentPacket(const IPacketInfo*& currentPacket);
*/
private:
	char								*_buffer;
	std::map<char, std::vector<unsigned char> >	_ref;
//	IPacketInfo							*current_packet;
};

#endif
