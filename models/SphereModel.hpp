#ifndef SPHEREMODEL_H
#define SPHEREMODEL_H
#pragma once
#include "AbstractModel.hpp"
#include "sphere.h"
class SphereModel : public AbstractModel {
 private:
 public:
  void draw(Shader *shader, Transform *transform) override;
  SphereModel();
  ~SphereModel();
};
#endif