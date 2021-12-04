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
                                    float quadratic) {
    return new PointLight(ambient, diffuse, specular, position, constant,
                          linear, quadratic);
  }
  static SpotLight *makeSpotLight(glm::vec3 ambient, glm::vec3 diffuse,
                                  glm::vec3 specular, glm::vec3 position,
                                  glm::vec3 direction) {
    return new SpotLight(ambient, diffuse, specular, position, direction);
  }
  static DirectionalLight *makeDirectionalLight(glm::vec3 ambient, glm::vec3 diffuse,
                                  glm::vec3 specular) { return new DirectionalLight(ambient, diffuse, specular); }
  LightFactory();
  ~LightFactory();
};
#endif