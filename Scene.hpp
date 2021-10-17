#ifndef SCENE_H
#define SCENE_H
#pragma once

#include <vector>

// #include "Object.hpp"
#include "Shader.hpp"
#include "CallbackController.hpp"
class Camera;
class Scene {
 private:
  // std::vector<Object> objects;
  Camera *camera;

 public:
  Scene();
  ~Scene();
  void render();
  void updateCamera();
};
#endif