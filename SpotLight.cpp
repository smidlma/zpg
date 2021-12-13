#include "SpotLight.hpp"

void SpotLight::useLight(int index, AbstractShader *shader) {
  char temp[256];
  
  sprintf(temp, "lights[%d].isOn", index);
  shader->setInt(temp, isOn);

  sprintf(temp, "lights[%d].type", index);
  shader->setInt(temp, type);

  sprintf(temp, "lights[%d].ambient", index);
  shader->setVec3(temp, ambient);

  sprintf(temp, "lights[%d].diffuse", index);
  shader->setVec3(temp, diffuse);

  sprintf(temp, "lights[%d].specular", index);
  shader->setVec3(temp, specular);

  sprintf(temp, "lights[%d].position", index);
  shader->setVec3(temp, position);

  sprintf(temp, "lights[%d].direction", index);
  shader->setVec3(temp, direction);

  sprintf(temp, "lights[%d].cutOff", index);
  shader->setFloat(temp, cutOff);

  sprintf(temp, "lights[%d].outerCutOff", index);
  shader->setFloat(temp, outerCutOff);
}
void SpotLight::update(Camera *camera) {
  position = camera->eye;
  direction = camera->target;
}

SpotLight::SpotLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
                     glm::vec3 position, glm::vec3 direction)
    : AbstractLight(ambient, diffuse, specular) {
  type = 2;
}

SpotLight::SpotLight() {}

SpotLight::~SpotLight() {}