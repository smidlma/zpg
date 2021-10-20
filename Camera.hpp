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
  Scene *scene = nullptr;
  glm::vec2 oldMousePos = {400, 300};
  float theta = 8.55 ;
  float phi = -2.39;
  float radius = 1;
  const float MOVEMENT_SPEED = 0.5f;

 public:
  glm::mat4 viewMatrix;
  Shader *shader = nullptr;
  glm::mat4 projectionMatrix;
  Camera(Scene *scene);
  ~Camera();
  glm::mat4 getCamera();
  void adjustTarget(glm::vec2 newMousePos);
  void toFront();
  void toLeft();
  void toRight();
  void toBack();
};
#endif