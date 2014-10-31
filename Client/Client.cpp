#include "../Includes/Client.h"

Lexer * Client::get_lexer(void) const
{
   return _lexer;
}

IDllLoader * Client::get_loader(void) const
{
   return _loader;
}

void Client::set_lexer(Lexer* new_lexer)
{
   _lexer = new_lexer;
}

void Client::set_loader(IDllLoader* new_loader)
{
   _loader = new_loader;
}

Client::Client()
{
}

Client::Client(const Client& oldClient)
{
   _lexer = oldClient._lexer;
   _loader = oldClient._loader;
}

Client::~Client()
{
   // TODO : implement
}
