#include "Scene.hpp"

#include "Camera.hpp"
void Scene::addObject(DrawableObject *o) { objects.push_back(o); }



Scene::Scene() {
  // camera = new Camera();
  // CallbackController::getInstance()->registerCamera(camera);
}

Scene::~Scene() {}