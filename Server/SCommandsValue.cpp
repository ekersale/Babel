#include "SCommandsValue.hh"
#include "dirent.h"
#include "Server.hh"

SCommandsValue::SCommandsValue(User *user)
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
  _user = user;
  _xmlParser = _user->get_server()->get_xmlParser();
}

SCommandsValue::~SCommandsValue() {
}

int		SCommandsValue::cmdVal(IPacketInfo *packet_info)
{
  if (methodPtr.find(packet_info->getCmd()) != methodPtr.end())
    {
      std::cout << "\n\t - - - - - - getCmd() is " << packet_info->getCmd() << "\n";
      (this->*methodPtr[packet_info->getCmd()])(packet_info->getChars(), packet_info->getInts());
    }
  else
    return (-1);
  return (0);
}

std::string	SCommandsValue::getFilename(std::string _login, int _id = -1)
{
  std::string	filename;
  std::size_t	pos;
  int		idpos = 0;
  std::string	id;
  int		toNb;
  QDir		dir(PATH);

  dir.setFilter(QDir::Files);
  dir.setSorting(QDir::Name);
  QFileInfoList filelist = dir.entryInfoList();
  for (int i = 0; i < filelist.size(); ++i)
    {
      QFileInfo fileInfo = filelist.at(i);
      filename = fileInfo.fileName().toStdString();
      if ((pos = filename.find(_login)) != std::string::npos)
	{
	  if (filename.at(_login.length()) == '-')
	    {
	      idpos = pos + _login.length() + 1;
	      id = filename.substr(idpos, idpos + 4 - filename.find(".xml"));
	      std::istringstream(id) >> toNb;
	      if (_id == -1 || _id == toNb)
		return (filename);
	    }
	}      
    }
  return ("");
}

int	SCommandsValue::getIdFromLogin(std::string _login)
{
  std::string	filename;
  std::size_t	pos;
  int		idpos = 0;
  std::string	id;
  int toNb;
  QDir		dir(PATH);

  dir.setFilter(QDir::Files);
  dir.setSorting(QDir::Name);
  QFileInfoList filelist = dir.entryInfoList();
  for (int i = 0; i < filelist.size(); ++i)
    {
      QFileInfo fileInfo = filelist.at(i);
      filename = fileInfo.fileName().toStdString();
      if ((pos = filename.find(_login)) != std::string::npos)
	{
	  if (filename.at(_login.length()) == '-')
	    {
	      idpos = pos + _login.length() + 1;
	      id = filename.substr(idpos, idpos + 4 - filename.find(".xml"));
	      std::istringstream(id) >> toNb;
	      return (toNb);
	    }
	}
    }
  return (-1);
}

std::string	SCommandsValue::getFilenameById(int _id)
{
  std::string	filename;
  std::size_t	pos;
  std::string	id;
  QDir		dir(PATH);

  id = intToStdString(_id);
  dir.setFilter(QDir::Files);
  dir.setSorting(QDir::Name);
  QFileInfoList filelist = dir.entryInfoList();
  for (int i = 0; i < filelist.size(); ++i)
    {
      QFileInfo fileInfo = filelist.at(i);
      filename = fileInfo.fileName().toStdString();  
      if ((pos = filename.find(id)) != std::string::npos)
	{
	  if (filename.at(pos - 1) == '-' && filename.at(pos + id.length() == '.'))
	    return (filename);
	}
    }
  return ("");
}

std::string	SCommandsValue::intToStdString(int nb)
{
  std::string res;
  std::stringstream toStr;

  toStr << nb;
  return (toStr.str());
}

#define		RET_OK	0
#define		RET_WRONG_LOG  1
#define		RET_WRONG_PSW	2

void		SCommandsValue::connect(std::vector<const char *> chars, std::vector<int> ints)
{
  std::string	filename;
  int		id;

  filename = getFilename(chars[0]);
  std::cout << "Login is : " << chars[0] << "\n";
  std::cout << "Psw is : " << chars[1] << "\n";
  if ((id = getIdFromLogin(chars[0])) == -1)
    {
      _user->authAnswer((char)RET_WRONG_LOG);
      std::cout << "Wrong log\n";
      return ;
    }
  puts("3");
  std::cout << "ID = " << id << std::endl;
  if (strcmp(chars[1], _xmlParser->getNodeValue(filename, "password").c_str()) == 0)
    {
      std::cout << "Good passwd" << std::endl;
      _user->set_psw(_xmlParser->getNodeValue(filename, "password"));
      _user->set_login(_xmlParser->getNodeValue(filename, "login"));
      _user->set_birth(_xmlParser->getNodeValue(filename, "birth"));
      _user->set_name(_xmlParser->getNodeValue(filename, "name"));
      _user->set_surname(_xmlParser->getNodeValue(filename, "surname"));
      _user->set_nickname(_xmlParser->getNodeValue(filename, "nick"));
      _user->set_adress(_xmlParser->getNodeValue(filename, "address"));
      _user->set_phone(_xmlParser->getNodeValue(filename, "phone"));
      _user->set_status(chars[2][0]);
      _user->set_module(chars[3][0]);
      std::cout << "\n\t Erase bloc at id : " <<_user->get_id() << "\n";
      _user->get_server()->get_users().erase(_user->get_id());
      std::cout << "\tCreate bloc at id : " << id << "\n\n";
      _user->get_server()->get_users()[id] = _user;
      _user->set_id(id);
      _user->authAnswer((char)RET_OK);
      std::cout << "Log OKK\n";
    }
  else
    {
      _user->authAnswer((char)RET_WRONG_PSW);
      std::cout << "Wrong Pass\n";
    }
}

