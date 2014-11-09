/*
** IBabelEncoder.h for Babel in /home/kersale/project/BabelSound
** 
** Made by Elliot Kersalé
** Login   <kersal_e@epitech.net>
** 
** Started on  Sat Nov  1 11:27:56 2014 Elliot Kersalé
// Last update Sat Nov  1 11:32:26 2014 Elliot Kersalé
*/

#ifndef			_IBABEL_ENCODER_H__
# define		_IBABEL_ENCODER_H__

class			IBabelEncoder
{
 public:
  virtual bool			opusEncoderCreate() = 0;
  virtual bool			opusDecoderCreate() = 0;
  virtual void			opusDestroy() = 0;
  virtual unsigned char		*encodeFrame(const float*, int) = 0;
  virtual float			*decodeFrame(const unsigned char*, int) = 0;
};


#endif		//	!_IBABEL_ENCODER_H__	
