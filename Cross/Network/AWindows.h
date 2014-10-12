#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN

#ifndef AWINDOWS_H_
#define AWINDOWS_H_

#include	<iostream>
#include	<Windows.h>
#include	<Winsock2.h>
#include	<WS2tcpip.h>
#include	<IPHlpApi.h>
#include	<stdio.h>

#pragma comment(lib, "Ws2_32.lib")

class AWindows
{
public:
	AWindows();
	~AWindows();
	virtual bool setSockAddr() = 0;
	virtual bool createSocket() = 0;
	bool bindSocket();
	bool listenSocket();
	bool acceptSocket();
	virtual bool recvSocket() = 0;
	virtual bool sendSocket() = 0;
	virtual bool recvFromSocket() = 0;
	virtual bool sendToSocket() = 0;
	bool connectSocket();

private:

};

#endif
#endif