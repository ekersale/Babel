#include "ThreadCom.hh"

ThreadCom::ThreadCom()
{
	_network = new Network(AF_INET, SOCK_STREAM, "TCP", sizeof(Packet));
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
  /*
  if (_socket == 0)
    emit finished();
  else {
    _network->recvSocket(_socket);
    _network->get_buffer();
    // cmdVal(_parser->decode(_serialize->extract(_network->get_buffer())));
  }
  */
  std::cout << "The value of _socket(id) " << _socket << "\n";
  if (_socket == 0)
    emit finished();
  else
    {
      ClientInfo	*clientInfo;

      if (clientInfo = _network->get_connected(_socket))
	{
	  _network->recvSocket(clientInfo->get_socket());
      
      
      //std::cout << "On reçoit quoi => " <<  _network->get_buffer() << "#" << std::endl;
      
	  Packet		*packet = new Packet();
	  std::string	rbuff(_network->get_buffer(), 65);
	  std::stringbuf	usz(rbuff);
	  
	  usz << packet;
	  
	  IPacketInfo	*packet_info;
	  //std::cout << "FUCK => " << getParser()->decode(packet) << std::endl;
	  packet_info = getParser()->decode(packet);
	  cmdVal(packet_info);
        }
    }
}


Network		*ThreadCom::getNetwork() const
{
  return (this->_network);
}
