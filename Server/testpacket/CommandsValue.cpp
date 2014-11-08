#include "CommandsValue.hh"

int		main()
{
  CommandsValue cmd;
  PacketInfo	packet;
  std::vector<char *> chars;
  std::vector<int> ints;

  packet.setCmd(14);
  cmd.setCommandsValue(&packet);
  return (0);
}

int		CommandsValue::setCommandsValue(PacketInfo *packet)
{
  std::vector<int>	ints;
  std::vector<char *>	chars;
  char			cmd;
  
  ints = packet->getInts();
  chars = packet->getChars();
  cmd = packet->getCmd();
  if (methodPtr.find(cmd) != methodPtr.end())
    (this->*methodPtr[cmd])(chars, ints);
  else
    return (-1);
  return (0);
}

CommandsValue::CommandsValue()
{
  methodPtr[1] = &CommandsValue::setConnect;
  methodPtr[2] = &CommandsValue::setSubscribe;
  methodPtr[3] = &CommandsValue::setAuthAnswer;
  methodPtr[4] = &CommandsValue::setNick;
  methodPtr[5] = &CommandsValue::setStatus;
  methodPtr[6] = &CommandsValue::setModule;
  methodPtr[7] = &CommandsValue::setBirth;
  methodPtr[8] = &CommandsValue::setSurname;
  methodPtr[9] = &CommandsValue::setName;
  methodPtr[10] = &CommandsValue::setAddress;
  methodPtr[11] = &CommandsValue::setPhone;
  methodPtr[12] = &CommandsValue::setContactNick;
  methodPtr[13] = &CommandsValue::setContactStatus;
  methodPtr[14] = &CommandsValue::setContactBirth;
  methodPtr[15] = &CommandsValue::setContactModule;
  methodPtr[16] = &CommandsValue::setContactSurname;
  methodPtr[17] = &CommandsValue::setContactName;
  methodPtr[18] = &CommandsValue::setContactAddress;
  methodPtr[19] = &CommandsValue::setContactPhone;
  methodPtr[20] = &CommandsValue::setAddRequest;
  methodPtr[21] = &CommandsValue::setAddAnswer;
  methodPtr[22] = &CommandsValue::setRemoveRequest;
  methodPtr[23] = &CommandsValue::setRemoveAnswer;
  methodPtr[24] = &CommandsValue::setCall;
  methodPtr[25] = &CommandsValue::setRequestCall;
  methodPtr[26] = &CommandsValue::setRequestAnswer;
  methodPtr[27] = &CommandsValue::setCallAnswer;
}

CommandsValue::~CommandsValue()
{

}

void		CommandsValue::setConnect(std::vector<char *> chars, std::vector<int> ints)
{
  std::cout << "test connect" << std::endl;
}

void		CommandsValue::setSubscribe(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setAuthAnswer(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setNick(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setStatus(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setModule(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setBirth(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setSurname(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setName(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setAddress(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setPhone(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setContactNick(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setContactStatus(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setContactBirth(std::vector<char *> chars, std::vector<int> ints)
{
  std::cout << "test contact birth" << std::endl;
}

void		CommandsValue::setContactModule(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setContactSurname(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setContactName(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setContactAddress(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setContactPhone(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setAddRequest(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setAddAnswer(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setRemoveRequest(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setRemoveAnswer(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setCall(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setRequestCall(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setRequestAnswer(std::vector<char *> chars, std::vector<int> ints)
{

}

void		CommandsValue::setCallAnswer(std::vector<char *> chars, std::vector<int> ints)
{

}
