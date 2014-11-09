/*
 * Serialize.hh
 *
 *  Created on: Oct 29, 2014
 *      Author: giraud_d
 */

#ifndef SERIALIZE_HH_
#define SERIALIZE_HH_

#include "ISerialize.hpp"

class Serialize : public ISerialize {
public:
	virtual ~Serialize();
	Serialize();

	IPacket		*extract(char *buff);
	char		*insert(IPacket *packet);
};

#endif /* SERIALIZE_HH_ */
