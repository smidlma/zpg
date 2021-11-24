#include "Model.hpp"

Model::Model(GLuint VAO, GLsizei indicesCount) {
  this->VAO = VAO;
  this->indicesCount = indicesCount;
}

Model::~Model() {}

void Model::draw(AbstractShader* shader, Transform* transform) {
  glUseProgram(shader->getShaderProgram());
  // glBindBuffer(GL_ARRAY_BUFFER, 0);
  GLint idModelTransform =
      glGetUniformLocation(shader->getShaderProgram(), "modelMatrix");
  if (idModelTransform == -1) {
    fprintf(stderr, "matrixModel not found \n");
    exit(1);
  }
  glUniformMatrix4fv(idModelTransform, 1, GL_FALSE,
                     &transform->getModelMatrix()[0][0]);
  // pridat VAO
  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, NULL);
  glUseProgram(0);
}