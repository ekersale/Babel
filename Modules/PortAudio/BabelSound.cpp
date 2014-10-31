#include "../../Includes/BabelSound.h"

IModule * BabelSound::createObject(void)
{
   // TODO : implement
}

bool BabelSound::initializePA(void)
{
   // TODO : implement
}

bool BabelSound::initializeOutput(void)
{
   // TODO : implement
}

bool BabelSound::initializeInput(void)
{
   // TODO : implement
}

bool BabelSound::readStream(void)
{
   // TODO : implement
}

bool BabelSound::writeStream(void)
{
   // TODO : implement
}

bool BabelSound::openStream(void)
{
   // TODO : implement
}

bool BabelSound::readFile(void)
{
   // TODO : implement
}

bool BabelSound::writeFile(void)
{
   // TODO : implement
}

bool BabelSound::printError(void) const
{
   // TODO : implement
}

PaStream * BabelSound::get_stream(void) const
{
   return _stream;
}

int BabelSound::get_readBufferSize(void) const
{
   return _readBufferSize;
}

PaStreamParameters BabelSound::get_inputParams(void) const
{
   return _inputParams;
}

PaStreamParameters BabelSound::get_outputParams(void) const
{
   return _outputParams;
}

unsigned char * BabelSound::get_readBuffer(void) const
{
   return _readBuffer;
}

void BabelSound::set_stream(PaStream * new_stream)
{
   _stream = new_stream;
}

void BabelSound::set_readBufferSize(int new_readBufferSize)
{
   _readBufferSize = new_readBufferSize;
}

void BabelSound::set_inputParams(PaStreamParameters new_inputParams)
{
   _inputParams = new_inputParams;
}

void BabelSound::set_outputParams(PaStreamParameters new_outputParams)
{
   _outputParams = new_outputParams;
}

void BabelSound::set_readBuffer(unsigned char * new_readBuffer)
{
   _readBuffer = new_readBuffer;
}

BabelSound::BabelSound()
{
   _stream = NULL;
   _readBuffer = NULL;
}

BabelSound::BabelSound(const BabelSound& oldBabelSound)
{
   _stream = oldBabelSound._stream;
   _readBufferSize = oldBabelSound._readBufferSize;
   _inputParams = oldBabelSound._inputParams;
   _outputParams = oldBabelSound._outputParams;
   _readBuffer = oldBabelSound._readBuffer;
}

BabelSound::~BabelSound()
{
   // TODO : implement
}
