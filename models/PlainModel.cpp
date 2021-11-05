#include <PlainModel.hpp>

PlainModel::PlainModel() {
  numberOfTriangles = 6;
  GLuint VBO = 0;
  glGenBuffers(1, &VBO);  // generate the VBO
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(plain), plain, GL_STATIC_DRAW);

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

PlainModel::~PlainModel() {}

void PlainModel::draw(AbstractShader *shader, Transform *transform) {
  render(shader, transform);
};
