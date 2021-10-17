#include "CallbackController.hpp"

CallbackController* CallbackController::callbackController = nullptr;

void CallbackController::registerCamera(Camera* camera) {
  cameras.push_back(camera);
}

void CallbackController::cursorPosCallback(GLFWwindow* window, double mouseXPos,
                                           double mouseYPos) {
  for (auto c : cameras) {
    c->adjustTarget(mouseXPos, mouseYPos);
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