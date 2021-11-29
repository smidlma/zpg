#ifndef PHONGSHADER_H
#define PHONGSHADER_H
#pragma once
#include <Camera.hpp>
#include <AbstractShader.hpp>
#include <AbstractLight.hpp>
#include <vector>
class PhongShader : public AbstractShader {
 private:
 public:
  // PhongShader(std::vector<AbstractLight*> lights);
  PhongShader();
  ~PhongShader();
  void update(Camera *camera) override;
};
#endif