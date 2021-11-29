#include "PointLight.hpp"
void PointLight::useLight(int index) {
  glUseProgram(shader->getShaderProgram());
  char temp[256];
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
                       float quadratic, AbstractShader *shader)
    : AbstractLight(ambient, diffuse, specular, shader) {
  this->position = position;
  this->constant = constant;
  this->linear = linear;
  this->quadratic = quadratic;
}

PointLight::~PointLight() {}