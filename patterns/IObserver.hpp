#ifndef IOBSERVER_H
#define IOBSERVER_H
#pragma once

class Camera;
class IObserver {
 public:
  virtual void update(Camera *camera) = 0;
};
#endif