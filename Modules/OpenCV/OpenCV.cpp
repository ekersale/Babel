// #include		"../../Includes/OpenCV.hh"

#include		"OpenCV.hh"

OpenCV::OpenCV(QObject *parent) : QThread(parent)
{
	_stop = true;
	_delay = 0;
}

OpenCV::~OpenCV()
{
}

void                    OpenCV::play()
{
	if (!isRunning())
	{
		if (isStopped())
			_stop = false;
		start(LowPriority);
	}
}

void                    OpenCV::stop()
{
	_stop = true;
}

int                     OpenCV::getFrameSize(cv::Mat frame)
{
	int                     i;

	i = 0;
	unsigned char *test = (unsigned char*)(frame.data);
	while (test[i])
		i++;
	return i;
}

bool                    OpenCV::isStopped() const
{
	return this->_stop;
}

void                    OpenCV::run()
{
	cv::VideoCapture        capture(0);
	cv::Mat         frame;
	cv::Mat         RGBframe;
	QImage          img;

	capture.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	if (!capture.isOpened())
	{
		std::cerr << "Can't Open caméra" << std::endl;
		return;
	}
	for (int i = 0; i < 20; i++)
	{
		int64   start;

		start = cv::getTickCount();
		capture >> frame;
		_frameRate = cv::getTickFrequency() / (cv::getTickCount() - start);
	}

	_delay = (1000 / _frameRate);

	while (1)
	{
		if (!capture.read(frame))
		{
			std::cerr << "Open CV can't read " << std::endl;
			return;
		}
		cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
		QImage img = QImage((const unsigned char *)(RGBframe.data),
			320, 240, QImage::Format_RGB888);
		emit processedImage(img, 0);
		cv::Mat *croppedImage1 = new cv::Mat;
		*croppedImage1 = RGBframe(cv::Rect(0, 0, 320, 30)).clone();
		cv::Mat *croppedImage2 = new cv::Mat;
		*croppedImage2 = RGBframe(cv::Rect(0, 30, 320, 30)).clone();
		cv::Mat *croppedImage3 = new cv::Mat;
		*croppedImage3 = RGBframe(cv::Rect(0, 60, 320, 30)).clone();
		cv::Mat *croppedImage4 = new cv::Mat;
		*croppedImage4 = RGBframe(cv::Rect(0, 90, 320, 30)).clone();
		cv::Mat *croppedImage5 = new cv::Mat;
		*croppedImage5 = RGBframe(cv::Rect(0, 120, 320, 30)).clone();
		cv::Mat *croppedImage6 = new cv::Mat;
		*croppedImage6 = RGBframe(cv::Rect(0, 150, 320, 30)).clone();
		cv::Mat *croppedImage7 = new cv::Mat;
		*croppedImage7 = RGBframe(cv::Rect(0, 180, 320, 30)).clone();
		cv::Mat *croppedImage8 = new cv::Mat;
		*croppedImage8 = RGBframe(cv::Rect(0, 210, 320, 30)).clone();

		_frames = new std::vector<unsigned char *>;
		_frames->push_back((*croppedImage1).data);
		_frames->push_back((*croppedImage2).data);
		_frames->push_back((*croppedImage3).data);
		_frames->push_back((*croppedImage4).data);
		_frames->push_back((*croppedImage5).data);
		_frames->push_back((*croppedImage6).data);
		_frames->push_back((*croppedImage7).data);
		_frames->push_back((*croppedImage8).data);
		emit sendFrame(_frames);
		msleep(_delay + 20);
	}
}

void    OpenCV::displayFrames(std::vector<unsigned char *> frame)
{
	QImage                  img;
	unsigned char *fin = new unsigned char[600000];

	for (unsigned int x = 0; x < frame.size(); x++)
	{
		if (x == 0)
			strcpy((char *)fin, (char *)(frame[0]));
		else {
			strcat((char *)fin, (char *)(frame[x] + 1));
		}
	}
	img = QImage((const unsigned char *)(fin),
		320, 240, QImage::Format_RGB888);
	emit processedImage(img, 1);
	delete fin;
}

void                    OpenCV::msleep(int ms)
{
#ifdef _WIN32
	Sleep(ms);
#else
	usleep(ms * 1000);
#endif
}
