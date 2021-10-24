#ifndef TRANSFORM_H
#define TRANSFORM_H
#pragma once
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>  // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/mat4x4.hpp>  // glm::mat4

class Transform {
 private:
  glm::mat4 modelMatrix = glm::mat4(1.0f);
 public:
  float lastAngle = 0;
  void translate(glm::vec3 delta);
  void scale(float scale);
  void rotate(float angel);
  glm::mat4 getModelMatrix();
  void reset();
  Transform();
  ~Transform();
};
#endif