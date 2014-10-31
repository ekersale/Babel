#ifndef	__CLIENT_H_
#define	__CLIENT_H__

#include	<iostream>
#include	<string>
#include	<map>
#include	<queue>

// #include	<QDomDocument>
#include	<QString>

#include	"Lexer.h"
#include	"IDllLoader.h"

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

protected:
private:
   Lexer * _lexer;
   IDllLoader * _loader;


};

#endif
