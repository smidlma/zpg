#ifndef SHADER_H
#define SHADER_H
#pragma once
#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include "Camera.hpp"

class Shader {
 private:
  GLuint shaderProgram;

 public:
  void updateCamera(Camera* camera);
  const char* vertex_shader =
      "#version 330\n"
      "layout(location=0) in vec4 vp;"
      "layout(location = 1) in vec4 color;"
      "out vec4 vColor;"
      "uniform mat4 modelMatrix;"
      "uniform mat4 viewMatrix;"
      "uniform mat4 projectionMatrix;"
      "void main () {"
      "     gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * vp;"
      "     vColor = color;"
      "}";

  const char* fragment_shader =
      "#version 330\n"
      "in vec4 vColor;"
      "out vec4 fColor;"
      "void main () {"
      "fColor = vColor;"
      "}";
  Shader();
  ~Shader();
  GLuint getShaderProgram();
};

#endif