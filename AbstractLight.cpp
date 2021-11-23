#include "AbstractLight.hpp"
AbstractLight::AbstractLight() {}
AbstractLight::AbstractLight(glm::vec3 ambient, glm::vec3 diffuse,
                             glm::vec3 specular, AbstractShader *shader) {
  this->ambient = ambient;
  this->diffuse = diffuse;
  this->specular = specular;
  this->shader = shader;
}

AbstractLight::~AbstractLight() {}