#ifndef NORMALTEXTURE_H
#define NORMALTEXTURE_H
#pragma once
#include <AbstractTexture.hpp>
class NormalTexture : public AbstractTexture {
 private:
 public:
  NormalTexture(std::string texturePath);
  ~NormalTexture();
  void useTexture(AbstractShader *shader) override;
};
#endif