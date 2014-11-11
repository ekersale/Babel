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
}

void ThreadCom::run()
{
	while (1) {
		if (_socket == 0)
			emit finished();
		else
		{
			ClientInfo	*clientInfo;

			if (clientInfo = _network->get_connected(_socket))
			{
				test++;
				_network->recvSocket(_socket);

				int deb = _network->get_filled();
				std::cout << deb << std::endl;
				Packet		*packet = new Packet();
				std::string	rbuff(_network->get_buffer(), 65);
				std::stringbuf	usz(rbuff);

				usz << packet;
				IPacketInfo	*packet_info;
				packet_info = getParser()->decode(packet);

				cmdVal(packet_info);
				const char *tmp = packet_info->getChars().front();
				std::cout <<  "data [" << tmp << "]" << std::endl;
			}
		}
	}
}


Network		*ThreadCom::getNetwork() const
{
	return (this->_network);
}
