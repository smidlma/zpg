#include <DrawableObject.hpp>
int DrawableObject::idCounter = 1;

AbstractModel *DrawableObject::getModel() { return model; }
std::vector<Material *> DrawableObject::getMaterials() { return materials; }

Transform *DrawableObject::getTransform() { return transform; }

AbstractShader *DrawableObject::getShader() { return shader; }

void DrawableObject::clickAction() {
  std::cout << "clicked id:" << id << std::endl;
}

int DrawableObject::getId() { return id; }

void DrawableObject::draw() {
  for (auto *m : materials) {
    m->useMaterial(shader);
  }
  model->draw(shader, transform);
}

// DrawableObject::DrawableObject(AbstractModel *model, Transform *transform,
//                                AbstractShader *shader) {
//   id = idCounter;
//   this->model = model;
//   this->transform = transform;
//   this->shader = shader;
//   idCounter++;
// }

DrawableObject::DrawableObject(AbstractModel *model, Transform *transform,
                               AbstractShader *shader, Material *material) {
  id = idCounter;
  this->model = model;
  this->transform = transform;
  this->shader = shader;
  this->materials.push_back(material);
  idCounter++;
}

DrawableObject::DrawableObject(AbstractModel *model, Transform *transform,
                               AbstractShader *shader,
                               std::vector<Material *> materials) {
  id = idCounter;
  this->model = model;
  this->transform = transform;
  this->shader = shader;
  this->materials = materials;

  idCounter++;
}

DrawableObject::~DrawableObject() {}