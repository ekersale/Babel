#if !defined(__Packet_Packet_hh)
#define __Packet_Packet_hh

#include "IPacket.hpp"

class Packet : public IPacket
{
public:
	Packet(char, char *);
	~Packet();
	char		getCommand(void);
	char		*getData(void);
private:
	char		command;
	char		data[64];
};

#endif
