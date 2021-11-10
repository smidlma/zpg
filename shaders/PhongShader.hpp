#ifndef PHONGSHADER_H
#define PHONGSHADER_H
#pragma once
#include <Camera.hpp>
#include <AbstractShader.hpp>
#include <Light.hpp>
class PhongShader : public AbstractShader {
 private:
 public:
  PhongShader();
  ~PhongShader();
  Light *l = new Light(glm::vec3(0,1,0), glm::vec3(0,1,0));
  void update(Camera *camera) override;
};
#endif