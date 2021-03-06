#ifndef TREEMODEL_H
#define TREEMODEL_H
#pragma once
#include <AbstractModel.hpp>
#include <tree.h>
class TreeModel : public AbstractModel {
 private:
 public:
  void draw(AbstractShader *shader, Transform *transform) override;

  TreeModel();
  ~TreeModel();
};
#endif