#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H
#pragma once

#include <AbstractShader.hpp>
#include <Transform.hpp>

class AbstractModel {
 protected:
  GLuint VAO = 0;
  GLsizei indicesCount = 0;
  int id = 0;

  void render(AbstractShader *shader, Transform *transform) {
    shader->setMat4("modelMatrix", transform->getModelMatrix());

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, indicesCount);
    glBindVertexArray(0);
  }

 public:
  void virtual draw(AbstractShader *shader, Transform *transform) = 0;
  int getId() { return id; };
  AbstractModel(){};
};
#endif