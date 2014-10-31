#include "../../Includes/BabelDataDecoder.h"

IModule * BabelDataDecoder::createObject(void)
{

}

bool BabelDataDecoder::initStructure(void)
{
}

bool BabelDataDecoder::initBits(void)
{

}

bool BabelDataDecoder::setQuality(void)
{
}

bool BabelDataDecoder::resetBits(void)
{

}

int BabelDataDecoder::destroyState(void)
{

}

int BabelDataDecoder::destroyStruct(void)
{

}

bool BabelDataDecoder::decode(void)
{

}

bool BabelDataDecoder::read(void)
{

}

bool BabelDataDecoder::print_error(void) const
{
}

void * BabelDataDecoder::get_state(void) const
{
   return _state;
}

char * BabelDataDecoder::get_outFile(void) const
{
   return _outFile;
}

FILE * BabelDataDecoder::get_fout(void) const
{
   return _fout;
}

short * BabelDataDecoder::get_out(void) const
{
   return _out;
}

float * BabelDataDecoder::get_output(void) const
{
   return _output;
}

char * BabelDataDecoder::get_memory(void) const
{
   return _memory;
}

SpeexBits BabelDataDecoder::get_bits(void) const
{
   return _bits;
}

void BabelDataDecoder::set_state(void * new_state)
{
   _state = new_state;
}

void BabelDataDecoder::set_outFile(char * new_outFile)
{
   _outFile = new_outFile;
}

void BabelDataDecoder::set_fout(FILE * new_fout)
{
   _fout = new_fout;
}

void BabelDataDecoder::set_out(short * new_out)
{
   _out = new_out;
}

void BabelDataDecoder::set_output(float * new_output)
{
   _output = new_output;
}

void BabelDataDecoder::set_memory(char * new_memory)
{
   _memory = new_memory;
}

void BabelDataDecoder::set_bits(SpeexBits new_bits)
{
   _bits = new_bits;
}

BabelDataDecoder::BabelDataDecoder()
{
}

BabelDataDecoder::BabelDataDecoder(const BabelDataDecoder& oldBabelDataDecoder)
{
   _outFile = oldBabelDataDecoder._outFile;
   _fout = oldBabelDataDecoder._fout;
   _out = oldBabelDataDecoder._out;
   _output = oldBabelDataDecoder._output;
   _memory = oldBabelDataDecoder._memory;
   _bits = oldBabelDataDecoder._bits;
   _state = oldBabelDataDecoder._state;
}

BabelDataDecoder::~BabelDataDecoder()
{
 
}
