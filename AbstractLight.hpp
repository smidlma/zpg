#ifndef ABSTRACTLIGHT_H
#define ABSTRACTLIGHT_H
#pragma once
#include <AbstractShader.hpp>
#include <glm/vec3.hpp>  // glm::vec3
class AbstractLight {
 private:
 protected:
  glm::vec3 ambient;
  glm::vec3 diffuse;
  glm::vec3 specular;
  AbstractShader *shader;

 public:
  virtual void useLight(int index) = 0;
  AbstractLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
                AbstractShader *shader);
  ~AbstractLight();
  AbstractLight();
};
#endif