void		SCommandsValue::subscribe(std::vector<const char *> chars, std::vector<int> ints)
{
  // DAM : générer l'id
  std::string filename;
  
  filename = chars[0];
  filename += ".xml";
  _xmlParser->generateFile(filename);
  std::cout << "filename = " <<  filename << std::endl;
  _xmlParser->updateNode(filename, "login", chars[0]);
  _xmlParser->updateNode(filename, "password", chars[1]);
  _user->set_login(chars[0]);
  _user->set_psw(chars[1]);
  _user->set_module(chars[2][0]);
  std::cout << "\n\t Erase bloc at id : " <<_user->get_id() << "\n";
  _user->get_server()->get_users().erase(_user->get_id());
  std::cout << "\tCreate bloc at id : " << _user->get_server()->get_tmpMax() << "\n\n";
  _user->get_server()->get_users()[_user->get_server()->get_tmpMax()] = _user;
  _user->set_id(_user->get_server()->get_tmpMax());
  _user->get_server()->increment_tmpMax();
  _user->authAnswer((char)RET_OK); //To check
}


// ALL need to push to contact
void		SCommandsValue::nick(std::vector<const char *> chars, std::vector<int> ints)
{
  std::string filename;
  
  (void)ints;
  _user->set_login("giraud_d"); // POUR TEST
  filename = getFilename(_user->get_login());
  _xmlParser->updateNode(filename, "nickname", chars[0]);
  _user->set_nickname(chars[0]);
}

void		SCommandsValue::status(std::vector<const char *> chars, std::vector<int> ints)
{
  std::string filename;

  (void)ints;  
  _user->set_login("giraud_d"); // POUR TEST
  filename = getFilename(_user->get_login());
  _xmlParser->updateNode(filename, "status", chars[0]);
  _user->set_status(chars[0][0]);
}

void		SCommandsValue::module(std::vector<const char *> chars, std::vector<int> ints)
{
  std::string filename;

  (void)ints;    
  _user->set_login("giraud_d"); // POUR TEST
  filename = getFilename(_user->get_login());
  _xmlParser->updateNode(filename, "module", chars[0]);
  _user->set_module(chars[0][0]);
}

void		SCommandsValue::birth(std::vector<const char *> chars, std::vector<int> ints)
{
  std::string filename;
  
  (void)ints;
  _user->set_login("giraud_d"); // POUR TEST
  filename = getFilename(_user->get_login());
  _xmlParser->updateNode(filename, "birth", chars[0]);
  _user->set_birth(chars[0]);
}

void		SCommandsValue::surname(std::vector<const char *> chars, std::vector<int> ints)
{
  std::string filename;
  
  (void)ints;  
  _user->set_login("giraud_d"); // POUR TEST
  filename = getFilename(_user->get_login());
  _xmlParser->updateNode(filename, "surname", chars[0]);
  _user->set_surname(chars[0]);
}

void		SCommandsValue::name(std::vector<const char *> chars, std::vector<int> ints)
{
  std::string filename;
  
  (void)ints;  
  _user->set_login("giraud_d"); // POUR TEST
  filename = getFilename(_user->get_login());
  _xmlParser->updateNode(filename, "name", chars[0]);
  _user->set_name(chars[0]);
}

void		SCommandsValue::address(std::vector<const char *> chars, std::vector<int> ints)
{
  std::string filename;
  
  (void)ints;  
  _user->set_login("giraud_d"); // POUR TEST
  filename = getFilename(_user->get_login());
  _xmlParser->updateNode(filename, "address", chars[0]);
  _user->set_adress(chars[0]);
}

void		SCommandsValue::phone(std::vector<const char *> chars, std::vector<int> ints)
{
  std::string filename;
  
  (void)ints;  
  _user->set_login("giraud_d"); // POUR TEST
  filename = getFilename(_user->get_login());
  _xmlParser->updateNode(filename, "phone", chars[0]);
  _user->set_name(chars[0]);
}

void		SCommandsValue::addRequest(std::vector<const char *> chars, std::vector<int> ints)
{
  std::string filename;
  std::string friendfilename;

  _user->set_login("giraud_d"); // POUR TEST
  filename = getFilename(_user->get_login());
  friendfilename = getFilename(chars[0]);
  _xmlParser->addChildToParent(filename, "contacts", "id", intToStdString(getIdFromLogin(chars[0])));
  _xmlParser->addChildToParent(friendfilename, "contacts", "id", intToStdString(getIdFromLogin(_user->get_login())));
  // NEKKO add le nouveau contact dans [id_login].xml du user + add contact id dans celui qui vient d'etre add 
}

void		SCommandsValue::removeRequest(std::vector<const char *> chars, std::vector<int> ints)
{
  // NEKKO comme au dessus mais le contraire
  std::string	filename;
  std::string	friendfilename;

  _user->set_login("giraud_d"); // POUR TEST
  filename = getFilename(_user->get_login());
  friendfilename = getFilenameById(ints[0]);  
  _xmlParser->removeChild(filename, intToStdString(ints[0]));
  _xmlParser->removeChild(friendfilename, intToStdString(getIdFromLogin(_user->get_login())));
}

void		SCommandsValue::call(std::vector<const char *> chars, std::vector<int> ints)
{

}

void		SCommandsValue::requestAnswer(std::vector<const char *> chars, std::vector<int> ints)
{

}
