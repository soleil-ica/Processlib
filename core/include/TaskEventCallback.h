#include "Data.h"
#include <pthread.h>

#ifndef __TASKEVENTCALLBACK_H
#define __TASKEVENTCALLBACK_H

class TaskEventCallback
{
 public:
  TaskEventCallback();
  virtual ~TaskEventCallback();
  virtual void started(Data &) {}
  virtual void finished(Data &) {}
  virtual void error(Data &,const char*) {}
  
  void ref();
  void unref();

 private:
  pthread_mutex_t _lock;
  int		  _refCounter;
};
#endif