#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H
#pragma once
#include <AbstractModel.hpp>
#include <Material.hpp>
#include <Transform.hpp>

class DrawableObject {
 private:
  static int idCounter;
  int id = 0;

 protected:
  Transform *transform;
  AbstractModel *model;

 public:
  Material *material;
  AbstractShader *shader;
  bool isSelectable = true;

  DrawableObject(AbstractModel *model, Transform *transform,
                 AbstractShader *shader, Material *material);

  ~DrawableObject();

  virtual void draw();

  int getId();

  void clickAction();

  Transform *getTransform();

  AbstractShader *getShader();

  AbstractModel *getModel();

  Material *getMaterial();
};
#endif