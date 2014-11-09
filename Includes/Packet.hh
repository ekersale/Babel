#if !defined(__Packet_Packet_hh)
#define __Packet_Packet_hh

#include "IPacket.hpp"

class Packet : public IPacket
{
public:
	Packet(char, const char *);
	~Packet();
	char		getCommand(void) const;
	const char	*getData(void) const;
private:
	char		command;
	char		data[64];
};

#endif
