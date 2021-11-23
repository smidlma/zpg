#include "PointLight.hpp"
void PointLight::useLight(int index) {}

PointLight::PointLight() {}

PointLight::PointLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
                       glm::vec3 position, float constant, float linear,
                       float quadratic, AbstractShader *shader)
    : AbstractLight(ambient, diffuse, specular, shader) {
  this->position = position;
  this->constant = constant;
  this->linear = linear;
  this->quadratic = quadratic;
}

PointLight::~PointLight() {}