#ifndef				_IBABEL_SOUND_H__
# define			_IBABEL_SOUND_H__

class				IBabelSound
{
protected:
	virtual bool		initializePA() = 0;
	virtual bool		initializeOutput() = 0;
	virtual bool		initializeInput() = 0;
	virtual bool		openStream() = 0;
	virtual bool		startStream() = 0;
	virtual bool		readStream() = 0;
	virtual bool		writeStream(float *, int) = 0;
	virtual bool		closeStream() = 0;
};

#endif // !_IBABEL_SOUND_H__
