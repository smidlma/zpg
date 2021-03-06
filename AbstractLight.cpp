#include "AbstractLight.hpp"
AbstractLight::AbstractLight() {}
AbstractLight::AbstractLight(glm::vec3 ambient, glm::vec3 diffuse,
                             glm::vec3 specular
                          ) {
  this->ambient = ambient;
  this->diffuse = diffuse;
  this->specular = specular;
}

AbstractLight::~AbstractLight() {}