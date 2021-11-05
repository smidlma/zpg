#include <Camera.hpp>
#include <Scene.hpp>
void Scene::addObject(DrawableObject *o) { objects.push_back(o); }

Scene::Scene() {}

Scene::~Scene() {}