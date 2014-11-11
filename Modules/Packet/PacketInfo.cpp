/*
 * PacketInfo.cpp
 *
 *  Created on: Oct 27, 2014
 *      Author: giraud_d
 */

#include "PacketInfo.hh"

PacketInfo::~PacketInfo() {
}

PacketInfo::PacketInfo() {
	_cmd = 0;
}

std::vector<const char*>& PacketInfo::getChars() {
	return _chars;
}

/*
void PacketInfo::setChars(const std::vector<char*>& chars) {
	_chars = chars;
}
*/

std::vector<int>& PacketInfo::getInts() {
	return _ints;
}

#include <string.h>
void PacketInfo::pushChars(const char *elem) {
  _chars.push_back(strdup(elem));
}

void PacketInfo::pushInts(const char *ptr) {
	int elem;

	elem = 0;
	for (int i = 0; i< 4; i++) {
		elem = (elem << 8) + (unsigned char)*(ptr + i);
	}
	_ints.push_back(elem);
}

char PacketInfo::getCmd() const {
	return _cmd;
}

const char* PacketInfo::popChars() {
	const char *ret;

	ret = _chars.front();
	_chars.erase(_chars.begin());
	//std::cout << "\n\t\tStr Ret is : " << ret << "\n\n";
	return (ret);
}

void PacketInfo::popInts(char *ptr) {
	int		val;

	val = _ints.front();
	_ints.erase(_ints.begin());
	for (int i = 3; i >= 0; i--) {
		*(ptr + i) = val & 255;
		val >>= 8;
	}
}

void PacketInfo::setCmd(char cmd) {
	_cmd = cmd;
}
