#ifndef TEXTURE_H
#define TEXTURE_H
#pragma once

#include <GL/glew.h>
#include <SOIL/SOIL.h>

#include <AbstractShader.hpp>
class Texture {
 private:
  GLuint textureID;

 public:
  Texture(const char *texturePath);
  ~Texture();
  void useTexture(AbstractShader *shader);
};
#endif