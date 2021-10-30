#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H
#pragma once

#include "Shader.hpp"
#include "Transform.hpp"

class AbstractModel {
 protected:
  GLuint VAO = 0;
  GLsizei numberOfTriangles = 0;

  void render(Shader *shader, Transform *transform) {
    glUseProgram(shader->getShaderProgram());
    glBindVertexArray(VAO);
    GLint idModelTransform =
        glGetUniformLocation(shader->getShaderProgram(), "modelMatrix");
    if (idModelTransform == -1) {
      fprintf(stderr, "matrixModel not found \n");
      exit(1);
    }
    glUniformMatrix4fv(idModelTransform, 1, GL_FALSE,
                       &transform->getModelMatrix()[0][0]);
    glDrawArrays(GL_TRIANGLES, 0, numberOfTriangles);
  }

 public:
  void virtual draw(Shader *shader, Transform *transform) = 0;
};
#endif