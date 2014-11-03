#include		"../../Includes/OpenCV.h"

OpenCV::OpenCV(QObject *parent) : QThread(parent)
{
  _stop = true;
}

OpenCV::~OpenCV()
{  
}

void			OpenCV::play()
{
  if (!isRunning())
    {
      if (isStopped())
	_stop = false;
      start(LowPriority);
    }
}

void			OpenCV::stop()
{
  _stop = true;
}

int			OpenCV::getFrameSize(cv::Mat frame)
{
  int			i;

  i = 0;
  unsigned char *test = (unsigned char*)(frame.data);
  while (test[i])
    i++;
  return i;
}

bool			OpenCV::isStopped() const
{
  return this->_stop;
}

void			OpenCV::run()
{
  cv::VideoCapture	capture(0);
  cv::Mat		frame;
  cv::Mat		RGBframe;
  QImage		img;

  std::cout << "On passe dans OpenCV::run " << std::endl;
  if (!capture.isOpened())
    {
      std::cerr << "Can't Open caméra" << std::endl;
      return;
    }
  for (int i = 0; i < 20; i++)
    {
      int64	start;
      
      start = cv::getTickCount();
      capture >> frame;
      _frameRate = cv::getTickFrequency() / (cv::getTickCount() - start);
    }

  int	delay = (1000 / _frameRate);
  
  while (1)
    {
      if (!capture.read(frame))
	{
	  std::cerr << "Open CV can't read " << std::endl;
	  return ;
	}
      if (frame.channels() == 3)
	{
	  cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
	  img = QImage((const unsigned char *)(RGBframe.data),
		       RGBframe.cols, RGBframe.rows, QImage::Format_RGB888);
	}
      else
	{
	  img = QImage((const unsigned char *)(frame.data),
		       frame.cols, frame.rows, QImage::Format_Indexed8);
	}
      int	i;

      for (i = 0; frame.data[i]; i++);
      //i = getFrameSize(frame);
      std::cout << " I => " << i << std::endl;
      emit processedImage(img);
      msleep(delay);
    }
}

void			OpenCV::msleep(int ms)
{
#if defined _WIN32
  Sleep(ms);
#else
  usleep(ms + 1);
#endif
}


