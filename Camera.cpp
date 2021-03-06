#include <Camera.hpp>

void Camera::resize(int width, int height) {
  projectionMatrix = glm::perspective(glm::radians(45.0f),
                                      (float)width / height, 0.1f, 100.0f);
  notify(this);
}

void Camera::resetCameraPosition() {
  eye = {0, 10, 0};
  theta = glm::radians(178.0f);
  calculateSphereCord();
  notify(this);
}

void Camera::toFront() {
  eye += (glm::normalize(target) * MOVEMENT_SPEED);
  notify(this);
}
void Camera::toLeft() {
  eye += (glm::normalize(glm::cross(target, up)) * -MOVEMENT_SPEED);
  notify(this);
}
void Camera::toRight() {
  eye += (glm::normalize(glm::cross(target, up)) * MOVEMENT_SPEED);
  notify(this);
}
void Camera::toBack() {
  eye += (-MOVEMENT_SPEED * glm::normalize(target));
  notify(this);
}

void Camera::adjustTarget(glm::vec2 newMousePos) {
  float deltaX = oldMousePos.x - newMousePos.x;
  float deltaY = oldMousePos.y - newMousePos.y;
  oldMousePos = newMousePos;

  // Horizontal mouse movement changes Phi, and vertical movement changes Theta

  if (deltaX > 0) {
    phi -= MOUSE_SENSITIVITY;
  } else if (deltaX < 0) {
    phi += MOUSE_SENSITIVITY;
  }

  if (deltaY > 0 && theta > glm::radians(1.0)) {
    theta -= MOUSE_SENSITIVITY;
  } else if (deltaY < 0 && theta < glm::radians(179.0)) {
    theta += MOUSE_SENSITIVITY;
  }
  calculateSphereCord();
  notify(this);
}

void Camera::calculateSphereCord() {
  target.x = radius * sin(theta) * cos(phi);
  target.z = radius * sin(theta) * sin(phi);
  target.y = radius * cos(theta);
}
glm::mat4 Camera::getCameraLookAt() {
  return glm::lookAt(eye, eye + target, up);
}

Camera::Camera(glm::vec2 resolution) {
  projectionMatrix = glm::perspective(
      glm::radians(45.0f), (float)resolution.x / resolution.y, 0.1f, 100.0f);
  viewMatrix = glm::lookAt(
      glm::vec3(10, 10, 10),  // Camera is at (4,3,-3), in World Space
      glm::vec3(0, 0, 0),     // and looks at the origin
      glm::vec3(0, 1, 0)      // Head is up (set to 0,-1,0 to look

  );
}

Camera::~Camera() {}