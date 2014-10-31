#ifndef	__BABELSOUND_H__
#define __BABELSOUND_H__

#include "IBabelSound.h"
#include "IModule.h"

class BabelSound : public IBabelSound, public IModule
{
public:
   IModule * createObject(void);
   bool initializePA(void);
   bool initializeOutput(void);
   bool initializeInput(void);
   bool readStream(void);
   bool writeStream(void);
   bool openStream(void);
   bool readFile(void);
   bool writeFile(void);
   bool printError(void) const;
   PaStream * get_stream(void) const;
   int get_readBufferSize(void) const;
   PaStreamParameters get_inputParams(void) const;
   PaStreamParameters get_outputParams(void) const;
   unsigned char * get_readBuffer(void) const;
   void set_stream(PaStream * new_stream);
   void set_readBufferSize(int new_readBufferSize);
   void set_inputParams(PaStreamParameters new_inputParams);
   void set_outputParams(PaStreamParameters new_outputParams);
   void set_readBuffer(unsigned char * new_readBuffer);
   BabelSound();
   BabelSound(const BabelSound& oldBabelSound);
   ~BabelSound();

protected:
private:
   PaStream * _stream;
   int _readBufferSize;
   PaStreamParameters _inputParams;
   PaStreamParameters _outputParams;
   unsigned char * _readBuffer;


};

#endif
