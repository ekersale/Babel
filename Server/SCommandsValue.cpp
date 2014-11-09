#include "SCommandsValue.hh"

SCommandsValue::SCommandsValue()
{
  methodPtr[1] = &ACommandsValue::connect;
  methodPtr[2] = &ACommandsValue::subscribe;
  //methodPtr[3] = &ACommandsValue::authAnswer;
  methodPtr[4] = &ACommandsValue::nick;
  methodPtr[5] = &ACommandsValue::status;
  methodPtr[6] = &ACommandsValue::module;
  methodPtr[7] = &ACommandsValue::birth;
  methodPtr[8] = &ACommandsValue::surname;
  methodPtr[9] = &ACommandsValue::name;
  methodPtr[10] = &ACommandsValue::address;
  methodPtr[11] = &ACommandsValue::phone;
  //methodPtr[12] = &ACommandsValue::contactNick;
  //methodPtr[13] = &ACommandsValue::contactStatus;
  //methodPtr[14] = &ACommandsValue::contactBirth;
  //methodPtr[15] = &ACommandsValue::contactModule;
  //methodPtr[16] = &ACommandsValue::contactSurname;
  //methodPtr[17] = &ACommandsValue::contactName;
  //methodPtr[18] = &ACommandsValue::contactAddress;
  //methodPtr[19] = &ACommandsValue::contactPhone;
  methodPtr[20] = &ACommandsValue::addRequest;
  //methodPtr[21] = &ACommandsValue::addAnswer;
  methodPtr[22] = &ACommandsValue::removeRequest;
  //methodPtr[23] = &ACommandsValue::removeAnswer;
  methodPtr[24] = &ACommandsValue::call;
  //methodPtr[25] = &ACommandsValue::requestCall;
  methodPtr[26] = &ACommandsValue::requestAnswer;
  //methodPtr[27] = &ACommandsValue::callAnswer;
}

SCommandsValue::~SCommandsValue() {
}

int		SCommandsValue::cmdVal(IPacketInfo *packet_info)
{
  std::vector<int>	     ints;
  std::vector<char *>        chars;
  char                       cmd;

  ints = packet_info->getInts();
  chars = packet_info->getChars();
  cmd = packet_info->getCmd();
  if (methodPtr.find(cmd) != methodPtr.end())
    (this->*methodPtr[cmd])(chars, ints);
  else
    return (-1);
  return (0);
}

void		SCommandsValue::connect(std::vector<char *> chars, std::vector<int> ints)
{

  
  // NEEKO remplir toutes les infos de UserInfo (sauf module & status) via le [id_login].xml (donc recup en parsan pour trouver le fichier via la login) + check en amont le psw

  // DAM pile : status + module


  std::cout << "test connect" << std::endl;
}

void		SCommandsValue::subscribe(std::vector<char *> chars, std::vector<int> ints)
{
  // DAM : générer l'id

  // NEEKO creer le fichier [id_login].xml (juste psw & login) (met un id bidon)
}

void		SCommandsValue::nick(std::vector<char *> chars, std::vector<int> ints)
{
  // NEKKO changer le valeur dans UserInfo + dans le [id_login].xml (recup la valeur dans la pile)
}

void		SCommandsValue::status(std::vector<char *> chars, std::vector<int> ints)
{
  // NEKKO changer le valeur dans UserInfo + dans le [id_login].xml (recup la valeur dans la pile)
}

void		SCommandsValue::module(std::vector<char *> chars, std::vector<int> ints)
{
  // NEKKO changer le valeur dans UserInfo + dans le [id_login].xml (recup la valeur dans la pile)
}

void		SCommandsValue::birth(std::vector<char *> chars, std::vector<int> ints)
{
  // NEKKO changer le valeur dans UserInfo + dans le [id_login].xml (recup la valeur dans la pile)
}

void		SCommandsValue::surname(std::vector<char *> chars, std::vector<int> ints)
{
  // NEKKO changer le valeur dans UserInfo + dans le [id_login].xml (recup la valeur dans la pile)
}

void		SCommandsValue::name(std::vector<char *> chars, std::vector<int> ints)
{
  // NEKKO changer le valeur dans UserInfo + dans le [id_login].xml (recup la valeur dans la pile)
}

void		SCommandsValue::address(std::vector<char *> chars, std::vector<int> ints)
{
  // NEKKO changer le valeur dans UserInfo + dans le [id_login].xml (recup la valeur dans la pile)
}

void		SCommandsValue::phone(std::vector<char *> chars, std::vector<int> ints)
{
  // NEKKO changer le valeur dans UserInfo + dans le [id_login].xml (recup la valeur dans la pile)
}

void		SCommandsValue::addRequest(std::vector<char *> chars, std::vector<int> ints)
{
  // NEKKO add le nouveau contact dans [id_login].xml du user + add contact id dans celui qui vient d'etre add
}

void		SCommandsValue::removeRequest(std::vector<char *> chars, std::vector<int> ints)
{
  // NEKKO comme au dessus mais le contraire
}

void		SCommandsValue::call(std::vector<char *> chars, std::vector<int> ints)
{

}

void		SCommandsValue::requestAnswer(std::vector<char *> chars, std::vector<int> ints)
{

}
