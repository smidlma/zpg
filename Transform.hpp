#ifndef TRANSFORM_H
#define TRANSFORM_H
#pragma once
#include <GLFW/glfw3.h>

#include <glm/gtc/matrix_transform.hpp>  // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/mat4x4.hpp>  // glm::mat4

class Transform {
 private:
  glm::mat4 modelMatrix = glm::mat4(1.0f);
  glm::mat4 prevMatrix = glm::mat4(1.0f);
  glm::vec3 position = {0,0,0};
  glm::vec3 rotation = {0,0,0};
  float scaleVal = 1.0f;

 public:
 
  void translate(glm::vec3 delta);
  void scale(float scaleVal);
  void rotate(glm::vec3 angel);
  glm::mat4 getModelMatrix();
  void reset();
  Transform();
  ~Transform();
};
#endif