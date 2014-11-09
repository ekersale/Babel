/*
 * PacketInfo.h
 *
 *  Created on: Oct 27, 2014
 *      Author: giraud_d
 */

#ifndef PACKETINFO_HH_
#define PACKETINFO_HH_

#include "IPacketInfo.hpp"

#include <iostream>
class PacketInfo: public IPacketInfo {
public:
	PacketInfo();
	virtual ~PacketInfo();
	const std::vector<const char*>& getChars() const;
	const std::vector<int>& getInts() const;
  // void setChars(const std::vector<char*>& chars);
	void pushChars(const char *);
	void pushInts(const char *);
	const char *popChars();
	void popInts(char *);
	char getCmd() const;
	void setCmd(char);

private:
	char					_cmd;
	std::vector<const char *>		_chars;
	std::vector<int>		_ints;
};

#endif /* PACKETINFO_HH_ */
