#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H
#pragma once
#include <AbstractLight.hpp>
class SpotLight : public AbstractLight {
 private:
 public:
  SpotLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
            AbstractShader *shader);
  SpotLight();
  ~SpotLight();
  void useLight(int index);
};
#endif