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
  std::vector<const char*>& getChars();
  std::vector<int>& getInts();
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
