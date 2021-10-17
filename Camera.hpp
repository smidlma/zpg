#ifndef CAMERA_H
#define CAMERA_H
#pragma once

// Include GLM
#include <stdio.h>

#include <glm/gtc/matrix_transform.hpp>  // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/mat4x4.hpp>  // glm::mat4
#include <glm/vec3.hpp>    // glm::vec3

#include "Shader.hpp"

class Scene;
class Camera {
 private:
  glm::vec3 eye = {10, 10, 10};
  glm::vec3 target = {0, 0, 0};
  glm::vec3 up = {0, 1, 0};
  glm::mat4 viewMatrix;
  Scene *scene = nullptr;
  float lastX = 400, lastY = 300;

 public:
  Shader *shader = nullptr;
  glm::mat4 projectionMatrix;
  Camera(Scene *scene);
  ~Camera();
  glm::mat4 getCamera();
  void adjustTarget(double mouseXPos, double mouseYPos);
};
#endif