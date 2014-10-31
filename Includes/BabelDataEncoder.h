#ifndef __BABELDATAENCODER_H__
#define __BABELDATAENCODER_H__

#include "IBabelData.h"
#include "IModule.h"

class BabelDataEncoder : public IBabelData, public IModule
{
public:
   IModule * createObject(void);
   bool initStructure(void);
   bool initBits(void);
   bool setQuality(void);
   int destroyStruct(void);
   bool resetBits(void);
   int destroyState(void);
   bool write(void);
   bool encode(void);
   bool print_error(void) const;
   SpeexBits get_bits(void) const;
   void * get_state(void) const;
   char * get_memory(void) const;
   float * get_input(void) const;
   short * get_in(void) const;
   void set_bits(SpeexBits new_bits);
   void set_state(void * new_state);
   void set_memory(char * new_memory);
   void set_input(float * new_input);
   void set_in(short * new_in);
   BabelDataEncoder();
   BabelDataEncoder(const BabelDataEncoder& oldBabelDataEncoder);
   ~BabelDataEncoder();

protected:
private:
   SpeexBits _bits;
   void * _state;
   char * _memory;
   float * _input;
   short * _in;


};

#endif
