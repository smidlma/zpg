#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#pragma once

#include "CallbackController.hpp"
#include "Camera.hpp"
#include "ModelFactory.hpp"
#include "Scene.hpp"
#include "Shader.hpp"
#include "Transform.hpp"

class SceneManager {
 private:
 public:
  SceneManager();
  ~SceneManager();
  static Scene *makeSimpleScene() {
    Scene *scene = new Scene();
    Camera *camera = new Camera();
    CallbackController::getInstance()->registerCamera(camera);
    Shader *loadedS = new Shader();
    loadedS->loadShader("shaders/phongVertex.txt", "shaders/phongFragment.txt");
    camera->registerShader(loadedS);

    AbstractModel *sphere = ModelFactory::makeSphere();
    Transform *tr1 = new Transform();
    Transform *tr2 = new Transform();
    Transform *tr3 = new Transform();
    Transform *tr4 = new Transform();

    tr1->translate(glm::vec3(1.0f, 0.0f, 0.0f));
    tr2->translate(glm::vec3(-1.0f, 0.0f, 0.0f));
    tr3->translate(glm::vec3(0.0f, 0.0f, 1.0f));
    tr4->translate(glm::vec3(0.0f, 0.0f, -1.0f));
    tr1->scale(0.4f);
    tr2->scale(0.4f);
    tr3->scale(0.4f);
    tr4->scale(0.4f);

    scene->addObject(new DrawableObject(sphere, tr1, loadedS));
    scene->addObject(new DrawableObject(sphere, tr2, loadedS));
    scene->addObject(new DrawableObject(sphere, tr3, loadedS));
    scene->addObject(new DrawableObject(sphere, tr4, loadedS));

    return scene;
  }
};
#endif