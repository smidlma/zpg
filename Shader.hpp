#ifndef SHADER_H
#define SHADER_H
#pragma once
#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>

#include "ShaderLoader.h"
class Camera;
class Shader : public ShaderLoader {
 private:
  GLuint shaderProgram;

 public:
  void updateCamera(Camera* camera);
  const char* vertex_shader =
      "#version 330\n"
      "layout(location=0) in vec3 vp;"
      "layout(location = 1) in vec3 color;"
      "out vec3 vColor;"
      "uniform mat4 modelMatrix;"
      "uniform mat4 viewMatrix;"
      "uniform mat4 projectionMatrix;"
      "void main () {"
      "     gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * "
      "vec4(vp,1.0f);"
      "     vColor = color;"
      "}";

  const char* fragment_shader =
      "#version 330\n"
      "in vec3 vColor;"
      "out vec4 fColor;"
      "void main () {"
      "fColor = vec4(vColor, 1);"
      "}";
  Shader();
  ~Shader();
  GLuint getShaderProgram();
};

#endif