#ifndef ABSTRACTSHADER_H
#define ABSTRACTSHADER_H
#pragma once
#include <IObserver.hpp>
#include <ShaderLoader.h>
class AbstractShader : public ShaderLoader, public IObserver {
 private:
 public:
  AbstractShader();
  ~AbstractShader();
  GLuint getShaderProgram() { return shaderProgramID; };
};
#endif