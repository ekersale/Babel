/*
 * ISerialize.hpp
 *
 *  Created on: Oct 29, 2014
 *      Author: giraud_d
 */

#ifndef ISERIALIZE_HPP_
#define ISERIALIZE_HPP_

#include "Packet.hh"

class ISerialize {
public:
	virtual IPacket		*extract(char *buff) = 0;
	virtual char		*insert(IPacket *packet) = 0;
	virtual ~ISerialize() {};
};

#endif /* ISERIALIZE_HPP_ */
