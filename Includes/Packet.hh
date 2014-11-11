#if !defined(__Packet_Packet_hh)
#define __Packet_Packet_hh

#include "IPacket.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

// struct		PacketValue {
//   char		cmd;
//   char		

class Packet : public IPacket
{
public:
  Packet(char, const char *);
  ~Packet();
  Packet();
  void		serialize(std::ostream &) const;
  void		unserialize(std::istream &);
  char		getCommand(void) const;
  const char	*getData(void) const;
// private:
  char		command;
  char		data[64];
};

std::stringbuf&	operator<<(std::stringbuf &stream, Packet *);
std::stringbuf& operator>>(std::stringbuf &stream, const Packet *);

#endif
