#ifndef SUZIMODEL_H
#define SUZIMODEL_H
#pragma once
#include <AbstractModel.hpp>
#include <suzi_flat.h>
class SuziModel : public AbstractModel {
 private:
 public:
  void draw(AbstractShader *shader, Transform *transform) override;
  SuziModel();
  ~SuziModel();
};
#endif