#ifndef ABSTRACTSHADER_H
#define ABSTRACTSHADER_H
#pragma once
#include <ShaderLoader.h>

#include <glm/glm.hpp>
// #include <AbstractLight.hpp>
#include <IObserver.hpp>
class AbstractShader : public ShaderLoader, public IObserver {
 private:
 public:
  void use();
  void setInt(const char *name, int value);
  void setMat4(const char *name, glm::mat4 mat);
  void setVec3(const char *name, glm::vec3 value);
  void setFloat(const char *name, float value);
  AbstractShader();
  ~AbstractShader();
};
#endif