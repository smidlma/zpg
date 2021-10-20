#include "DrawableObject.hpp"

void DrawableObject::draw() { model->draw(shader, transform); }

DrawableObject::DrawableObject(AbstractModel *model, Transform *transform,
                               Shader *shader) {
  this->model = model;
  this->transform = transform;
  this->shader = shader;
}

DrawableObject::~DrawableObject() {}