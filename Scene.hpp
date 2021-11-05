#ifndef SCENE_H
#define SCENE_H
#pragma once

#include <vector>

#include <CallbackController.hpp>
#include <DrawableObject.hpp>

class Scene {
 private:
 public:
  std::vector<DrawableObject *> objects;
  Scene();
  ~Scene();
  void addObject(DrawableObject *o);
};
#endif