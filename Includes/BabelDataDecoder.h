#ifndef	__BABELDATADECODER_H__
#define	__BABELDATADECODER_H__

#include "IBabelData.h"
#include "IModule.h"

class BabelDataDecoder : public IBabelData, public IModule
{
public:
   IModule * createObject(void);
   bool initStructure(void);
   bool initBits(void);
   bool setQuality(void);
   bool resetBits(void);
   int destroyState(void);
   int destroyStruct(void);
   bool decode(void);
   bool read(void);
   bool print_error(void) const;
   void * get_state(void) const;
   char * get_outFile(void) const;
   FILE * get_fout(void) const;
   short * get_out(void) const;
   float * get_output(void) const;
   char * get_memory(void) const;
   SpeexBits get_bits(void) const;
   void set_state(void * new_state);
   void set_outFile(char * new_outFile);
   void set_fout(FILE * new_fout);
   void set_out(short * new_out);
   void set_output(float * new_output);
   void set_memory(char * new_memory);
   void set_bits(SpeexBits new_bits);
   BabelDataDecoder();
   BabelDataDecoder(const BabelDataDecoder& oldBabelDataDecoder);
   ~BabelDataDecoder();

protected:
private:
   char * _outFile;
   FILE * _fout;
   short * _out;
   float * _output;
   char * _memory;
   SpeexBits _bits;
   void * _state;


};

#endif
