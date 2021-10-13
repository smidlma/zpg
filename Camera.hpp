#ifndef CAMERA_H
#define CAMERA_H
#pragma once

// Include GLM
#include <glm/gtc/matrix_transform.hpp>  // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>  // glm::value_ptr
#include <glm/mat4x4.hpp>        // glm::mat4
#include <glm/vec3.hpp>          // glm::vec3
#include <glm/vec4.hpp>          // glm::vec4

class Camera {
 private:
  glm::vec3 eye = {0, 0, 0};
  glm::vec3 target = {0, 0, 0};
  glm::vec3 up = {0, 0, 1};
  // Projection matrix :
  // 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
  glm::mat4 projection =
      glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);

 public:
  Camera();
  ~Camera();
  glm::mat4 getCamera();
  void look();
};
#endif