#include "DirectionalLight.hpp"
void DirectionalLight::update(Camera *camera) {}
void DirectionalLight::useLight(int index, AbstractShader *shader) {
  char temp[256];
  sprintf(temp, "lights[%d].isOn", index);
  shader->setInt(temp, isOn);

  sprintf(temp, "lights[%d].type", index);
  shader->setInt(temp, type);

  sprintf(temp, "lights[%d].ambient", index);
  shader->setVec3(temp, ambient); shader->setVec3(temp, ambient);

  sprintf(temp, "lights[%d].diffuse", index);
  shader->setVec3(temp, diffuse);

  sprintf(temp, "lights[%d].specular", index);
  shader->setVec3(temp, specular);

  sprintf(temp, "lights[%d].direction", index);
  shader->setVec3(temp, direction);
}

DirectionalLight::DirectionalLight(glm::vec3 ambient, glm::vec3 diffuse,
                                   glm::vec3 specular)
    : AbstractLight(ambient, diffuse, specular) {
  type = 3;
}

DirectionalLight::~DirectionalLight() {}
