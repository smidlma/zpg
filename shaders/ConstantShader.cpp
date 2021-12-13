#include <ConstantShader.hpp>

void ConstantShader::update(Camera *camera) {
  use();
  setMat4("projectionMatrix", camera->projectionMatrix);
  setMat4("viewMatrix", camera->getCameraLookAt());
}

ConstantShader::ConstantShader() {
  loadShader("shaders/constantVertex.txt", "shaders/constantFragment.txt");
}

ConstantShader::~ConstantShader() {}