#include "Shader.hpp"
#include "Camera.hpp"
void Shader::updateCamera(Camera* camera) {
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
  glUniformMatrix4fv(idViewMatrix, 1, GL_FALSE, &camera->getCameraLookAt()[0][0]);
}

GLuint Shader::getShaderProgram() { return this->shaderProgramID; }

Shader::Shader() {
  // create and compile shaders
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertex_shader, NULL);
  glCompileShader(vertexShader);
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
  glCompileShader(fragmentShader);
  this->shaderProgramID = glCreateProgram();
  glAttachShader(shaderProgramID, fragmentShader);
  glAttachShader(shaderProgramID, vertexShader);
  glLinkProgram(shaderProgramID);

  GLint status;
  glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &status);
  if (status == GL_FALSE) {
    GLint infoLogLength;
    glGetProgramiv(shaderProgramID, GL_INFO_LOG_LENGTH, &infoLogLength);
    GLchar* strInfoLog = new GLchar[infoLogLength + 1];
    glGetProgramInfoLog(shaderProgramID , infoLogLength, NULL, strInfoLog);
    fprintf(stderr, "Linker failure: %s\n", strInfoLog);
    delete[] strInfoLog;
    exit(EXIT_FAILURE);
  }
}

Shader::~Shader() {}