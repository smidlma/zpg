#ifndef CONSTANTSHADER_H
#define CONSTANTSHADER_H
#pragma once
#include <Camera.hpp>
#include <AbstractShader.hpp>
class ConstantShader : public AbstractShader {
 private:
 public:
  void update(Camera *camera) override;
  ConstantShader();
  ~ConstantShader();
};
#endif