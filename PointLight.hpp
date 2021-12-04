#ifndef POINTLIGHT_H
#define POINTLIGHT_H
#pragma once
#include <AbstractLight.hpp>

class PointLight : public AbstractLight {
 private:
  glm::vec3 position;
  float constant;
  float linear;
  float quadratic;

 public:
  PointLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
             glm::vec3 position, float constant, float linear, float quadratic);
  PointLight();
  ~PointLight();
  void useLight(int index, AbstractShader *shader) override;
  void update(Camera *camera) override;
};
#endif