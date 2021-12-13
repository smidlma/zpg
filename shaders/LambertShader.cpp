#include <LambertShader.hpp>

void LambertShader::update(Camera *camera) {
  use();
  setMat4("projectionMatrix", camera->projectionMatrix);
  setMat4("viewMatrix", camera->getCameraLookAt());
}

LambertShader::LambertShader() {
  loadShader("shaders/lambertVertex.txt", "shaders/lambertFragment.txt");
}

LambertShader::~LambertShader() {}