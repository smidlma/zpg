#ifndef ABSTRACTSHADER_H
#define ABSTRACTSHADER_H
#pragma once
#include <ShaderLoader.h>

// #include <AbstractLight.hpp>
#include <IObserver.hpp>
#include <vector>
class AbstractShader : public ShaderLoader, public IObserver {
 private:
 protected:
  // std::vector<AbstractLight*> lights;

 public:
  // AbstractShader(std::vector<AbstractLight*> lights);
  AbstractShader();
  ~AbstractShader();
  GLuint getShaderProgram() { return shaderProgramID; };
};
#endif