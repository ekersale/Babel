#include "ThreadCom.hh"

ThreadCom::ThreadCom()
{
	test = 0;
	_network = new Network(AF_INET, SOCK_STREAM, "TCP", 65);
	_serialize = new Serialize();
	_xmlParser = new XMLParser();
	_parser = new Parser(_xmlParser->getCommandArgs("commands.xml"));
	_socket = 0;
}

ThreadCom::~ThreadCom() {
}

bool ThreadCom::connectServer()
{
	_socket = _network->connectSocket(IP_ADDR_SERV, PORT);
	if (_socket == false) {
		emit displayError("Failed to join server");
		return (false);
	}
	return (true);
}

void ThreadCom::run()
{
	static int i = 0;
	while (1) {
		if (_socket == 0)
			emit finished();
		else
		{

			ClientInfo	*clientInfo;
			if ((clientInfo = _network->get_connected(_socket)))
			{
				if (_network->recvSocket(_socket) == false)
					exit(0);
				if (_network->get_filled() == 0)
					exit(0);

				Packet		*packet = new Packet();
				std::string	rbuff(_network->get_buffer(), 65);
				std::stringbuf	usz(rbuff);

				usz << packet;

				IPacketInfo	*packet_info;
				packet_info = getParser()->decode(packet);

				cmdVal(packet_info);
				const char *tmp = packet_info->getChars().front();
				//int val = packet_info->getInts[0];
				//std::cout << "val [" << val << "]" << std::endl;
				if (i == 0){

#ifdef	_WIN32	
					Sleep(100);
#else
					usleep(100000);
					std::cout << "On est dans le USLEEP" << std::endl;
#endif
				}
				i++;
			}
		}
	}
}

Network		*ThreadCom::getNetwork() const
{
	return (this->_network);
}
