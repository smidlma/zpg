#include <AbstractShader.hpp>

// AbstractShader::AbstractShader(std::vector<AbstractLight*> lights) {
//   this->lights = lights;
// }

void AbstractShader::use() { glUseProgram(shaderProgramID); }

void AbstractShader::setMat4(const char *name, glm::mat4 mat) {
  glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, name), 1, GL_FALSE,
                     &mat[0][0]);
}

void AbstractShader::setVec3(const char *name, glm::vec3 value) {
  glUniform3fv(glGetUniformLocation(shaderProgramID, name), 1, &value[0]);
}

void AbstractShader::setInt(const char *name, int value) {
  glUniform1i(glGetUniformLocation(shaderProgramID, name), value);
}
void AbstractShader::setFloat(const char *name, float value) {
  glUniform1f(glGetUniformLocation(shaderProgramID, name), value);
}

AbstractShader::AbstractShader() {}

AbstractShader::~AbstractShader() {}