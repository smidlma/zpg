#ifndef LAMBERTSHADER_H
#define LAMBERTSHADER_H
#pragma once
#include <AbstractShader.hpp>
#include <Camera.hpp>
class LambertShader : public AbstractShader {
 private:
 public:
  LambertShader();
  ~LambertShader();
  void update(Camera *camera) override;
};
#endif