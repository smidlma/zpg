#ifndef SCENE_H
#define SCENE_H
#pragma once

#include <vector>

#include "CallbackController.hpp"
#include "DrawableObject.hpp"
#include "Shader.hpp"
class Camera;
class Scene {
 private:
  std::vector<DrawableObject *> objects;
  Camera *camera;

 public:
  Scene();
  ~Scene();
  void render();
  void updateCamera();
  void addObject(DrawableObject *o);
};
#endif