#include "SpotLight.hpp"

void SpotLight::useLight(int index, AbstractShader *shader) {
  glUseProgram(shader->getShaderProgram());

  char temp[256];
  sprintf(temp, "lights[%d].isOn", index);
  glUniform1i(glGetUniformLocation(shader->getShaderProgram(), temp), isOn);

  sprintf(temp, "lights[%d].type", index);
  glUniform1i(glGetUniformLocation(shader->getShaderProgram(), temp), 2);

  sprintf(temp, "lights[%d].ambient", index);
  glUniform3fv(glGetUniformLocation(shader->getShaderProgram(), temp), 1,
               &ambient[0]);

  // std::cout << temp << std::endl;
  sprintf(temp, "lights[%d].diffuse", index);
  glUniform3fv(glGetUniformLocation(shader->getShaderProgram(), temp), 1,
               &diffuse[0]);

  sprintf(temp, "lights[%d].specular", index);
  glUniform3fv(glGetUniformLocation(shader->getShaderProgram(), temp), 1,
               &specular[0]);

  sprintf(temp, "lights[%d].position", index);
  glUniform3fv(glGetUniformLocation(shader->getShaderProgram(), temp), 1,
               &position[0]);

  sprintf(temp, "lights[%d].direction", index);
  glUniform3fv(glGetUniformLocation(shader->getShaderProgram(), temp), 1,
               &direction[0]);

  sprintf(temp, "lights[%d].cutOff", index);
  glUniform1f(glGetUniformLocation(shader->getShaderProgram(), temp), cutOff);

  sprintf(temp, "lights[%d].outerCutOff", index);
  glUniform1f(glGetUniformLocation(shader->getShaderProgram(), temp),
              outerCutOff);
  glUseProgram(0);
}
void SpotLight::update(Camera *camera) {
  position = camera->eye;
  direction = camera->target;
}

SpotLight::SpotLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
                     glm::vec3 position, glm::vec3 direction)
    : AbstractLight(ambient, diffuse, specular) {}

SpotLight::SpotLight() {}

SpotLight::~SpotLight() {}