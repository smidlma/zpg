#include "PointLight.hpp"
void PointLight::update(Camera *camera) {}
void PointLight::useLight(int index, AbstractShader *shader) {
  glUseProgram(shader->getShaderProgram());

  char temp[256];
  sprintf(temp, "lights[%d].isOn", index);
  glUniform1i(glGetUniformLocation(shader->getShaderProgram(), temp), isOn);

  sprintf(temp, "lights[%d].type", index);
  glUniform1i(glGetUniformLocation(shader->getShaderProgram(), temp), 1);

  sprintf(temp, "lights[%d].ambient", index);
  glUniform3fv(glGetUniformLocation(shader->getShaderProgram(), temp), 1,
               &ambient[0]);

  sprintf(temp, "lights[%d].diffuse", index);
  glUniform3fv(glGetUniformLocation(shader->getShaderProgram(), temp), 1,
               &diffuse[0]);

  sprintf(temp, "lights[%d].specular", index);
  glUniform3fv(glGetUniformLocation(shader->getShaderProgram(), temp), 1,
               &specular[0]);

  sprintf(temp, "lights[%d].position", index);
  glUniform3fv(glGetUniformLocation(shader->getShaderProgram(), temp), 1,
               &position[0]);

  sprintf(temp, "lights[%d].constant", index);
  glUniform1f(glGetUniformLocation(shader->getShaderProgram(), temp), constant);

  sprintf(temp, "lights[%d].linear", index);
  glUniform1f(glGetUniformLocation(shader->getShaderProgram(), temp), linear);

  sprintf(temp, "lights[%d].quadratic", index);
  glUniform1f(glGetUniformLocation(shader->getShaderProgram(), temp),
              quadratic);

  glUseProgram(0);
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
}

PointLight::~PointLight() {}