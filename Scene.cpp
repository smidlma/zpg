#include "Scene.hpp"

void Scene::render() {
  GLint idProjectionMatrix =
      glGetUniformLocation(shader->getShaderProgram(), "projectionMatrix");
  if (idProjectionMatrix == -1) {
    fprintf(stderr, "ProjectionMatrix not found \n");
  }
  glUniformMatrix4fv(idProjectionMatrix, 1, GL_FALSE, &projectionMatrix[0][0]);

  GLint idViewMatrix =
      glGetUniformLocation(shader->getShaderProgram(), "viewMatrix");
  if (idViewMatrix == -1) {
    fprintf(stderr, "ViewMatrix not found \n");
  }
  glUniformMatrix4fv(idViewMatrix, 1, GL_FALSE, &viewMatrix[0][0]);

  //   while (1) {
  //     for (auto o : objects) {
  //         o.draw();
  //     }
  //   }
}

Scene::Scene() {}

Scene::~Scene() {}