#include <NormalShader.hpp>

void NormalShader::update(Camera *camera) {
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

  GLint idViewPos = glGetUniformLocation(shaderProgramID, "viewPos");
  if (idViewPos == -1) {
    fprintf(stderr, "ViewPos not found \n");
  }
  glUniform3fv(idViewPos, 1, &camera->eye[0]);

  glUseProgram(0);
}

NormalShader::NormalShader() {
  loadShader("shaders/PhongVertexShader.glsl",
             "shaders/PhongFragmentShader.glsl");
}

NormalShader::~NormalShader() {}