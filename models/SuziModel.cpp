#include "SuziModel.hpp"

SuziModel::SuziModel(const float data[]) {
  GLuint VBO = 0;
  glGenBuffers(1, &VBO);  // generate the VBO
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(suziFlat), suziFlat, GL_STATIC_DRAW);

  glGenVertexArrays(1, &VAO);  // generate the VAO
  glEnableVertexAttribArray(0);
  glBindVertexArray(VAO);  // bind the VAO
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                        (GLvoid *)0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                        (GLvoid *)(3 * sizeof(GL_FLOAT)));
}

void SuziModel::draw(Shader *shader, Transform *transform) {
  glUseProgram(shader->getShaderProgram());
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 2904);
  GLint idModelTransform =
      glGetUniformLocation(shader->getShaderProgram(), "modelMatrix");
  if (idModelTransform == -1) {
    fprintf(stderr, "matrixModel not found \n");
    exit(1);
  }
  glUniformMatrix4fv(idModelTransform, 1, GL_FALSE,
                     &transform->getModelMatrix()[0][0]);
}
SuziModel::~SuziModel() {}