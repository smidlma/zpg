#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H
#pragma once
#include <AbstractLight.hpp>
#include <Camera.hpp>
#include <glm/gtc/type_ptr.hpp>  // glm::value_ptr
class SpotLight : public AbstractLight {
 private:
  glm::vec3 position;
  glm::vec3 direction;
  float cutOff = glm::cos(glm::radians(12.5f));
  float outerCutOff = glm::cos(glm::radians(15.0f));

 public:
  SpotLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
            glm::vec3 position, glm::vec3 direction);
  SpotLight();
  ~SpotLight();
  void useLight(int index, AbstractShader *shader);
  void update(Camera *camera) override;
};
#endif