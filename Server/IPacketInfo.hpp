/*
 * IPacketInfo.h
 *
 *  Created on: Oct 27, 2014
 *      Author: giraud_d
 */

#ifndef IPACKETINFO_HPP_
#define IPACKETINFO_HPP_

#include <vector>

class IPacketInfo {
public:
	virtual ~IPacketInfo() {};
	virtual const std::vector<char*>& getChars() const = 0;
	virtual const std::vector<int>& getInts() const = 0;
  	virtual void pushChars(char *) = 0;
  	virtual void pushInts(char *) = 0;
  	virtual char getCmd() const = 0;
	virtual void setCmd(char) = 0;
	virtual char *popChars() = 0;
	virtual void popInts(char *) = 0;
};

#endif /* IPACKETINFO_HPP_ */
