#ifndef					_BABEL_SOUND_H__
# define				_BABEL_SOUND_H__

#include				<portaudio.h>
#include				<iostream>
#include				<cstdlib>
#include				<cstdio>

#include				"IBabelSound.h"


#define					NUM_CHANNELS		(2)
#define					SAMPLE_RATE		(24000)
#define					FRAMES_PER_BUFFER	(480)
#define					PA_SAMPLE_TYPE		paFloat32

typedef float				SAMPLE;

class					ABabelSound : public IBabelSound
{
public:
	ABabelSound();
	~ABabelSound();

	bool				initializePA();
	bool				initializeOutput();
	bool				initializeInput();
	bool				openStream();
	bool				startStream();
	bool				readStream();
	bool				writeStream(float *, int i);
	bool				printError(const int &);
	float				*getRecordedSamples();
	bool				closeStream();

private:
	PaStream			*_stream;
	PaStreamParameters		_inputParam;
	PaStreamParameters		_outputParam;
	SAMPLE				*_recordedSamples;
};

#endif					// !_BABEL_SOUND_H__
