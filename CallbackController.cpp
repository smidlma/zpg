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

void CallbackController::mouseButtonCallback(GLFWwindow* window, int button,
                                             int action, int mods) {
  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
    // Identifikace
    GLbyte color[4];
    GLfloat depth;
    GLuint index;

    double xpos, ypos;
    // getting cursor position
    glfwGetCursorPos(window, &xpos, &ypos);
    GLint x = (GLint)xpos;
    GLint y = (GLint)ypos;

    glm::vec2 res = Engine::getEngine()->resolution;
    int newy = res.y - y;

    glReadPixels(x, newy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
    glReadPixels(x, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
    glReadPixels(x, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

    printf(
        "Clicked on pixel %d, %d, color %02hhx%02hhx%02hhx%02hhx,depth "
        "%f,stencil index %u\n",
        x, y, color[0], color[1], color[2], color[3], depth, index);

    for (auto* o :
         Engine::getEngine()->sceneManager->getCurrentScene()->objects) {
      // Identify
      if (o->getId() == index) {
        // cameras[0]->removeObserver(o->shader);
        // o->shader = new LambertShader();
        // cameras[0]->registerObserver(o->shader);

        o->clickAction();
        // Můžeme vypočíst pozici v globálním souřadném systému.

        glm::vec3 screenX = glm::vec3(x, newy, depth);
        glm::vec4 viewPort = glm::vec4(0, 0, res.x, res.y);
        glm::vec3 pos = glm::unProject(screenX, cameras[0]->getCameraLookAt(),
                                       cameras[0]->projectionMatrix, viewPort);

        printf("unProject [%f,%f,%f]\n", pos.x, pos.y, pos.z);

        Engine::getEngine()->sceneManager->makeTree(pos);
      }
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