#include				"XMLParser.hh"

XMLParser::XMLParser()
{
}

XMLParser::~XMLParser()
{
}

bool							XMLParser::print_error(const std::string &msg)
{
  std::cerr << "Function : " << msg << " failed" << std::endl;
  return (false);
}

bool							XMLParser::openFile(std::string filename)
{
  // Je passe cette fonction en bool pour qu'on puisse la tester avec sa valeur de retour
  // comme les autres fonctions dans le projet
  std::string				path;
  path = PATH;
  path += filename;
  QDomDocument				doc(stdStringToQString(path));
  QFile					xmldoc(stdStringToQString(path));
  QString				error;
  int					errorLine;
  int					errorColumn;

  if (!xmldoc.open(QIODevice::ReadOnly))
    {
      print_error(" Xml Open file ");
      return (false);
    }
  _doc = doc;
  if (!_doc.setContent(&xmldoc, false, &error, &errorLine, &errorColumn))
    {
      xmldoc.close();
      print_error(" Link Xml file to DOM file ");
      std::cerr << error.toStdString() << "on line " << errorLine << " and column " << errorColumn << std::endl;
      return (false);
    }
  xmldoc.close();
  return (true);
}

void							XMLParser::setDoc(QDomDocument doc)
{
  _doc = doc;
}

QDomDocument						XMLParser::getDoc(void) const
{
  return (this->_doc);
}


QString							XMLParser::stdStringToQString(std::string chaine)
{
  QString				str;
  
  str = QString::fromUtf8(chaine.c_str());
  return (str);
}

std::string						XMLParser::getNodeValue(std::string filename, std::string nodename)
{
  QDomElement				dom_elem;
  QDomNode				node;
  
  if (openFile(filename) == false)
    {
      print_error(" GetNodeValue ");
      return ("");
    }
  dom_elem = getDoc().documentElement();
  node = dom_elem.firstChild();
  while (!node.isNull())
    {
      QDomElement	elem = node.toElement();
      if (!elem.isNull() && elem.tagName() == stdStringToQString(nodename))
	return (elem.text().toStdString());
      node = node.nextSibling();
    }
  return ("");
}

std::map<std::string, std::string>			XMLParser::parseFile(std::string filename)
{
  QDomElement				dom_elem;
  QDomNode				node;
  std::map<std::string, std::string>	map;
  std::pair<std::string, std::string>	pair;

  if (openFile(filename) == false)
    return (map);
  dom_elem = getDoc().documentElement();
  node = dom_elem.firstChild();
  while (!node.isNull())
    {
      QDomElement			elem;

      elem = node.toElement();
      if (!elem.isNull())
	{
	  pair = std::make_pair(elem.tagName().toStdString(), elem.text().toStdString());
	  map.insert(map.end(), pair);
	}
      node = node.nextSibling();
    }
  return (map);
}

std::vector<int>					XMLParser::getClients(std::string filename)
{
  std::vector<int>				vec;
  QDomElement					dom_elem;
  QDomNode					node;

  if (openFile(filename) == false)
    return (vec);
  dom_elem = getDoc().documentElement();
  node = dom_elem.firstChildElement("contacts").firstChild();
  while (!node.isNull())
    {
      QDomElement	elem;
      
      elem = node.toElement();
      vec.push_back(elem.text().toInt());
      node = node.nextSibling();
    }
  return (vec);
}

bool							XMLParser::removeChild(std::string filename, std::string value)
{
  std::string				path;
  path = PATH;
  path += filename;
  std::ofstream				outFile("../XML_file/temp.xml");
  std::fstream				readFile(path.c_str(), std::fstream::in);
  std::string				line;

  if (outFile.fail())
    {
      print_error(" Ouverture temp.xml ");
      return (false);
    }
  if (readFile.fail())
    {
      print_error(" Lecture temp.xml ");
      return (false);
    }
  while (std::getline(readFile, line))
    {
      if (line.find("<id>" + value + "</id>") == std::string::npos)
	outFile << line << std::endl;
    }
  readFile.close();
  outFile.close();
  removeFile(path);
  renameFile("../XML_file/temp.xml", path);
  return (true);
}

void							XMLParser::createBalise(std::ofstream &stream, std::string balise)
{
  stream << balise << std::endl;
}

