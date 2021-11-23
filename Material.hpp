#ifndef MATERIAL_H
#define MATERIAL_H
#pragma once
#include <AbstractTexture.hpp>
#include <glm/vec3.hpp>  // glm::vec3
class Material {
 private:
  glm::vec3 ambient;
  glm::vec3 diffuse;
  glm::vec3 specular;
  float shininess;

 public:
  std::vector<AbstractTexture *> textures;
  Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
           float shininess, std::vector<AbstractTexture *> textures);
  Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
           float shininess);
  Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
           float shininess, AbstractTexture *texture);
  ~Material();

  void useMaterial(AbstractShader *shader);

  void addTexture(AbstractTexture *texture);
};
#endif