#ifndef ABSTRACTTEXTURE_H
#define ABSTRACTTEXTURE_H
#pragma once
#include <GL/glew.h>
#include <AbstractShader.hpp>
class AbstractTexture {
 private:
 protected:
  GLuint textureID;
 public:
  void virtual useTexture(AbstractShader *shader) = 0;
  AbstractTexture();
  ~AbstractTexture();
};
#endif