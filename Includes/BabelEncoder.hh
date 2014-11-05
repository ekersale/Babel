/*
** BabelEncoder.h for Babel in /home/kersale/project/BabelSound
** 
** Made by Elliot Kersalé
** Login   <kersal_e@epitech.net>
** 
** Started on  Wed Oct 29 13:52:47 2014 Elliot Kersalé
// Last update Wed Nov  5 17:34:27 2014 Sliman Desmars
*/

#ifndef				_BABEL_ENCODER_H__
# define			_BABEL_ENCODER_H__

#include			"IBabelEncoder.hh"

#include			<opus/opus.h>
#include			<iostream>
#include			<cstdlib>
#include			<cstdio>
#include			<string.h>


#define				SAMPLE_RATE (24000)
#define				CHANNELS (2)
#define				APPLICATION OPUS_APPLICATION_VOIP

class                           BabelEncoder : public IBabelEncoder
{
public:
  BabelEncoder();
  ~BabelEncoder();

  bool				opusEncoderCreate();
  bool				opusDecoderCreate();
  void				opusDestroy();
  unsigned char			*encodeFrame(const float *, int);
  float				*decodeFrame(const unsigned char *, int );
  int				getBytesDecode();
  int				getEncodedDataSize(void);

private:
  OpusEncoder			*_encoder;
  OpusDecoder			*_decoder;
  int				_encoded_data_size;
  int				num_channels;
  int				_bytes;
};

#endif				//!_BABEL_ENCODER_H__
