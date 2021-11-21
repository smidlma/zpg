#ifndef CUBEMAPSHADER_H
#define CUBEMAPSHADER_H
#pragma once
#include <AbstractShader.hpp>
#include <Camera.hpp>
class CubeMapShader : public AbstractShader {
 private:
 public:
  void update(Camera *camera) override;
  CubeMapShader();
  ~CubeMapShader();
};
#endif