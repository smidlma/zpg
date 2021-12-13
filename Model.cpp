#include "Model.hpp"

Model::Model(GLuint VAO, GLsizei indicesCount) {
  this->VAO = VAO;
  this->indicesCount = indicesCount;
}

Model::~Model() {}

void Model::draw(AbstractShader* shader, Transform* transform) {
  // GLint idModelTransform =
  //     glGetUniformLocation(shader->getShaderProgram(), "modelMatrix");
  // if (idModelTransform == -1) {
  //   fprintf(stderr, "matrixModel not found \n");
  //   exit(1);
  // }
  
  shader->setMat4("modelMatrix", transform->getModelMatrix());
  // pridat VAO
  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, NULL);
}