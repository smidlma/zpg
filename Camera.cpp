#include "Camera.hpp"

#include "Scene.hpp"

void Camera::toFront() {
  eye += (glm::normalize(target) * MOVEMENT_SPEED);
  scene->updateCamera();
}
void Camera::toLeft() {
  eye += (glm::normalize(glm::cross(target, up)) * -MOVEMENT_SPEED);
  scene->updateCamera();
}
void Camera::toRight() {
  eye += (glm::normalize(glm::cross(target, up)) * MOVEMENT_SPEED);
  scene->updateCamera();
}
void Camera::toBack() {
  eye += (-MOVEMENT_SPEED * glm::normalize(target));
  scene->updateCamera();
}

void Camera::adjustTarget(glm::vec2 newMousePos) {
  // printf("x=[%f], y=[%f] \n", mouseXPos, mouseYPos);
  float sensitivity = 0.01;
  float deltaX = oldMousePos.x - newMousePos.x;
  float deltaY = oldMousePos.y - newMousePos.y;
  // printf("deltaX= %f \n", deltaX);
  // printf("deltaY= %f \n", deltaY);

  // Horizontal mouse movement changes Phi, and vertical movement changes Theta
  if (deltaX > 0) {
    phi += sensitivity;
  } else if (deltaX < 0) {
    phi -= sensitivity;
  }

  if (deltaY > 0) {
    theta += sensitivity;
  } else if (deltaY < 0) {
    theta -= sensitivity;
  }

  // printf("theta %f, phi %f \n", theta, phi);
  oldMousePos = newMousePos;
  target.x = radius * sin(theta) * cos(phi);
  target.z = radius * sin(theta) * sin(phi);
  target.y = radius * cos(theta);

  scene->updateCamera();
}
glm::mat4 Camera::getCamera() { return glm::lookAt(eye, eye + target, up); }

Camera::Camera(Scene *scene) {
  shader = new Shader();
  this->scene = scene;
  projectionMatrix =
      glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
  viewMatrix = glm::lookAt(
      glm::vec3(10, 10, 10),  // Camera is at (4,3,-3), in World Space
      glm::vec3(0, 0, 0),     // and looks at the origin
      glm::vec3(0, 1, 0)      // Head is up (set to 0,-1,0 to look

  );
}

Camera::~Camera() {}