#ifndef PHONGSHADER_H
#define PHONGSHADER_H
#pragma once
#include <Camera.hpp>
#include <AbstractShader.hpp>
class PhongShader : public AbstractShader {
 private:
 public:
  PhongShader();
  ~PhongShader();
  void update(Camera *camera) override;
};
#endif