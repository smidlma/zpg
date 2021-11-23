#include <Scene.hpp>
void Scene::addObject(DrawableObject *o) { objects.push_back(o); }

void Scene::addLight(AbstractLight *l) { lights.push_back(l); }

Scene::Scene() {}

Scene::~Scene() {}