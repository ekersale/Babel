#if !defined(__Packet_IPacket_hh)
#define __Packet_IPacket_hh

#include <string.h>
#include <string>

class IPacket
{
public:
	virtual ~IPacket() {};
	virtual char		getCommand(void) = 0;
	virtual char		*getData(void) = 0;
};

#endif
