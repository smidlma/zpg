#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#pragma once

#include <AbstractShader.hpp>
#include <AbstractTexture.hpp>
#include <CallbackController.hpp>
#include <Camera.hpp>
#include <ConstantShader.hpp>
#include <CubeMap.hpp>
#include <CubeMapShader.hpp>
#include <LambertShader.hpp>
#include <Material.hpp>
#include <ModelFactory.hpp>
#include <ObjectLoader.hpp>
#include <PhongShader.hpp>
#include <Scene.hpp>
#include <SkyBox.hpp>
#include <Texture.hpp>
#include <Transform.hpp>
#include <vector>
#include <LightFactory.hpp>
#include <NormalShader.hpp>
#include <MovableObject.hpp>
class SceneManager {
 private:
  Scene *currentScene;
  std::vector<Scene *> scenes;
  Camera *camera;

 public:
  Scene *getCurrentScene();
  int setScene(int index);
  SceneManager(glm::vec2 resolution);
  ~SceneManager();

  void makeTree(glm::vec3 pos);

  Scene *makeSimpleScene();

  Scene *makeForestScene();

  Scene *makeTestScene();
};
#endif