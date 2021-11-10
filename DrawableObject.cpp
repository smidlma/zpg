#include <DrawableObject.hpp>

void DrawableObject::draw() {
  model->draw(shader, transform);
  if (material) {
    material->texture->useTexture(shader);
  }
}

DrawableObject::DrawableObject(AbstractModel *model, Transform *transform,
                               AbstractShader *shader) {
  this->model = model;
  this->transform = transform;
  this->shader = shader;
}

DrawableObject::DrawableObject(AbstractModel *model, Transform *transform,
                               AbstractShader *shader, Material *material) {
  this->model = model;
  this->transform = transform;
  this->shader = shader;
  this->material = material;
}

DrawableObject::~DrawableObject() {}