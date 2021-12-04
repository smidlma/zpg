#include "DirectionalLight.hpp"
void DirectionalLight::update(Camera *camera) {}
void DirectionalLight::useLight(int index, AbstractShader *shader) {
  glUseProgram(shader->getShaderProgram());

  char temp[256];
  sprintf(temp, "lights[%d].isOn", index);
  glUniform1i(glGetUniformLocation(shader->getShaderProgram(), temp), isOn);

  sprintf(temp, "lights[%d].type", index);
  glUniform1i(glGetUniformLocation(shader->getShaderProgram(), temp), 3);

  sprintf(temp, "lights[%d].ambient", index);
  glUniform3fv(glGetUniformLocation(shader->getShaderProgram(), temp), 1,
               &ambient[0]);

  sprintf(temp, "lights[%d].diffuse", index);
  glUniform3fv(glGetUniformLocation(shader->getShaderProgram(), temp), 1,
               &diffuse[0]);

  sprintf(temp, "lights[%d].specular", index);
  glUniform3fv(glGetUniformLocation(shader->getShaderProgram(), temp), 1,
               &specular[0]);

  sprintf(temp, "lights[%d].direction", index);
  glUniform3fv(glGetUniformLocation(shader->getShaderProgram(), temp), 1,
               &direction[0]);

  glUseProgram(0);
}

DirectionalLight::DirectionalLight(glm::vec3 ambient, glm::vec3 diffuse,
                                   glm::vec3 specular)
    : AbstractLight(ambient, diffuse, specular) {}

DirectionalLight::~DirectionalLight() {}
