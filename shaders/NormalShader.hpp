#ifndef NORMALSHADER_H
#define NORMALSHADER_H
#pragma once
#include <AbstractShader.hpp>
#include <Camera.hpp>

class NormalShader : public AbstractShader {
 private:
 public:
  NormalShader();
  ~NormalShader();
  void update(Camera *camera) override;
};
#endif