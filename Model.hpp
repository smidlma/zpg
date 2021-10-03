#ifndef MODEL_H
#define MODEL_H
#pragma once
#include <GL/glew.h>
#include <glm/vec4.hpp> 
#include <vector>
struct ModelStruct {
  float pos[4];
  float rgba[4];
};

class Model {
 private:
  std::vector<ModelStruct> model;
  GLuint VAO = 0;
 public:
  Model(std::vector<ModelStruct> model);
  ~Model();
  GLuint getVAO();
  
};
#endif