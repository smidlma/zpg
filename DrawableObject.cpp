#include <DrawableObject.hpp>

Transform *DrawableObject::getTransform() { return transform; }

AbstractShader *DrawableObject::getShader() { return shader; }

void DrawableObject::draw() {
  for (auto *m : materials) {
    m->useMaterial(shader);
  }
  model->draw(shader, transform);
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
  this->materials.push_back(material);
}

DrawableObject::DrawableObject(AbstractModel *model, Transform *transform,
                               AbstractShader *shader,
                               std::vector<Material *> materials) {
  this->model = model;
  this->transform = transform;
  this->shader = shader;
  this->materials = materials;
}

DrawableObject::~DrawableObject() {}