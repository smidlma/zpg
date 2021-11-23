#ifndef PHONGSHADER_H
#define PHONGSHADER_H
#pragma once
#include <Camera.hpp>
#include <AbstractShader.hpp>
#include <Light.hpp>
#include <AbstractLight.hpp>
#include <vector>
class PhongShader : public AbstractShader {
 private:
 public:
  // PhongShader(std::vector<AbstractLight*> lights);
  PhongShader();
  ~PhongShader();
  Light *l = new Light(glm::vec3(0,20.0,0), glm::vec3(0,1,0));
  void update(Camera *camera) override;
};
#endif