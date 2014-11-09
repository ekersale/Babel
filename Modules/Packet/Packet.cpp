#include "Packet.hh"
#include <stdlib.h>

Packet::Packet(char _command, const char *_data) : command(_command) {
	memcpy(data, _data, 64);
}

Packet::~Packet() {
}

char Packet::getCommand() const {
  return (command);
}

const char *Packet::getData(void) const {
  return (data);
}