bool							XMLParser::addChildToParent(std::string filename, std::string parent,
								    std::string child, std::string value)
{
  std::string				path;
  path = PATH;
  path += filename;
  std::ofstream				outFile("../XML_file/temp.xml");
  std::fstream				readFile(path.c_str(), std::fstream::in);
  std::string				line;
  std::string				openBalise;
  std::string				childOpenBalise;
  std::string				childCloseBalise;

  if (outFile.fail())
    {
      print_error(" Ouverture temp.xml ");
      return (false);
    }
  if (readFile.fail())
    {
      print_error(" Lecture temp.xml ");
      return (false);
    }
  openBalise = "\t<" + parent + ">";
  childOpenBalise = "\n\t\t<" + child + ">";
  childCloseBalise = "</" + child + ">";
  while (std::getline(readFile, line))
    {
      size_t		pos;
      
      pos = line.find("<" + parent + ">");
      if (pos != std::string::npos)
	{
	  std::string	tmp;

	  tmp = openBalise;
	  tmp += childOpenBalise;
	  tmp += value;
	  tmp += childCloseBalise;
	  line = tmp;
	}
      outFile << line << std::endl;
    }
    readFile.close();
    outFile.close();
    removeFile(path);
    renameFile("../XML_file/temp.xml", path);
    return (true);
}

void						XMLParser::generateFile(std::string filename)
{
  std::string		path;
  path = PATH;
  path += filename;
  std::ofstream		file(path.c_str());
  std::string		id;
  std::string		ver;

  ver = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
  createBalise(file, ver);
  id = "<id>";
  createBalise(file, id);
  createBalise(file, "\t<login></login>");
  createBalise(file, "\t<password></password>");
  createBalise(file, "\t<nickname></nickname>");
  createBalise(file, "\t<status></status>");
  createBalise(file, "\t<module></module>");
  createBalise(file, "\t<birth></birth>");
  createBalise(file, "\t<surname></surname>");
  createBalise(file, "\t<name></name>");
  createBalise(file, "\t<address></address>");
  createBalise(file, "\t<phone></phone>");
  createBalise(file, "\t<contacts>");
  createBalise(file, "\t</contacts>");
  createBalise(file, "</id>");
}

bool						XMLParser::updateNode(std::string filename, std::string node, std::string value)
{
  std::string		path;
  path = PATH;
  path += filename;
  std::ofstream		outFile("../XML_file/temp.xml");
  std::fstream		readFile(path.c_str(), std::fstream::in);
  std::string		line;
  std::string		openBalise;
  std::string		closeBalise;

  if (outFile.fail())
    {
      print_error(" Could not open output file ");
      return (false);
    }
  if (readFile.fail())
    {
      print_error(" Could not read output file ");
      return (false);
    }
  openBalise = "\t<" + node + ">";
  closeBalise = "</" + node + ">";
  while (std::getline(readFile, line))
    {
      size_t		pos;

      pos = line.find("<" + node + ">");
      if (pos != std::string::npos)
	{
	  std::string	tmp;
	  
	  tmp = openBalise;
	  tmp += value;
	  tmp += closeBalise;
	  line = tmp;
	}
      outFile << line << std::endl;
    }
  readFile.close();
  outFile.close();
  removeFile(path);
  renameFile("../XML_file/temp.xml", path);
  return true;
}

bool						XMLParser::removeFile(std::string  filename)
{
  if (remove(filename.c_str()) != 0)
    {
      print_error(" Remove file ");
      return false;
    }
  return true;
}

bool						XMLParser::renameFile(std::string oldFilename, std::string newFilename)
{
  if (rename(oldFilename.c_str(), newFilename.c_str()) != 0)
    {
      print_error(" Rename file ");
      return false;
    }
  return true;
}

std::map<char, std::vector<unsigned char> >	XMLParser::getCommandArgs(std::string filename)
{
  std::map<char, std::vector<unsigned char> >		map;
  QDomElement						dom_elem;
  QDomNode						node;
  QDomElement						elem;
  QDomElement						childelem;
  QDomNode						childnode;

  if (openFile(filename) == false)
    return (map);
  dom_elem = getDoc().documentElement();
  node = dom_elem.firstChild();
  while (!node.isNull())
    {
      elem = node.toElement();
      if (!elem.isNull())
	{
	  std::vector<unsigned char>			vec;
	  childnode = elem.firstChild().toElement().firstChild();
	  while (!childnode.isNull())
	    {
	      childelem = childnode.toElement();
	      vec.push_back(childelem.text().toInt());
	      childnode = childnode.nextSibling();
	    }
	  map[node.toElement().attribute("nb").toInt()] = vec;
	}
      node = node.nextSibling();
    }
  return (map);
}

unsigned int	XMLParser::countXmlFiles()
{
  QDir		dir(PATH);
  QStringList	filter;

  filter << "*.xml";
  dir.setFilter(QDir::Files);
  dir.setSorting(QDir::Name);
  dir.setNameFilters(filter);
  return (dir.count());
}

