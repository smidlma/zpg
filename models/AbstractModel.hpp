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
    glUseProgram(shader->getShaderProgram());
    GLint idModelTransform =
        glGetUniformLocation(shader->getShaderProgram(), "modelMatrix");
    if (idModelTransform == -1) {
      fprintf(stderr, "matrixModel not found \n");
      exit(1);
    }
    glUniformMatrix4fv(idModelTransform, 1, GL_FALSE,
                       &transform->getModelMatrix()[0][0]);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, indicesCount);
    glBindVertexArray(0);
    glUseProgram(0);
  }

 public:
  void virtual draw(AbstractShader *shader, Transform *transform) = 0;
  int getId() { return id; };
  AbstractModel(){};
};
#endif