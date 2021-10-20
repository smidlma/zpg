#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H
#pragma once
#include "AbstractModel.hpp"
#include "Shader.hpp"
#include "Transform.hpp"
class DrawableObject {
 private:
  AbstractModel *model;
  Transform *transform;
  Shader *shader;

 public:
  DrawableObject(AbstractModel *model, Transform *transform, Shader *shader);
  ~DrawableObject();
  void draw();
};
#endif