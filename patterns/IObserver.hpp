#ifndef IOBSERVER_H
#define IOBSERVER_H
#pragma once

class IObserver {
 public:
  virtual void update(float temp) = 0;
};
#endif