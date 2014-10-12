#ifndef INETWORK_H_
#define INETWORK_H_

class INetwork
{
public:
	virtual bool setSockAddr() = 0;
	virtual bool createSocket() = 0;
	virtual bool bindSocket() = 0;
	virtual bool listenSocket() = 0;
	virtual bool acceptSocket() = 0;
	virtual bool recvSocket() = 0;
	virtual bool sendSocket() = 0;
	virtual bool recvFromSocket() = 0;
	virtual bool sendToSocket() = 0;
	virtual bool connectSocket() = 0;
private:

};

#endif