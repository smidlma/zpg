#include <NormalShader.hpp>

void NormalShader::update(Camera *camera) {
  use();
  setMat4("projectionMatrix", camera->projectionMatrix);
  setMat4("viewMatrix", camera->getCameraLookAt());
  setVec3("viewPos", camera->eye);
}

NormalShader::NormalShader() {
  loadShader("shaders/PhongVertexShader.glsl",
             "shaders/PhongFragmentShader.glsl");
}

NormalShader::~NormalShader() {}