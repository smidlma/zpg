#ifndef ABSTRACTLIGHT_H
#define ABSTRACTLIGHT_H
#pragma once
#include <AbstractShader.hpp>
#include <glm/vec3.hpp>  // glm::vec3
class AbstractLight : public IObserver{
 private:
 protected:
  glm::vec3 ambient;
  glm::vec3 diffuse;
  glm::vec3 specular;


 public:
  int isOn = 1;
  virtual void useLight(int index, AbstractShader *shader) = 0;
  AbstractLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
  ~AbstractLight();
  AbstractLight();
};
#endif