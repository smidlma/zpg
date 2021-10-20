#include "Scene.hpp"

#include "Camera.hpp"
void Scene::addObject(DrawableObject *o) { objects.push_back(o); }

void Scene::updateCamera() {
  // printf("Update \n");
  GLint idProjectionMatrix = glGetUniformLocation(
      camera->shader->getShaderProgram(), "projectionMatrix");
  if (idProjectionMatrix == -1) {
    fprintf(stderr, "ProjectionMatrix not found \n");
  }
  glUniformMatrix4fv(idProjectionMatrix, 1, GL_FALSE,
                     &camera->projectionMatrix[0][0]);

  GLint idViewMatrix =
      glGetUniformLocation(camera->shader->getShaderProgram(), "viewMatrix");
  if (idViewMatrix == -1) {
    fprintf(stderr, "ViewMatrix not found \n");
  }
  glUniformMatrix4fv(idViewMatrix, 1, GL_FALSE, &camera->getCamera()[0][0]);
}

void Scene::render() {}

Scene::Scene() {
  camera = new Camera(this);
  CallbackController::getInstance()->registerCamera(camera);
}

Scene::~Scene() {}