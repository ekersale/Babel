#include		"../../Includes/OpenCV.h"
//#include "IModule.h"

IModule			*OpenCV::createObject(void)
{
   // TODO : implement
}

OpenCV::OpenCV()
{
}

OpenCV::OpenCV(const OpenCV& oldOpenCV)
{
   _video = oldOpenCV._video;
   _frame = oldOpenCV._frame;
   _RGBFrame = oldOpenCV._RGBFrame;
   _img = oldOpenCV._img;
}

OpenCV::~OpenCV()
{
   // TODO : implement
}

VideoCapture		OpenCV::getCaptureVideo(void)
{
  return this->_vidéo;
}

void			OpenCV::runVideo(void)
{
   // TODO : implement
}

void			OpenCV::playVideo(void)
{
   // TODO : implement
}

bool			OpenCV::isStopped(void)
{
  return (false);
   // TODO : implement
}

void			OpenCV::print_error(void)
{
   // TODO : implement
}

VideoCapture		OpenCV::get_video(void) const
{
   return _video;
}

Mat			OpenCV::get_frame(void) const
{
   return _frame;
}

Mat			OpenCV::get_RGBFrame(void) const
{
   return _RGBFrame;
}

QImage			OpenCV::get_img(void) const
{
   return _img;
}

void			OpenCV::set_video(VideoCapture new_video)
{
   _video = new_video;
}

void			OpenCV::set_frame(cv::Mat new_frame)
{
   _frame = new_frame;
}

void			OpenCV::set_RGBFrame(cv::Mat new_RGBFrame)
{
   _RGBFrame = new_RGBFrame;
}

void			OpenCV::set_img(QImage new_img)
{
   _img = new_img;
}
