#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H
#pragma once
#include <AbstractLight.hpp>
class DirectionalLight : public AbstractLight {
 private:
 public:
  DirectionalLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
  ~DirectionalLight();
};
#endif