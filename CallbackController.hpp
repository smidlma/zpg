#ifndef CALLBACKCONTROLLER_H
#define CALLBACKCONTROLLER_H
#pragma once

// Include GLFW
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#include <vector>

#include <Camera.hpp>
struct KeyBoard{
  bool front = false;
  bool back = false;
  bool left = false;
  bool right = false;
};

class Engine;
class CallbackController {
 private:
  static CallbackController* callbackController;
  CallbackController();
  std::vector<Camera*> cameras;
  KeyBoard keyBoard;

 public:
  static CallbackController* getInstance();
  ~CallbackController();
  void cursorPosCallback(GLFWwindow* window, double mouseXPos,
                         double mouseYPos);
  void keyCallback(GLFWwindow* window, int key, int scancode, int action,
                   int mods);
  void registerCamera(Camera* camera);
  void windowSizeChangeCallback(GLFWwindow* window, int width, int height);
  void updateMovement();
};
#endif