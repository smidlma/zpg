#include "Material.hpp"

void Material::useMaterial(AbstractShader *shader) {
  // Use material
  glUseProgram(shader->getShaderProgram());
  glUniform3fv(
      glGetUniformLocation(shader->getShaderProgram(), "material.ambient"), 1,
      &ambient[0]);
  glUniform3fv(
      glGetUniformLocation(shader->getShaderProgram(), "material.diffuse"), 1,
      &diffuse[0]);
  glUniform3fv(
      glGetUniformLocation(shader->getShaderProgram(), "material.specular"), 1,
      &specular[0]);
  glUniform1f(
      glGetUniformLocation(shader->getShaderProgram(), "material.shininess"),
      shininess);
  glUseProgram(0);
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