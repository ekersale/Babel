/*
 * PacketInfo.h
 *
 *  Created on: Oct 27, 2014
 *      Author: giraud_d
 */

#ifndef PACKETINFO_HH_
#define PACKETINFO_HH_

#include "IPacketInfo.hpp"
#include <vector>

#include <iostream>
class PacketInfo: public IPacketInfo {
public:
	PacketInfo();
	virtual ~PacketInfo();
	const std::vector<char*>& getChars() const;
	void setChars(const std::vector<char*>& chars);
	const std::vector<int>& getInts() const;
	void pushChars(char *);
	void pushInts(char *);
	char *popChars();
	void popInts(char *);
	char getCmd() const;
	void setCmd(char cmd);

private:
	char					_cmd;
	std::vector<char *>		_chars;
	std::vector<int>		_ints;
};

#endif /* PACKETINFO_HH_ */
