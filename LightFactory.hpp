#ifndef LIGHTFACTORY_H
#define LIGHTFACTORY_H
#pragma once
#include <DirectionalLight.hpp>
#include <PointLight.hpp>
#include <SpotLight.hpp>
class LightFactory {
 private:
 public:
  static PointLight *makePointLight(glm::vec3 ambient, glm::vec3 diffuse,
                                    glm::vec3 specular, glm::vec3 position,
                                    float constant, float linear,
                                    float quadratic, AbstractShader *shader) {
    return new PointLight(ambient, diffuse, specular, position, constant,
                          linear, quadratic, shader);
  }
  static SpotLight *makeSpotLight() { return new SpotLight(); }
  static DirectionalLight *makeDirectionalLight() { return nullptr; }
  LightFactory();
  ~LightFactory();
};
#endif