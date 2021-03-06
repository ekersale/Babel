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

#define		PATH		"XML_file/"
// #define		PATH_SERVER		"../XML_file/l"

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
  bool						updateNode(std::string, std::string, std::string) const;
  bool						addChildToParent(std::string, std::string, std::string, std::string) const;
  void						generateFile(std::string) const;
  void						createBalise(std::ofstream &, std::string) const;
  bool						print_error(const std::string &msg) const;
  std::map<char, std::vector<unsigned char> >	getCommandArgs(std::string);
  bool						removeChild(std::string, std::string) const;
  unsigned int  countXmlFiles();

private:
  QDomDocument				_doc;
  QString				stdStringToQString(std::string) const;
  bool					openFile(std::string);
  bool					removeFile(std::string) const;
  bool					renameFile(std::string, std::string) const;
  
};

#endif
