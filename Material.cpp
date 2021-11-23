#include "Material.hpp"

void Material::useMaterial(AbstractShader *shader) {
  // Use material

  // Use Textures
  for (auto *t : textures) {
    t->useTexture(shader);
  }
}

Material::Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
                   float shininess) {
  this->ambient = ambient;
  this->diffuse = diffuse;
  this->specular = specular;
  this->shininess = shininess;
}
Material::Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
                   float shininess, std::vector<AbstractTexture *> textures) {
  this->ambient = ambient;
  this->diffuse = diffuse;
  this->specular = specular;
  this->shininess = shininess;
  this->textures = textures;
}

Material::Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
                   float shininess, AbstractTexture *texture) {
  this->ambient = ambient;
  this->diffuse = diffuse;
  this->specular = specular;
  this->shininess = shininess;
  this->textures.push_back(texture);
}

void Material::addTexture(AbstractTexture *texture) {
  textures.push_back(texture);
}

Material::~Material() {}