//
// BabelEncoder.cpp for Babel in /home/kersale/project/BabelSound
// 
// Made by Elliot Kersalé
// Login   <kersal_e@epitech.net>
// 
// Started on  Fri Oct 31 23:48:20 2014 Elliot Kersalé
// Last update Wed Nov  5 17:50:11 2014 Sliman Desmars
//

#include		"../../Includes/BabelEncoder.hh"

BabelEncoder::BabelEncoder() {
  num_channels = CHANNELS;
  _encoder = NULL;
  _decoder = NULL;
  _bytes = 0;
}

BabelEncoder::~BabelEncoder() {
  opusDestroy();
}

int			BabelEncoder::getEncodedDataSize(void)
{
  return (_encoded_data_size);
}

bool			BabelEncoder::opusEncoderCreate() {
  int			error;

  error = 0;
  _encoder = opus_encoder_create(SAMPLE_RATE, num_channels, OPUS_APPLICATION_VOIP, &error);
  if (error != OPUS_OK) {
    std::cerr << "opus_encoder_create() failed : error on initializing encoder" << std::endl;
    return (false);
  }
  opus_int32		rate;
  opus_encoder_ctl(_encoder, OPUS_GET_BANDWIDTH(&rate));
  _encoded_data_size = rate;
  return (true);
}

bool			BabelEncoder::opusDecoderCreate() {
  int			error;

  error = 0;
  _decoder = opus_decoder_create(SAMPLE_RATE, num_channels, &error);  
  if (error != OPUS_OK) {
    std::cerr << "opus_decoder_create() failed : error on initializing decoder" << std::endl;
    return (false);
  }
  return (true);
}

void			BabelEncoder::opusDestroy() {
  if (_encoder != NULL)
    opus_encoder_destroy(_encoder);
  if (_decoder != NULL)
    opus_decoder_destroy(_decoder);
}



unsigned char		*BabelEncoder::encodeFrame(const float *frame, int frame_size) {
  unsigned char		*compressed_buffer;
  int			error;
  
  if (frame == NULL)
    return (NULL);
  compressed_buffer = (unsigned char *)malloc(_encoded_data_size * sizeof(unsigned char));
  if ((error = opus_encode_float(_encoder, frame, frame_size, compressed_buffer,
				 _encoded_data_size)) != OPUS_OK) {
  }
  return (compressed_buffer);
}

float			*BabelEncoder::decodeFrame(const unsigned char *data, int frame_size)
{
  int			error;
  float			*frame;

  if (data == NULL)
    return (NULL);
  if ((error = opus_packet_get_nb_channels(data)) <= 0) {
    std::cerr << "opus_packet_get_nb_channels() failed : error on getting number of channels, trying with 2" << std::endl;
    error = 2;
  }
  if ((frame = (float *)malloc(frame_size * error * sizeof(float))) == NULL) {
    std::cerr << "malloc() failed : error on allocating memory" << std::endl;
    return (NULL);
  }
  memset(frame, 0, frame_size);
  if ((_bytes = opus_decode_float(_decoder, data, _encoded_data_size, frame, frame_size, 0)) != OPUS_OK) {
  }
  return (frame);
}

int			BabelEncoder::getBytesDecode()
{
  return (_bytes);
}
