#include "ACommandsValue.hh"

ACommandsValue::ACommandsValue()
{
  methodPtr[1] = &ACommandsValue::connect;
  methodPtr[2] = &ACommandsValue::subscribe;
  methodPtr[3] = &ACommandsValue::authAnswer;
  methodPtr[4] = &ACommandsValue::nick;
  methodPtr[5] = &ACommandsValue::status;
  methodPtr[6] = &ACommandsValue::module;
  methodPtr[7] = &ACommandsValue::birth;
  methodPtr[8] = &ACommandsValue::surname;
  methodPtr[9] = &ACommandsValue::name;
  methodPtr[10] = &ACommandsValue::address;
  methodPtr[11] = &ACommandsValue::phone;
  methodPtr[12] = &ACommandsValue::contactNick;
  methodPtr[13] = &ACommandsValue::contactStatus;
  methodPtr[14] = &ACommandsValue::contactBirth;
  methodPtr[15] = &ACommandsValue::contactModule;
  methodPtr[16] = &ACommandsValue::contactSurname;
  methodPtr[17] = &ACommandsValue::contactName;
  methodPtr[18] = &ACommandsValue::contactAddress;
  methodPtr[19] = &ACommandsValue::contactPhone;
  methodPtr[20] = &ACommandsValue::addRequest;
  methodPtr[21] = &ACommandsValue::addAnswer;
  methodPtr[22] = &ACommandsValue::removeRequest;
  methodPtr[23] = &ACommandsValue::removeAnswer;
  methodPtr[24] = &ACommandsValue::call;
  methodPtr[25] = &ACommandsValue::requestCall;
  methodPtr[26] = &ACommandsValue::requestAnswer;
  methodPtr[27] = &ACommandsValue::callAnswer;
}

ACommandsValue::~ACommandsValue()
{

}

void		ACommandsValue::connect(std::vector<char *> chars, std::vector<int> ints)
{
  std::cout << "test connect" << std::endl;
}

void		ACommandsValue::subscribe(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::authAnswer(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::nick(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::status(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::module(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::birth(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::surname(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::name(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::address(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::phone(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::contactNick(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::contactStatus(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::contactBirth(std::vector<char *> chars, std::vector<int> ints)
{
  std::cout << "test contact birth" << std::endl;
}

void		ACommandsValue::contactModule(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::contactSurname(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::contactName(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::contactAddress(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::contactPhone(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::addRequest(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::addAnswer(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::removeRequest(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::removeAnswer(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::call(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::requestCall(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::requestAnswer(std::vector<char *> chars, std::vector<int> ints)
{

}

void		ACommandsValue::callAnswer(std::vector<char *> chars, std::vector<int> ints)
{

}
