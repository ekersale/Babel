#include			"Lexer.h"

bool				Lexer::inCmd(void)
{
   // TODO : implement
}

int				Lexer::inInt(void)
{
   // TODO : implement
}

char				Lexer::inChar(void)
{
   // TODO : implement
}

int				Lexer::inType(void)
{
   // TODO : implement
}

char				*Lexer::outCmd(void)
{
   // TODO : implement
}

int				Lexer::outInt(void)
{
   // TODO : implement
}

int				Lexer::outChar(void)
{
   // TODO : implement
}

int				Lexer::outType(void)
{
   // TODO : implement
}

void				Lexer::print_error(void)
{
   // TODO : implement
}

std::queue<char>		Lexer::get_charPile(void) const
{
   return _charPile;
}

std::queue<int>			Lexer::get_intPile(void) const
{
   return _intPile;
}

void				*Lexer::get_bufferBegin(void) const
{
   return _bufferBegin;
}

XMLParser			*Lexer::get_xmlParser(void) const
{
   return _xmlParser;
}

void				Lexer::set_charPile(std::queue<char> new_charPile)
{
   _charPile = new_charPile;
}

void				Lexer::set_intPile(std::queue<int> new_intPile)
{
   _intPile = new_intPile;
}

void				Lexer::set_bufferBegin(void * new_bufferBegin)
{
   _bufferBegin = new_bufferBegin;
}

void				Lexer::set_xmlParser(XMLParser* new_xmlParser)
{
   _xmlParser = new_xmlParser;
}

Lexer::Lexer()
{
   _bufferBegin = NULL;
   _xmlParser = NULL;
}

Lexer::Lexer(const Lexer& oldLexer)
{
   _charPile = oldLexer._charPile;
   _intPile = oldLexer._intPile;
   _bufferBegin = oldLexer._bufferBegin;
   _xmlParser = oldLexer._xmlParser;
}

Lexer::~Lexer()
{
   // TODO : implement
}
