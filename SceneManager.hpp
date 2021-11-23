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
#include <ConstantShader.hpp>
#include <Material.hpp>
#include <PhongShader.hpp>
#include <AbstractTexture.hpp>
#include <Texture.hpp>
#include <CubeMap.hpp>
#include <CubeMapShader.hpp>
#include <SkyBox.hpp>
#include <ObjectLoader.hpp>
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

  Scene *makeTestScene();
};
#endif