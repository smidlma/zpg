#include "Camera.hpp"

void Camera::look() {
  
}

glm::mat4 Camera::getCamera() { return glm::lookAt(eye, eye + target, up); }

Camera::Camera() {}

Camera::~Camera() {}