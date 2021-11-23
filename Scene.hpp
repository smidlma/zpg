#ifndef SCENE_H
#define SCENE_H
#pragma once

#include <AbstractLight.hpp>
#include <CallbackController.hpp>
#include <DrawableObject.hpp>
#include <vector>

class Scene {
 private:
 public:
  std::vector<DrawableObject *> objects;
  std::vector<AbstractLight *> lights;
  Scene();
  ~Scene();
  void addObject(DrawableObject *o);
  void addLight(AbstractLight *l);
};
#endif