#include "Packet.hh"
#include <stdlib.h>

Packet::Packet(char _command, char *_data) : command(_command) {
	memcpy(data, _data, 64);
}

Packet::~Packet() {
}

char Packet::getCommand() {
  return (command);
}

char *Packet::getData(void) {
  return (data);
}
