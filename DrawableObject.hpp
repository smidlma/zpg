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
  AbstractModel *model;
  Transform *transform;
  std::vector<Material *> materials;

 public:
  AbstractShader *shader;
  DrawableObject(AbstractModel *model, Transform *transform,
                 AbstractShader *shader);
  DrawableObject(AbstractModel *model, Transform *transform,
                 AbstractShader *shader, Material *material);
  DrawableObject(AbstractModel *model, Transform *transform,
                 AbstractShader *shader, std::vector<Material *> materials);
  ~DrawableObject();

  void draw();
  int getId();

  void clickAction();

  Transform *getTransform();

  AbstractShader *getShader();
};
#endif