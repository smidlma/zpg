#include "TriangleModel.hpp"

void TriangleModel::draw(Shader *shader, Transform *transform) {
  glUseProgram(shader->getShaderProgram());
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 3);  // mode,first,count
  GLint idModelTransform =
      glGetUniformLocation(shader->getShaderProgram(), "modelMatrix");
  if (idModelTransform == -1) {
    fprintf(stderr, "matrixModel not found \n");
  }
  glUniformMatrix4fv(idModelTransform, 1, GL_FALSE,
                     &transform->getModelMatrix()[0][0]);
}

TriangleModel::TriangleModel(std::vector<ModelStruct> data) {
  GLuint VBO = 0;
  glGenBuffers(1, &VBO);  // generate the VBO
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(data.at(0)) * data.size(), data.data(),
               GL_STATIC_DRAW);

  glGenVertexArrays(1, &VAO);  // generate the VAO
  glEnableVertexAttribArray(0);
  glBindVertexArray(VAO);  // bind the VAO
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(data.at(0)),
                        (GLvoid *)0);

  glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(data.at(0)),
                        (GLvoid *)(4 * sizeof(GL_FLOAT)));
}

TriangleModel::~TriangleModel() {}