/*
 * Serialize.cpp
 *
 *  Created on: Oct 29, 2014
 *      Author: giraud_d
 */

#include "Serialize.hh"
#include <stdlib.h>

Serialize::~Serialize() {
	// TODO Auto-generated destructor stub
}

Serialize::Serialize() {
	// TODO Auto-generated constructor stub

}

IPacket* Serialize::extract(char* buff) {
	IPacket		*packet;

	packet = (IPacket *)malloc(sizeof(Packet));
	memcpy(packet, buff, sizeof(Packet));
	return (packet);
}

char* Serialize::insert(IPacket* packet) {
	char		*buff;

	buff = (char *)malloc(sizeof(Packet));
	memcpy(buff, packet, sizeof(Packet));
	return (buff);
}
