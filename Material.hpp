#ifndef MATERIAL_H
#define MATERIAL_H
#pragma once
#include <Texture.hpp>
#include <glm/vec3.hpp>  // glm::vec3
class Material {
 private:
  glm::vec3 ambient;
  glm::vec3 diffuse;
  glm::vec3 specular;
  float shininess;
 public:
  Texture *texture;
  Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess, Texture *texture);
  ~Material();
};
#endif