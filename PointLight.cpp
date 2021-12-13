#include "PointLight.hpp"
void PointLight::update(Camera *camera) {}
void PointLight::useLight(int index, AbstractShader *shader) {
  char temp[256];

  sprintf(temp, "lights[%d].isOn", index);
  shader->setInt(temp, isOn);

  sprintf(temp, "lights[%d].type", index);
  shader->setInt(temp, type);

  sprintf(temp, "lights[%d].ambient", index);
  shader->setVec3(temp, ambient);
  shader->setVec3(temp, ambient);

  sprintf(temp, "lights[%d].diffuse", index);
  shader->setVec3(temp, diffuse);

  sprintf(temp, "lights[%d].specular", index);
  shader->setVec3(temp, specular);

  sprintf(temp, "lights[%d].position", index);
  shader->setVec3(temp, position);

  sprintf(temp, "lights[%d].constant", index);
  shader->setFloat(temp, constant);

  sprintf(temp, "lights[%d].linear", index);
  shader->setFloat(temp, linear);

  sprintf(temp, "lights[%d].quadratic", index);
  shader->setFloat(temp, quadratic);
}

PointLight::PointLight() {}

PointLight::PointLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
                       glm::vec3 position, float constant, float linear,
                       float quadratic)
    : AbstractLight(ambient, diffuse, specular) {
  this->position = position;
  this->constant = constant;
  this->linear = linear;
  this->quadratic = quadratic;
  type = 1;
}

PointLight::~PointLight() {}