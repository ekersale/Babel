#ifndef	__OPENCV_H__
#define __OPENCV_H__

#include		<iostream>

#include		<QMutex>
#include		<QThread>
#include		<QImage>
#include		<QWaitCondition>

#include		"IModule.h"

#include		<opencv2/core/core.hpp>
#include		<opencv2/imgproc/imgproc.hpp>
#include		<opencv2/highgui/highgui.hpp>



class OpenCV : public QThread
{
  Q_OBJECT
private:
  cv::VideoCapture		_videoPerso;
  cv::VideoCapture		_videoOther;
  cv::Mat			_frame;
  cv::Mat			_RGBframe;
  QImage			_img;
  QMutex			_mutex;
  QWaitCondition		_condition;
  int				_frameRate;
  bool				_stop;

signals:
  void			processedImage(const QImage &image);

public:
  OpenCV(QObject *parent = 0); 
  ~OpenCV();
  void			play();
  void			stop();
  bool			isStopped() const;
  void			msleep(int ms);
  void			run();
  int			getFrameSize(cv::Mat frame);
};

#endif
