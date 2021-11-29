#ifndef PHONGSHADER_H
#define PHONGSHADER_H
#pragma once
#include <AbstractShader.hpp>
#include <Camera.hpp>
class PhongShader : public AbstractShader {
 private:
 public:
  PhongShader();
  ~PhongShader();
  void update(Camera *camera) override;
};
#endif