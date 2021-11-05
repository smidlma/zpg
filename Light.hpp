#ifndef LIGHT_H
#define LIGHT_H
#pragma once
#include <glm/vec3.hpp>  // glm::vec3
class Light {
 private:
  glm::vec3 position;
  glm::vec3 color;

 public:
  Light(glm::vec3 pos, glm::vec3 col);
  ~Light();
};
#endif