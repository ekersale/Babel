#include "Packet.hh"
#include <stdlib.h>

Packet::Packet(char _command, const char *_data) : command(_command) {
	memcpy(data, _data, 64);
}

Packet::~Packet() {
}

Packet::Packet() {
  command = 0;
  memset(data, 0, 64);
}

void		Packet::serialize(std::ostream &os) const
{
  os.write(reinterpret_cast<const char *>(&this->command), sizeof(char));
  os.write(reinterpret_cast<const char *>(&this->data), sizeof(char) * 64);
}

void		Packet::unserialize(std::istream &is)
{
  char		byte;
  int		i = -1;

  is.read(&byte, sizeof(char));
  this->command = reinterpret_cast<char>(byte);
  while (++i < 64)
    {
      is.read(&byte, sizeof(char));
      this->data[i] = reinterpret_cast<char>(byte);
    }
}

// deserializing overload
std::stringbuf& operator<<(std::stringbuf &stream, Packet *pack)
{
  std::istream is(&stream);
  pack->unserialize(is);
  return stream;
}

// serializing overload
std::stringbuf& operator>>(std::stringbuf &stream, const Packet *pack)
{
  std::ostream os(&stream);
  pack->serialize(os);
  return stream;
}

char Packet::getCommand() const {
  return (command);
}

const char *Packet::getData(void) const {
  return (data);
}
