#include <CallbackController.hpp>
#include <Engine.hpp>

CallbackController* CallbackController::callbackController = nullptr;

void CallbackController::updateMovement() {
  if (keyBoard.front) {
    for (auto c : cameras) {
      c->toFront();
    }
  }
  if (keyBoard.back) {
    for (auto c : cameras) {
      c->toBack();
    }
  }
  if (keyBoard.left) {
    for (auto c : cameras) {
      c->toLeft();
    }
  }
  if (keyBoard.right) {
    for (auto c : cameras) {
      c->toRight();
    }
  }
}

void CallbackController::registerCamera(Camera* camera) {
  cameras.push_back(camera);
}

void CallbackController::keyCallback(GLFWwindow* window, int key, int scancode,
                                     int action, int mods) {
  if (key == GLFW_KEY_W && action == GLFW_PRESS) {
    keyBoard.front = true;
  }

  if (key == GLFW_KEY_W && action == GLFW_RELEASE) {
    keyBoard.front = false;
  }

  if (key == GLFW_KEY_S && action == GLFW_PRESS) {
    keyBoard.back = true;
  }

  if (key == GLFW_KEY_S && action == GLFW_RELEASE) {
    keyBoard.back = false;
  }

  if (key == GLFW_KEY_A && action == GLFW_PRESS) {
    keyBoard.left = true;
  }

  if (key == GLFW_KEY_A && action == GLFW_RELEASE) {
    keyBoard.left = false;
  }

  if (key == GLFW_KEY_D && action == GLFW_PRESS) {
    keyBoard.right = true;
  }

  if (key == GLFW_KEY_D && action == GLFW_RELEASE) {
    keyBoard.right = false;
  }

  if (key == GLFW_KEY_R) {
    for (auto c : cameras) {
      c->resetCameraPosition();
    }
  }

  if (key == GLFW_KEY_1) {
    Engine::getEngine()->sceneManager->setScene(0);
  }

  if (key == GLFW_KEY_2) {
    Engine::getEngine()->sceneManager->setScene(1);
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