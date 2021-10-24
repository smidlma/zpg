#include "CallbackController.hpp"

CallbackController* CallbackController::callbackController = nullptr;

void CallbackController::registerCamera(Camera* camera) {
  cameras.push_back(camera);
}

void CallbackController::keyCallback(GLFWwindow* window, int key, int scancode,
                                     int action, int mods) {

  if (key == GLFW_KEY_W && action== GLFW_REPEAT) {
    for (auto c : cameras) {
      c->toFront();
    }
  }

  if (key == GLFW_KEY_S) {
    for (auto c : cameras) {
      c->toBack();
    }
  }

  if (key == GLFW_KEY_A) {
    for (auto c : cameras) {
      c->toLeft();
    }
  }

  if (key == GLFW_KEY_D) {
    for (auto c : cameras) {
      c->toRight();
    }
  }
}

void CallbackController::cursorPosCallback(GLFWwindow* window, double mouseXPos,
                                           double mouseYPos) {
  glfwSetCursorPos(window, 800/2, 600/2);
  for (auto c : cameras) {
    c->adjustTarget({mouseXPos, mouseYPos});
  }
}

CallbackController* CallbackController::getInstance() {
  if (!callbackController) {
    callbackController = new CallbackController();
  }
  return callbackController;
}

CallbackController::CallbackController() {}

CallbackController::~CallbackController() {}