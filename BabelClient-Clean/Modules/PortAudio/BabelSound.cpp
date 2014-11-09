//
// BabelSound.cpp for Babel in /home/kersale/rendu/babel/Modules/PortAudio
// 
// Made by Elliot Kersalé
// Login   <kersal_e@epitech.net>
// 
// Started on  Sun Nov  2 18:34:20 2014 Elliot Kersalé
// Last update Wed Nov  5 17:30:19 2014 Sliman Desmars
//

#include "../../Includes/BabelSound.hh"

ABabelSound::ABabelSound()
{
  _stream = NULL;
}

ABabelSound::~ABabelSound()
{
}

bool			ABabelSound::printError(const int &error)
{
  std::cerr << Pa_GetErrorText(error) << std::endl;
  return (false);
}

bool            ABabelSound::initializePA()
{
  int			error = 0;
  
  if ((error = Pa_Initialize()) != paNoError)
    return (printError(error));
  return (true);
}

bool            ABabelSound::openStream()
{
  int error = 0;

  if ((error = Pa_OpenStream(&_stream, &_inputParam, &_outputParam, SAMPLE_RATE,
			     FRAMES_PER_BUFFER, paClipOff, NULL, NULL)) != paNoError)
    return (printError(error));
  return (true);
}

bool		ABabelSound::stopStream()
{
  int error = 0;
  if ((error = Pa_StopStream(_stream)) != paNoError)
    return (printError(error));
  return (true);
}

bool            ABabelSound::startStream()
{
  int			error = 0;
   
  if ((error = Pa_StartStream(_stream)) != paNoError)
    return (printError(error));
  (void)error;
  return (true);
}


bool            ABabelSound::initializeInput()
{
  if ((_inputParam.device = Pa_GetDefaultInputDevice()) == paNoDevice) {
    std::cerr << "Pa_GetDefaultInputDevice() failed" << std::endl;
    return (false);
  }
  _inputParam.channelCount = 2;
  _inputParam.sampleFormat = PA_SAMPLE_TYPE;
  _inputParam.suggestedLatency = Pa_GetDeviceInfo(_inputParam.device)->defaultLowInputLatency;
  _inputParam.hostApiSpecificStreamInfo = NULL;
  return (true);
}

bool            ABabelSound::initializeOutput()
{
  if ((_outputParam.device = Pa_GetDefaultOutputDevice()) == paNoDevice) {
    std::cerr << "Pa_GetDefaultOutputDevice() failed" << std::endl;
    return (false);
  }
  _outputParam.channelCount = 2;
  _outputParam.sampleFormat = PA_SAMPLE_TYPE;
  _outputParam.suggestedLatency = Pa_GetDeviceInfo(_outputParam.device)->defaultLowInputLatency;
  _outputParam.hostApiSpecificStreamInfo = NULL;
  return (true);
}

bool            ABabelSound::readStream()
{
  int			error = 0;

  if ((_recordedSamples = (SAMPLE *)malloc(FRAMES_PER_BUFFER * sizeof(SAMPLE) * NUM_CHANNELS)) == NULL) {
    std::cerr << "malloc() failed : error on allocating memory" << std::endl;
    return (false);
  }
  for (int i = 0; i<FRAMES_PER_BUFFER; i++)
    _recordedSamples[i] = 0;
  if ((error = Pa_ReadStream(_stream, _recordedSamples, FRAMES_PER_BUFFER)) != paNoError)
    return (printError(error));
  return (true);
}

float		*ABabelSound::getRecordedSamples()
{
  return (_recordedSamples);
}

bool		ABabelSound::closeStream()
{
  int		error = 0;
  
  if ((error = Pa_CloseStream(_stream)) != paNoError)
    return (printError(error));
  return (true);
}

bool            ABabelSound::writeStream(float *recordedSamples, int i)
{
  int		error = 0;

  if ((error = Pa_WriteStream(_stream, recordedSamples, i)) != paNoError)
    return (printError(error));
  return (true);
}
