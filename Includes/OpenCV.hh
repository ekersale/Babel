#ifndef __OPENCV_H__
#define __OPENCV_H__

#include                <iostream>

#include                <QtCore/QMutex>
#include                <QtCore/QThread>
#include                <QtGui/QImage>
#include                <QtCore/QWaitCondition>
#include                <vector>
#ifdef _WIN32
#include        <Windows.h>
#endif
#include                "IModule.hh"

#include                "opencv2/core/core.hpp"

#include                <opencv2/core/core.hpp>
#include                <opencv2/imgproc/imgproc.hpp>
#include                <opencv2/highgui/highgui.hpp>



class OpenCV : public QThread
{
  Q_OBJECT

private:
  cv::VideoCapture              _videoPerso;
  cv::VideoCapture              _videoOther;
  cv::Mat                               _frame;
  cv::Mat                               _RGBframe;
  QImage                                _img;
  QMutex                                _mutex;
  QWaitCondition                _condition;
  std::vector<unsigned char*> *_frames;
  int                                   _frameRate;
  bool                                  _stop;
  int                                   _delay;

signals:
  void                  processedImage(const QImage &image, int value);
  void                  sendFrame(std::vector<unsigned char *> *);

public:
  OpenCV(QObject *parent = 0);
  ~OpenCV();

  void                  play();
  void                  stop();
  bool                  isStopped() const;
  void                  msleep(int ms);
  void                  run();
  int                   getFrameSize(cv::Mat frame);
  void                  displayFrames(std::vector<unsigned char *>);
  std::vector<unsigned char *> getVecFrames() const;};

#endif
