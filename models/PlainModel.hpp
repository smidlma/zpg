#ifndef PLAINMODEL_H
#define PLAINMODEL_H
#pragma once
#include "AbstractModel.hpp"
#include "plain.h"
class PlainModel : public AbstractModel {
 private:
 public:
  PlainModel();
  ~PlainModel();
  void draw(Shader *shader, Transform *transform) override;
};
#endif