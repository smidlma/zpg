#include "CallbackController.hpp"

CallbackController* CallbackController::callbackController = nullptr;

void CallbackController::registerCamera(Camera* camera) {
  cameras.push_back(camera);
}

void CallbackController::keyCallback(GLFWwindow* window, int key, int scancode,
                                     int action, int mods) {
  if (key == GLFW_KEY_W) {
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

  if (key == GLFW_KEY_R) {
    for (auto c : cameras) {
      c->resetCameraPosition();
    }
  }
}
void CallbackController::windowSizeChangeCallback(GLFWwindow* window, int width,
                                                  int height) {
  for (auto c : cameras) {
    c->resize(width, height);
  }
  glViewport(0, 0, width, height);
}
void CallbackController::cursorPosCallback(GLFWwindow* window, double mouseXPos,
                                           double mouseYPos) {
  int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
  if (state == GLFW_PRESS) {
    for (auto c : cameras) {
      c->adjustTarget({mouseXPos, mouseYPos});
    }
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