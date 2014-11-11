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


// std::stringstream	&operator<<(std::stringstream &out, const Packet *other)
// {
//   out << other->getCommand() << 't';
//   out << other->getData() << std::endl;
//   return out;
// }

// Packet *	&operator>>(std::stringstream &in, Packet *other)
// {
//   in >> other->command;
//   //in >> other->data;
  
//   return other;
// }

std::stringstream	&operator<<(std::stringstream &out, const Packet *other)
{
  out << other->getCommand();
  out << other->getData();
  return out;
}


std::stringstream	&operator>>(std::stringstream &in, Packet *other)
{
  in >> other->command;
  in >> other->data;
  
  return in;
}


// IPacket* Serialize::extract(char* buff) {
// 	IPacket		*packet;

// 	packet = (IPacket *)malloc(sizeof(Packet));
// 	memcpy(packet, buff, sizeof(Packet));
// 	return (packet);
// }

// char* Serialize::insert(IPacket* packet) {
// 	char		*buff;

// 	buff = (char *)malloc(sizeof(Packet));
// 	memcpy(buff, packet, sizeof(Packet));
// 	return (buff);
// }
