#include <Transform.hpp>

void Transform::translate(glm::vec3 delta) { position = delta; }

void Transform::scale(float scaleVal) {
  this->scaleVal = scaleVal;
  // modelMatrix *= glm::scale(glm::mat4(1.0f), glm::vec3(scale, scale, scale));
}

void Transform::rotate(glm::vec3 angel) { this->rotation = angel; }

glm::mat4 Transform::getModelMatrix() {
  glm::mat4 posMatrix = glm::translate(glm::mat4(1.0f), position);
  glm::mat4 rotXMatrix =
      glm::rotate(glm::mat4(1.0f), rotation.x, glm::vec3(1, 0, 0));
  glm::mat4 rotYMatrix =
      glm::rotate(glm::mat4(1.0f), rotation.y, glm::vec3(0, 1, 0));
  glm::mat4 rotZMatrix =
      glm::rotate(glm::mat4(1.0f), rotation.z, glm::vec3(1, 0, 0));
  glm::mat4 scaleMatrix =
      glm::scale(glm::mat4(1.0f), glm::vec3(scaleVal, scaleVal, scaleVal));

  glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

  return posMatrix * rotMatrix * scaleMatrix;
}
void Transform::reset() { modelMatrix = glm::mat4(1.0f); }
Transform::Transform() {}

Transform::~Transform() {}