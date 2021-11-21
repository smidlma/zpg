#ifndef TEXTURE_H
#define TEXTURE_H
#pragma once

#include <GL/glew.h>
#include <SOIL/SOIL.h>

#include <AbstractShader.hpp>
#include <AbstractTexture.hpp>
class Texture : public AbstractTexture{
 private:
 public:
  Texture(const char *texturePath);
  ~Texture();
  void useTexture(AbstractShader *shader) override;
};
#endif