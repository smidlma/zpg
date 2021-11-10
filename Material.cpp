#include "Material.hpp"

Material::Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
                   float shininess, Texture *texture) {
  this->ambient = ambient;
  this->diffuse = diffuse;
  this->specular = specular;
  this->shininess = shininess;
  this->texture = texture;
}

Material::~Material() {}