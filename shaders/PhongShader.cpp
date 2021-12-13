#include <PhongShader.hpp>

void PhongShader::update(Camera *camera) {
  use();
  setMat4("projectionMatrix", camera->projectionMatrix);
  setMat4("viewMatrix", camera->getCameraLookAt());
  setVec3("viewPos", camera->eye);
}

PhongShader::PhongShader() {
  loadShader("shaders/phongVertex.vs", "shaders/phongFragment.fs");
}

PhongShader::~PhongShader() {}