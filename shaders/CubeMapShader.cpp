#include "CubeMapShader.hpp"

void CubeMapShader::update(Camera *camera) {
  use();
  setMat4("projectionMatrix", camera->projectionMatrix);
  glm::mat4 view = glm::mat4(glm::mat3(camera->getCameraLookAt()));
  setMat4("viewMatrix", view);
}

CubeMapShader::CubeMapShader() {
  loadShader("shaders/skyboxVertex", "shaders/skyboxFragment");
}