#include "SCommandsValue.hh"
#include "dirent.h"
#include "Server.hh"

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
  //  _xmlParser = new XMLParser();
  _xmlParser = _user->get_server()->get_xmlParser();
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
  std::string filename;

  filename = chars[0];
  filename += ".xml";
  // envoie giraud_d et non giraud_d.44 donc parser le filename par trouver le bon fichier
  if (strcmp(chars[1], _xmlParser->getNodeValue(filename, "password").c_str()) == 0)
    std::cout << "Good passwd" << std::endl;
  else
    std::cout << "Wrong passwd" << std::endl;
  _user->set_login(_xmlParser->getNodeValue(filename, "login"));
  //std::cout << _xmlParser->getNodeValue(filename, "password");
  _user->set_birth(_xmlParser->getNodeValue(filename, "birth"));
  _user->set_name(_xmlParser->getNodeValue(filename, "name"));
  _user->set_surname(_xmlParser->getNodeValue(filename, "surname"));
  _user->set_nickname(_xmlParser->getNodeValue(filename, "nick"));
  _user->set_adress(_xmlParser->getNodeValue(filename, "address"));
  _user->set_phone(_xmlParser->getNodeValue(filename, "phone"));
  // DAM pile : status + module
  // _user->set_status(char[2][0]);
  // _user->set_module(chars[3][0]);
  // 
  
  std::cout << "test connect" << std::endl;
}

void		SCommandsValue::subscribe(std::vector<char *> chars, std::vector<int> ints)
{
  // DAM : générer l'id
  std::string filename;
  
  filename = chars[0];
  filename += ".xml";
  _xmlParser->generateFile(filename);
  _xmlParser->updateNode(filename, "login", chars[1]);
  _xmlParser->updateNode(filename, "password", chars[2]);
  // NEEKO creer le fichier [id_login].xml (juste psw & login) (met un id bidon)
}

void		SCommandsValue::nick(std::vector<char *> chars, std::vector<int> ints)
{
  // NEKKO changer le valeur dans UserInfo + dans le [id_login].xml (recup la valeur dans la pile)
  std::string filename;
  
  filename = chars[0];
  filename += ".xml";
  _xmlParser->updateNode(filename, "nick", chars[1]);
}

void		SCommandsValue::status(std::vector<char *> chars, std::vector<int> ints)
{
  std::string filename;
  
  filename = chars[0];
  filename += ".xml";
  _xmlParser->updateNode(filename, "status", chars[1]);
  // NEKKO changer le valeur dans UserInfo + dans le [id_login].xml (recup la valeur dans la pile)
}

void		SCommandsValue::module(std::vector<char *> chars, std::vector<int> ints)
{
  std::string filename;
  
  filename = chars[0];
  filename += ".xml";
  _xmlParser->updateNode(filename, "module", chars[1]);
  // NEKKO changer le valeur dans UserInfo + dans le [id_login].xml (recup la valeur dans la pile)
}

void		SCommandsValue::birth(std::vector<char *> chars, std::vector<int> ints)
{
  std::string filename;
  
  filename = chars[0];
  filename += ".xml";
  _xmlParser->updateNode(filename, "birth", chars[1]);
  // NEKKO changer le valeur dans UserInfo + dans le [id_login].xml (recup la valeur dans la pile)
}

void		SCommandsValue::surname(std::vector<char *> chars, std::vector<int> ints)
{
  std::string filename;
  
  filename = chars[0];
  filename += ".xml";
  _xmlParser->updateNode(filename, "surname", chars[1]);
  // NEKKO changer le valeur dans UserInfo + dans le [id_login].xml (recup la valeur dans la pile)
}

void		SCommandsValue::name(std::vector<char *> chars, std::vector<int> ints)
{
  std::string filename;
  
  filename = chars[0];
  filename += ".xml";
  _xmlParser->updateNode(filename, "name", chars[1]);
  // NEKKO changer le valeur dans UserInfo + dans le [id_login].xml (recup la valeur dans la pile)
}

void		SCommandsValue::address(std::vector<char *> chars, std::vector<int> ints)
{
  std::string filename;
  
  filename = chars[0];
  filename += ".xml";
  _xmlParser->updateNode(filename, "address", chars[1]);
  // NEKKO changer le valeur dans UserInfo + dans le [id_login].xml (recup la valeur dans la pile)
}

void		SCommandsValue::phone(std::vector<char *> chars, std::vector<int> ints)
{
  std::string filename;
  
  filename = chars[0];
  filename += ".xml";
  _xmlParser->updateNode(filename, "phone", chars[1]);
  // NEKKO changer le valeur dans UserInfo + dans le [id_login].xml (recup la valeur dans la pile)
}

void		SCommandsValue::addRequest(std::vector<char *> chars, std::vector<int> ints)
{
  DIR		*dir;
  struct dirent *file;
  std::string	friendfilename;
  std::string	filename;
  std::size_t	pos;
  int		idpos = 0;
  std::string	id;

  if ((dir = opendir(".")) != NULL)
    {
      while ((file = readdir(dir)) != NULL)
	{
	  friendfilename = file->d_name;
	  if ((pos = friendfilename.find(chars[1])) != std::string::npos)
	    {
	      idpos = pos + strlen(chars[1]) + 1;
	      std::cout << "ID = " <<  friendfilename.substr(idpos, idpos + 4 - friendfilename.find(".xml")) << std::endl;
	      id = friendfilename.substr(idpos, idpos + 4 - friendfilename.find(".xml"));
	      filename = chars[0];
	      filename += ".xml";
	      _xmlParser->addChildToParent(filename, "contacts", "id", id);
	      //	      _xmlParser->addChildToParent(friendfilename, "contacts", "id");
	    }
	}
      closedir(dir);
    }
  else
    {
      std::cerr << "Could not open directory" << std::endl;
      return ;
    }
  
  // NEKKO add le nouveau contact dans [id_login].xml du user + add contact id dans celui qui vient d'etre add 
  // -> Dans proto ajout en fonction du login sauf que dans xml c'est un ID. Comment check le login ?
  
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
