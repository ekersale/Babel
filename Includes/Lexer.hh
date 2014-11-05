#ifndef	__LEXER_H__
#define __LEXER_H__

#include "XMLParser.hh"

class Lexer
{
public:
   bool inCmd(void);
   int inInt(void);
   char inChar(void);
   int inType(void);
   char * outCmd(void);
   int outInt(void);
   int outChar(void);
   int outType(void);
   void print_error(void);
   std::queue<char> get_charPile(void) const;
   std::queue<int> get_intPile(void) const;
   void * get_bufferBegin(void) const;
   XMLParser * get_xmlParser(void) const;
   void set_charPile(std::queue<char> new_charPile);
   void set_intPile(std::queue<int> new_intPile);
   void set_bufferBegin(void * new_bufferBegin);
   void set_xmlParser(XMLParser* new_xmlParser);
   Lexer();
   Lexer(const Lexer& oldLexer);
   ~Lexer();

protected:
private:
   std::queue<char> _charPile;
   std::queue<int> _intPile;
   void * _bufferBegin;
   XMLParser * _xmlParser;


};

#endif
