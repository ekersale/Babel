#include "ThreadCom.hh"

ThreadCom::ThreadCom()
{
	_network = new Network(AF_INET, SOCK_STREAM, "TCP", sizeof(Packet));
	_serialize = new Serialize();
	// _xmlParser = new XMLParser();
	_parser = new Parser(_xmlParser->getCommandArgs("./XML_file/commands.xml"));
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
  if (_socket == 0)
    emit finished();
  else {
    _network->recvSocket(_socket);
    _network->get_buffer();
    cmdVal(_parser->decode(_serialize->extract(_network->get_buffer())));
  }
}


Network		*ThreadCom::getNetwork() const
{
  return (this->_network);
}
