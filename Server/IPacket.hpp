#if !defined(__Packet_IPacket_hh)
#define __Packet_IPacket_hh

#include <string.h>
#include <string>

class IPacket
{
public:
	virtual ~IPacket() {};
	virtual char		getCommand(void) const = 0;
	virtual const char	*getData(void) const = 0;
};

#endif
