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
  // Camera *camera;

 public:
  std::vector<DrawableObject *> objects;
  Scene();
  ~Scene();
  void updateCamera();
  void addObject(DrawableObject *o);
  
  
};
#endif