#ifndef LAMBERTSHADER_H
#define LAMBERTSHADER_H
#pragma once
#include <Camera.hpp>
#include <AbstractShader.hpp>
class LambertShader : public AbstractShader {
 private:
 public:
  void update(Camera *camera) override;
  LambertShader();
  ~LambertShader();
};
#endif