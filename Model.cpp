#include "Model.hpp"

Model::Model(std::vector<ModelStruct> model) {
  const ModelStruct b[] = {
      {{-.5f, -.5f, .5f, 1}, {1, 0, 0, 1}},
      {{-.5f, .5f, .5f, 1}, {0, 1, 0, 1}},
      {{.5f, .5f, .5f, 1}, {0, 0, 1, 1}},
  };
  GLuint VBO = 0;
  glGenBuffers(1, &VBO);  // generate the VBO
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(model.at(0)) * model.size(),
               model.data(), GL_STATIC_DRAW);

  glGenVertexArrays(1, &VAO);  // generate the VAO
  glEnableVertexAttribArray(0);
  glBindVertexArray(VAO);  // bind the VAO
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(model.at(0)),
                        (GLvoid*)0);

  glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(model.at(0)),
                        (GLvoid*)(4 * sizeof(GL_FLOAT)));
}

GLuint Model::getVAO() { return this->VAO; }

Model::~Model() {}