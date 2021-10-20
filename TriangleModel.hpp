#ifndef TRIANGLEMODEL_H
#define TRIANGLEMODEL_H
#pragma once
#include <ModelStruct.h>

#include <vector>

#include "AbstractModel.hpp"
class TriangleModel : public AbstractModel {
 private:
  std::vector<ModelStruct> data;

 public:
  TriangleModel(std::vector<ModelStruct> data);
  ~TriangleModel();
  void draw(Shader *shader, Transform *transform) override;
};
#endif