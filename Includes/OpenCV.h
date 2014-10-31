#ifndef	__OPENCV_H__
#define __OPENCV_H__

#include		"IModule.h"

class OpenCV : public IModule
{
  cv::VideoCapture	_video;
  cv::Mat		_frame;
  cv::Mat		_RGBframe;
  /* QImage		_img; */

public:
  IModule * createObject(void);
   VideoCapture getCaptureVideo(void);
   void runVideo(void);
   void playVideo(void);
   bool isStopped(void);
   void print_error(void);
   VideoCapture get_video(void) const;
   Math get_frame(void) const;
   Math get_RGBFrame(void) const;
   QueueImage get_img(void) const;
   void set_video(VideoCapture new_video);
   void set_frame(Math new_frame);
   void set_RGBFrame(Math new_RGBFrame);
   void set_img(QueueImage new_img);
   OpenCV();
   OpenCV(const OpenCV& oldOpenCV);
   ~OpenCV();

protected:
private:
   VideoCapture _video;
   Math _frame;
   Math _RGBFrame;
   QueueImage _img;


};

#endif
