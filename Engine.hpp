#ifndef ENGINE_H
#define ENGINE_H
#pragma once
#include <GL/glew.h>
// Include GLFW
#include <GLFW/glfw3.h>

// Include GLM
#include <glm/gtc/matrix_transform.hpp>  // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>  // glm::value_ptr
#include <glm/mat4x4.hpp>        // glm::mat4
#include <glm/vec3.hpp>          // glm::vec3
#include <glm/vec4.hpp>          // glm::vec4

// Include the standard C++ headers
#include <stdio.h>
#include <stdlib.h>

#include "CallbackController.hpp"
#include "Scene.hpp"
#include "Shader.hpp"
#include "DrawableObject.hpp"
#include "ModelFactory.hpp"
#include "Transform.hpp"
#include "Renderer.hpp"
#include "SceneManager.hpp"

class Engine {
 private:
  static Engine *engine;
  GLFWwindow *window;
  Scene *scene;
  Engine();
  void draw();
  void init();
  void setCallbacks();
  void initScene();

 public:
  static Engine *getEngine();
  ~Engine();
  void run();
  Scene *getScene();
};
#endif