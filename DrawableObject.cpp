#include <DrawableObject.hpp>
int DrawableObject::idCounter = 1;

AbstractModel *DrawableObject::getModel() { return model; }

Material *DrawableObject::getMaterial() { return material; }

Transform *DrawableObject::getTransform() { return transform; }

AbstractShader *DrawableObject::getShader() { return shader; }

void DrawableObject::clickAction() {
  std::cout << "clicked id:" << id << std::endl;
}

int DrawableObject::getId() { return id; }

void DrawableObject::draw() {
  // Use shader for that object
  shader->use();
  // -------------

  material->useMaterial(shader);

  model->draw(shader, transform);
}

DrawableObject::DrawableObject(AbstractModel *model, Transform *transform,
                               AbstractShader *shader, Material *material) {
  id = idCounter;
  this->model = model;
  this->transform = transform;
  this->shader = shader;
  this->material = material;
  idCounter++;
}

DrawableObject::~DrawableObject() {}