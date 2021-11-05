#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#pragma once

#include <vector>

#include <CallbackController.hpp>
#include <Camera.hpp>
#include <ModelFactory.hpp>
#include <Scene.hpp>
#include <Transform.hpp>
#include <AbstractShader.hpp>
#include <LambertShader.hpp>
#include <PhongShader.hpp>
class SceneManager {
 private:
  Scene *currentScene;
  std::vector<Scene *> scenes;
  Camera *camera;

 public:
  Scene *getCurrentScene();
  int setScene(int index);
  SceneManager();
  ~SceneManager();

  Scene *makeSimpleScene();

  Scene *makeForestScene();
};
#endif