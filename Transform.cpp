#include "Transform.hpp"

void Transform::translate(glm::vec3 delta) {
  modelMatrix *= glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, delta));
}

void Transform::scale(float scale) {
  modelMatrix *= glm::scale(glm::mat4(1.0f), glm::vec3(scale));
}

void Transform::rotate(float angel) {
  modelMatrix *=
      glm::rotate(glm::mat4(1.0f), angel, glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Transform::getModelMatrix(){
    return modelMatrix;
}

Transform::Transform() {}

Transform::~Transform() {}