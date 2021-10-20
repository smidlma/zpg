#include "Shader.hpp"
void Shader::updateCamera(Camera* camera) {
  // printf("Update \n");
  GLint idProjectionMatrix =
      glGetUniformLocation(shaderProgram, "projectionMatrix");
  if (idProjectionMatrix == -1) {
    fprintf(stderr, "ProjectionMatrix not found \n");
  }
  glUniformMatrix4fv(idProjectionMatrix, 1, GL_FALSE,
                     &camera->projectionMatrix[0][0]);

  GLint idViewMatrix = glGetUniformLocation(shaderProgram, "viewMatrix");
  if (idViewMatrix == -1) {
    fprintf(stderr, "ViewMatrix not found \n");
  }
  glUniformMatrix4fv(idViewMatrix, 1, GL_FALSE, &camera->getCamera()[0][0]);
}

GLuint Shader::getShaderProgram() { return this->shaderProgram; }

Shader::Shader() {
  // create and compile shaders
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertex_shader, NULL);
  glCompileShader(vertexShader);
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
  glCompileShader(fragmentShader);
  this->shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, fragmentShader);
  glAttachShader(shaderProgram, vertexShader);
  glLinkProgram(shaderProgram);

  GLint status;
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
  if (status == GL_FALSE) {
    GLint infoLogLength;
    glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
    GLchar* strInfoLog = new GLchar[infoLogLength + 1];
    glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, strInfoLog);
    fprintf(stderr, "Linker failure: %s\n", strInfoLog);
    delete[] strInfoLog;
    exit(EXIT_FAILURE);
  }
}

Shader::~Shader() {}