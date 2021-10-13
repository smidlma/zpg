#ifndef MODEL_H
#define MODEL_H
#pragma once
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>  // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>  // glm::value_ptr
#include <glm/mat4x4.hpp>        // glm::mat4
#include <glm/vec3.hpp>          // glm::vec3
#include <glm/vec4.hpp>          // glm::vec4

#include <vector>

#include "Shader.hpp"
struct ModelStruct {
  float pos[4];
  float rgba[4];
};

class Model {
 private:
  std::vector<ModelStruct> model;
  GLuint VAO = 0;
  GLuint getVAO();
  glm::mat4 M = glm::mat4(1.0f);
  Shader *shader;
  float rotationAngel = 0;

 public:
  Model(std::vector<ModelStruct> model, Shader *shader);
  ~Model();
  void transalte(float myView);
  void setForRender();
  void rotate(float angel);
  void scale(float scale);
};
#endif