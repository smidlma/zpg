#ifndef ISUBJECT_H
#define ISUBJECT_H
#pragma once
#include <list>
#include <vector>

class IObserver;
class Camera;
class ISubject {
 private:
 protected:
  std::list<IObserver *> observers;

 public:
  void registerObserver(IObserver *ob);
  void removeObserver(IObserver *ob);
  void notify(Camera *camera);
};
#endif