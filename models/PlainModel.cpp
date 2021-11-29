#include <PlainModel.hpp>

PlainModel::PlainModel() {
  id = 1;
  indicesCount = 6;
  // GLuint VBO = 0;
  // glGenBuffers(1, &VBO);  // generate the VBO
  // glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // glBufferData(GL_ARRAY_BUFFER, sizeof(plain), plain, GL_STATIC_DRAW);

  // glGenVertexArrays(1, &VAO);  // generate the VAO
  // glEnableVertexAttribArray(0);
  // glBindVertexArray(VAO);  // bind the VAO
  // glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // glEnableVertexAttribArray(0);
  // glEnableVertexAttribArray(1);
  // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
  //                       (GLvoid *)0);

  // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
  //                       (GLvoid *)(3 * sizeof(GL_FLOAT)));
  // vertex buffer object (VBO)

  GLuint VBO = 0;
  glGenBuffers(1, &VBO);  // generate the VBO
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(plain), plain, GL_STATIC_DRAW);
  // vertex attribute object(VAO)
  glGenVertexArrays(1, &VAO);    // generate the VAO
  glBindVertexArray(VAO);        // bind the VAO
  glEnableVertexAttribArray(0);  // enable vertex attributes
  glEnableVertexAttribArray(1);
  glEnableVertexAttribArray(2);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                        (GLvoid *)0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                        (GLvoid *)(3 * sizeof(float)));
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                        (GLvoid *)(6 * sizeof(float)));
  glBindVertexArray(0);
}

PlainModel::~PlainModel() {}

void PlainModel::draw(AbstractShader *shader, Transform *transform) {
  render(shader, transform);
};
