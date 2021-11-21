#ifndef ABSTRACTLIGHT_H
#define ABSTRACTLIGHT_H
#pragma once
#include <glm/vec3.hpp>  // glm::vec3

class AbstractLight {
 private:
 protected:
  glm::vec3 ambient;
  glm::vec3 diffuse;
  glm::vec3 specular;

 public:
  virtual void bind() = 0;
  AbstractLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
  ~AbstractLight();
};
#endif