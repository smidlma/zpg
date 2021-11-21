#include "CubeMapShader.hpp"

void CubeMapShader::update(Camera *camera) {
  glUseProgram(shaderProgramID);
  GLint idProjectionMatrix =
      glGetUniformLocation(shaderProgramID, "projectionMatrix");
  if (idProjectionMatrix == -1) {
    fprintf(stderr, "ProjectionMatrix not found \n");
    exit(1);
  }
  glUniformMatrix4fv(idProjectionMatrix, 1, GL_FALSE,
                     &camera->projectionMatrix[0][0]);

  GLint idViewMatrix = glGetUniformLocation(shaderProgramID, "viewMatrix");
  if (idViewMatrix == -1) {
    fprintf(stderr, "ViewMatrix not found \n");
    exit(1);
  }

  glm::mat4 view = glm::mat4(glm::mat3(camera->getCameraLookAt()));
  glUniformMatrix4fv(idViewMatrix, 1, GL_FALSE,
                     &view[0][0]);



  glUseProgram(0);
}

CubeMapShader::CubeMapShader() {
  loadShader("shaders/skyboxVertex", "shaders/skyboxFragment");
}