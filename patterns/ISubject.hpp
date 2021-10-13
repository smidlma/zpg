#ifndef ISUBJECT_H
#define ISUBJECT_H
#pragma once

#include "IObserver.hpp"
class ISubject {
 private:
 public:
  virtual void registerObserver(IObserver *ob) = 0;
  virtual void removeObserver(IObserver *ob) = 0;
  virtual void notify() = 0;
};
#endif