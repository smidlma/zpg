#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#pragma once

#include <AbstractLight.hpp>
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
#include <PointLight.hpp>
#include <Scene.hpp>
#include <SkyBox.hpp>
#include <Texture.hpp>
#include <Transform.hpp>
#include <vector>
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