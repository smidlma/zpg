#include "Model.hpp"

void Model::transalte(float myView) {
  
  M *= glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, myView));
}

void Model::scale(float scale){
  M *= glm::scale(glm::mat4(1.0f), glm::vec3(scale));
}

void Model::rotate(float angel) {
  M *= glm::rotate(glm::mat4(1.0f), angel, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Model::setForRender() {
  glUseProgram(shader->getShaderProgram());
  glBindVertexArray(this->getVAO());
  glDrawArrays(GL_TRIANGLES, 0, 3);  // mode,first,count
  GLint idModelTransform =
      glGetUniformLocation(shader->getShaderProgram(), "modelMatrix");
  if (idModelTransform == -1) {
    fprintf(stderr, "matrixModel not found \n");
  }
  glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &M[0][0]);
  M = glm::mat4(1.0f);
}

Model::Model(std::vector<ModelStruct> model, Shader *shader) {
  this->shader = shader;
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
                        (GLvoid *)0);

  glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(model.at(0)),
                        (GLvoid *)(4 * sizeof(GL_FLOAT)));
}

GLuint Model::getVAO() { return this->VAO; }

Model::~Model() {}