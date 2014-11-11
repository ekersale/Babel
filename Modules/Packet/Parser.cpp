#include "Parser.hh"

Parser::Parser(std::map<char, std::vector<unsigned char> > ref) {
	setRef(ref);
}

Parser::~Parser() {
}

IPacket* Parser::encode(IPacketInfo* packetinfo)
{
	std::vector<unsigned char>			key;
	char						data[64];
	char						*ptr;

	key = _ref.find(packetinfo->getCmd())->second;
	ptr = data;
	memset(data, 0, 64);
	std::cout << "\n\tWith Value : " << (int)packetinfo->getCmd() << "\n\n";
	for (std::vector<unsigned char>::iterator mykey = key.begin(); mykey != key.end(); mykey++) {
		if (*mykey > 128)
		  {
		    strncpy(ptr, packetinfo->popChars(), (*mykey - 128));
		    ptr = ptr + (*mykey - 128);
		  }
		else if (*mykey == 64)
		  {
		    packetinfo->popInts(ptr);
		    ptr += 4;
		  }
		else {
			// TODO
		}
	}
	return (new Packet(packetinfo->getCmd(), data));
}

IPacketInfo* Parser::decode(IPacket* packet) {
	std::vector<unsigned char>	key;
	IPacketInfo			*packetinfo;
	const char			*ptr;

	std::cout << "\n\n\n\tCmd val is : " << (int)packet->getCommand() <<"\n"; 
	key = _ref.find(packet->getCommand())->second;
	packetinfo = new PacketInfo();
	ptr = packet->getData();
	packetinfo->setCmd(packet->getCommand());
	for (std::vector<unsigned char>::iterator mykey = key.begin(); mykey != key.end(); mykey++) {
		if (*mykey > 128) {
			packetinfo->pushChars(ptr);
			ptr += (*mykey - 128);
		} else if (*mykey == 64) {
			packetinfo->pushInts(ptr);
			ptr += 4;
		} else {
			// TODO
		}
	}
	return (packetinfo);
}

char* Parser::getBuffer() const {
	return _buffer;
}

void Parser::setBuffer(char* buffer) {
	_buffer = buffer;
}

const std::map<char, std::vector<unsigned char> >& Parser::getRef() const {
	return _ref;
}

void Parser::setRef(const std::map<char, std::vector<unsigned char> >& ref) {
	_ref = ref;
}
