#include "Camera.hpp"

#include "Scene.hpp"

void Camera::adjustTarget(double mouseXPos, double mouseYPos) {
  // printf("x=[%f], y=[%f] \n", mouseXPos, mouseYPos);

  float xoffset = mouseXPos - lastX;
  float yoffset =
      lastY - mouseYPos;  // reversed since y-coordinates range from bottom to top
  lastX = mouseXPos;
  lastY = mouseYPos;
  yaw

  // printf("%f\n", r);

  // float fi = mouseXPos * 0.5 + mouseYPos;
  // float psi = mouseYPos * 0.5 + mouseXPos;
  // target.x = cos(fi);
  // target.z = sin(fi);
  // target.y = sin(psi);

  scene->updateCamera();
}

glm::mat4 Camera::getCamera() {
  return glm::lookAt(
      glm::vec3(10, 10, 10),  // Camera is at (4,3,-3), in World Space
      glm::vec3(0, 0, 0),     // and looks at the origin
      glm::vec3(0, 1, 0)      // Head is up (set to 0,-1,0 to look upside-down)
  );
  // glm::lookAt(eye, eye + target, up);
}

Camera::Camera(Scene *scene) {
  shader = new Shader();
  this->scene = scene;
  projectionMatrix =
      glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
  viewMatrix = getCamera();
}

Camera::~Camera() {}