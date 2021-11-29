#include <LambertShader.hpp>

void LambertShader::update(Camera *camera) {
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
  glUniformMatrix4fv(idViewMatrix, 1, GL_FALSE,
                     &camera->getCameraLookAt()[0][0]);

  glUseProgram(0);
}

LambertShader::LambertShader() {
  loadShader("shaders/lambertVertex.txt", "shaders/lambertFragment.txt");
}

LambertShader::~LambertShader() {}