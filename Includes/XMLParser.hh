#ifndef	__XMLPARSER_H__
#define __XMLPARSER_H__

#include	<iostream>
#include	<fstream>
#include	<string>
#include	<vector>
#include	<map>
#include	<utility>
#include	<cstdio>

#ifdef _WIN32
#include	<QtXml/QtXml>
#include	<QtXml/QDomDocument>
#include	<QtCore/QString>
#else
#include	<QtXml>
#include	<QDomDocument>
#include	<QString>
#endif


#define		PATH		"../XML_file/"

class					XMLParser
{
 public:
  XMLParser();
  ~XMLParser();
  void						setDoc(QDomDocument new_doc);
  QDomDocument					getDoc(void) const;
  std::map<std::string, std::string>		parseFile(std::string);
  std::string					getNodeValue(std::string, std::string);
  std::vector<int>				getClients(std::string);
  bool						updateNode(std::string, std::string, std::string);
  bool						addChildToParent(std::string, std::string, std::string, std::string);
  void						generateFile(std::string);
  void						createBalise(std::ofstream &, std::string);
  bool						print_error(const std::string &msg);
  std::map<char, std::vector<unsigned char> >	getCommandArgs(std::string);
  bool						removeChild(std::string, std::string);

private:
  QDomDocument				_doc;
  QString				stdStringToQString(std::string);
  bool					openFile(std::string);
  bool					removeFile(std::string);
  bool					renameFile(std::string, std::string);
  
};

#endif
