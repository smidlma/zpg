#ifndef MODEL_H
#define MODEL_H
#pragma once
#include <GL/glew.h>


class Model {
 private:
  GLuint VAO = 0;
 public:
  Model();
  ~Model();
  GLuint getVAO();
  
};
#endif