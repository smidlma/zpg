#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#pragma once

#include <vector>

#include "CallbackController.hpp"
#include "Camera.hpp"
#include "ModelFactory.hpp"
#include "Scene.hpp"
#include "Shader.hpp"
#include "Transform.hpp"
class SceneManager {
 private:
  Scene *currentScene;
  std::vector<Scene *> scenes;

 public:
  void getCurrentScene();
  int setScene(int index);
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

  static Scene *makeForestScene() {
    Camera *camera = new Camera();
    CallbackController::getInstance()->registerCamera(camera);
    Shader *loadedS = new Shader();
    loadedS->loadShader("shaders/phongVertex.txt", "shaders/phongFragment.txt");
    camera->registerShader(loadedS);
    Scene *scene = new Scene();
    AbstractModel *plain = ModelFactory::makePlain();
    Transform *tr = new Transform();
    tr->scale(40.0f);
    tr->translate(glm::vec3(0, 0, 0));
    scene->addObject(new DrawableObject(plain, tr, loadedS));

    AbstractModel *tree = ModelFactory::makeTree();
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
      Transform *tran = new Transform();
      float x = rand() % 61 - 30;
      float z = rand() % 61 - 30;
      tran->translate(glm::vec3(x, 0, z));
      tran->scale((float) i);
      scene->addObject(new DrawableObject(tree, tran, loadedS));
    }
    return scene;
  }
};
#endif