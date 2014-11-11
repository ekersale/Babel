/*
 * Serialize.hh
 *
 *  Created on: Oct 29, 2014
 *      Author: giraud_d
 */

#ifndef SERIALIZE_HH_
#define SERIALIZE_HH_

#include	<iostream>
#include	<istream>
#include	<ostream>
#include	<sstream>

#include	"Packet.hh"

// #include "ISerialize.hpp"

class Serialize // : public ISerialize
{
public:
  Serialize();
  ~Serialize();
  // IPacket		*extract(char *buff);
  // char		*insert(IPacket *packet);

};
// std::ostream		&operator<<(std::ostream &out, const Packet &other);
// std::istream		&operator>>(std::istream &in, Packet *other);

// std::ostream		&operator<<(std:::ostream &out, const Packet *other)
// std::istream		&operator>>(std::istream &in, Packet *other)
std::stringstream	&operator<<(std::stringstream &out, const Packet *other);
std::stringstream	&operator>>(std::stringstream &in, Packet *other);  


#endif /* SERIALIZE_HH_ */
