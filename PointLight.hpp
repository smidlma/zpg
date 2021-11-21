#ifndef POINTLIGHT_H
#define POINTLIGHT_H
#pragma once
#include <AbstractLight.hpp>
class PointLight : public AbstractLight {
 private:
 public:
  PointLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
  ~PointLight();
};
#endif