#include <iterator>
#include <QApplication>
#include <QtXml>
#include "XMLParser.h"

void printmap(std::map<std::string, std::string> map)
{
  std::map<std::string, std::string>::iterator it;

  for (it = map.begin(); it != map.end(); ++it)
    {
      std::cout << it->first << " -> " << it->second << std::endl;
    }
}

void printvector(std::vector<unsigned char> vec)
{
  std::vector<unsigned char>::iterator it;

  for (it = vec.begin(); it != vec.end(); ++it)
    {
      std::cout << (int)*it << std::endl;
    }
}

void printmap(std::map<char, std::vector<unsigned char> > map)
{
  std::map<char, std::vector<unsigned char> >::iterator it;

  for (it = map.begin(); it != map.end(); ++it)
    {
      std::cout << "---------" << std::endl;
      std::cout << (int)it->first << " -> " << std::endl;
      printvector(it->second);
    }
}

void printvector(std::vector<int> vec)
{
  std::vector<int>::iterator it;

  for (it = vec.begin(); it != vec.end(); ++it)
    {
      std::cout << *it << std::endl;
    }
}



int main(int argc, char *argv[])
{
  QApplication::addLibraryPath(".");
  QApplication        a(argc, argv);
  XMLParser           *Dom = new XMLParser();
  std::map<std::string, std::string> map;
  std::map<char, std::vector<unsigned char> > command;
  std::vector<int>                   vec;

  std::cout << Dom->getNodeValue("books.xml", "phone") << std::endl; // affiche la valeur de la balise "phone"
  Dom->generateFile("42.xml"); // créé et remplis un fichier
  Dom->updateNode("42.xml", "surname", "Vinvin des bois"); // remplace la valeur "surname" par "vinvin des bois"
  Dom->addChildToParent("42.xml", "contacts", "id", "4222"); // ajoute le sous-noeud "id" avec la valeur 4222 à "contacts"
  Dom->updateNode("42.xml", "dddd", "Vinvin des bois"); // rien ne se passe car "dddd" n'existe pas
  Dom->addChildToParent("42.xml", "contacts", "id", "4221");
  Dom->updateNode("42.xml", "nick", "Vinvin");
  Dom->updateNode("42.xml", "phone", "064848947");
  map = Dom->parseFile("42.xml"); // retourne une std::map<string, string> contenant les valeurs de tout le fichier
  printmap(map); // affiche la map
  vec = Dom->getClients("42.xml"); // retourne un std::vector<int> contenant tous les ID des amis
  printvector(vec);
  command = Dom->getCommandArgs("commands.xml"); // retourne une map contenant les args
  printmap(command);
  return a.exec();
}
