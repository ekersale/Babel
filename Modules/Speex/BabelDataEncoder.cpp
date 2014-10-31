
#include "../../Includes/BabelDataEncoder.h"

IModule *BabelDataEncoder::createObject(void)
{
   // TODO : implement
}

bool BabelDataEncoder::initStructure(void)
{
   // TODO : implement
}

bool BabelDataEncoder::initBits(void)
{
   // TODO : implement
}


bool BabelDataEncoder::setQuality(void)
{
   // TODO : implement
}

int BabelDataEncoder::destroyStruct(void)
{
   // TODO : implement
}

bool BabelDataEncoder::resetBits(void)
{
   // TODO : implement
}

int BabelDataEncoder::destroyState(void)
{
   // TODO : implement
}

bool BabelDataEncoder::write(void)
{
   // TODO : implement
}

bool BabelDataEncoder::encode(void)
{
   // TODO : implement
}

bool BabelDataEncoder::print_error(void) const
{
   // TODO : implement
}

SpeexBits BabelDataEncoder::get_bits(void) const
{
   return _bits;
}

void * BabelDataEncoder::get_state(void) const
{
   return _state;
}

char * BabelDataEncoder::get_memory(void) const
{
   return _memory;
}

float * BabelDataEncoder::get_input(void) const
{
   return _input;
}

short * BabelDataEncoder::get_in(void) const
{
   return _in;
}

void BabelDataEncoder::set_bits(SpeexBits new_bits)
{
   _bits = new_bits;
}

void BabelDataEncoder::set_state(void * new_state)
{
   _state = new_state;
}

void BabelDataEncoder::set_memory(char * new_memory)
{
   _memory = new_memory;
}

void BabelDataEncoder::set_input(float * new_input)
{
   _input = new_input;
}

void BabelDataEncoder::set_in(short * new_in)
{
   _in = new_in;
}

BabelDataEncoder::BabelDataEncoder()
{
}

BabelDataEncoder::BabelDataEncoder(const BabelDataEncoder& oldBabelDataEncoder)
{
   _bits = oldBabelDataEncoder._bits;
   _state = oldBabelDataEncoder._state;
   _memory = oldBabelDataEncoder._memory;
   _input = oldBabelDataEncoder._input;
   _in = oldBabelDataEncoder._in;
}

BabelDataEncoder::~BabelDataEncoder()
{
   // TODO : implement
}
