#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H
#pragma once
#include <AbstractModel.hpp>
#include <Transform.hpp>
class DrawableObject {
 private:
  AbstractModel *model;
  Transform *transform;
  AbstractShader *shader;

 public:
  DrawableObject(AbstractModel *model, Transform *transform, AbstractShader *shader);
  ~DrawableObject();
  void draw();
  Transform *getTransform(){
    return transform;
  }
};
#endif