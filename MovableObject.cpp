#include "MovableObject.hpp"
void MovableObject::draw() {
  glm::vec4 parameters = glm::vec4(t * t * t, t * t, t, 1.0f);
  glm::vec3 p = parameters * A * glm::transpose(B);
  transform->translate(p);

  for (auto *m : materials) {
    m->useMaterial(shader);
  }
  model->draw(shader, transform);

  if (t >= 1.0f || t <= 0.0f) {
    delta *= -1;
  }
  t += delta;
}

MovableObject::MovableObject(AbstractModel *model, Transform *transform,
                             AbstractShader *shader,
                             std::vector<Material *> materials)
    : DrawableObject(model, transform, shader, materials) {}

MovableObject::MovableObject(AbstractModel *model, Transform *transform,
                             AbstractShader *shader, Material *material)
    : DrawableObject(model, transform, shader, material) {}

void MovableObject::setControlPoints(glm::mat4x3 controlPoints) {
  B = controlPoints;
}

void MovableObject::setSpeed(float speed) { delta = speed; }

MovableObject::~MovableObject() {}