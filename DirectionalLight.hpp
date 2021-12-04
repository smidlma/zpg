#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H
#pragma once
#include <AbstractLight.hpp>
class DirectionalLight : public AbstractLight {
 private:
  glm::vec3 direction = {-0.2f, -1.0f, -0.3f};
 public:
  DirectionalLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
  ~DirectionalLight();
  void useLight(int index, AbstractShader *shader);
  void update(Camera *camera) override;
};
#endif