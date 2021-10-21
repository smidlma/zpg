#include "Scene.hpp"

#include "Camera.hpp"
void Scene::addObject(DrawableObject *o) { objects.push_back(o); }

void Scene::render() {
  for (DrawableObject *o : objects) {
    o->draw();
  }
}

Scene::Scene() {
  // camera = new Camera();
  // CallbackController::getInstance()->registerCamera(camera);
}

Scene::~Scene() {}