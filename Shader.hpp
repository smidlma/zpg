#ifndef SHADER_H
#define SHADER_H
#pragma once
#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>
class Shader {
 private:
 GLuint shaderProgram;
 public:
  Shader();
  ~Shader();
  GLuint getShaderProgram();
};
#endif