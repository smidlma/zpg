#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H
#pragma once
#include <AbstractModel.hpp>
#include <Material.hpp>
#include <Transform.hpp>

class DrawableObject {
 private:
  AbstractModel *model;
  Transform *transform;
  AbstractShader *shader;
  Material *material = nullptr;

 public:
  DrawableObject(AbstractModel *model, Transform *transform,
                 AbstractShader *shader);
  DrawableObject(AbstractModel *model, Transform *transform,
                 AbstractShader *shader, Material *material);
  ~DrawableObject();
  void draw();
  Transform *getTransform() { return transform; }
};
#endif