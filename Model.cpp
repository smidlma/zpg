#include "Model.hpp"
struct ModelStruct {
    float pos[4];
    int rgba[4];
};

Model::Model() {
    const ModelStruct points[] ={
   { { -.5f, -.5f, .5f, 1 }, { 1, 1, 0, 1 } },
   { { -.5f, .5f, .5f, 1 }, { 1, 0, 0, 1 } },
   { { .5f, .5f, .5f, 1 }, { 0, 0, 0, 1 } },
   { { .5f, -.5f, .5f, 1 }, { 0, 1, 0, 1 } },
};
  GLuint VBO = 0;
  glGenBuffers(1, &VBO);  // generate the VBO
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

  glGenVertexArrays(1, &VAO);    // generate the VAO
  glBindVertexArray(VAO);        // bind the VAO
  glEnableVertexAttribArray(0);  // enable vertex attributes
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

GLuint Model::getVAO(){
    return this->VAO;
}

Model::~Model() {}