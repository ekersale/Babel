#ifndef	__CLIENT_H_
#define	__CLIENT_H__

#include	<iostream>
#include	<string>
#include	<map>
#include	<queue>

// #include	<QDomDocument>
#include	<QString>

#include	"Lexer.hh"
#include	"IDllLoader.hh"

class Client
{
public:
   Lexer * get_lexer(void) const;
   IDllLoader * get_loader(void) const;
   void set_lexer(Lexer* new_lexer);
   void set_loader(IDllLoader* new_loader);
   Client();
   Client(const Client& oldClient);
   ~Client();

private:
   Lexer * _lexer;
   IDllLoader * _loader;


};

#endif
