#include "Model.hpp"
struct Vertex {
  float Position[3];
  float Normal[3];
  float Texture[2];
  float Tangent[3];
};

Model::Model(GLsizei indicesCount) { this->indicesCount = indicesCount; }

Model::~Model() {}

void Model::draw(AbstractShader* shader, Transform* transform) {
  glUseProgram(shader->getShaderProgram());
  GLint idModelTransform =
      glGetUniformLocation(shader->getShaderProgram(), "modelMatrix");
  if (idModelTransform == -1) {
    fprintf(stderr, "matrixModel not found \n");
    exit(1);
  }
  glUniformMatrix4fv(idModelTransform, 1, GL_FALSE,
                     &transform->getModelMatrix()[0][0]);

  glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, NULL);
  glUseProgram(0);
}