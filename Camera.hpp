#ifndef CAMERA_H
#define CAMERA_H
#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

// Include GLM
#include <glm/gtc/matrix_transform.hpp>  // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/mat4x4.hpp>  // glm::mat4
#include <glm/vec3.hpp>    // glm::vec3
#include <vector>
#include <Engine.hpp>
#include <ISubject.hpp>

class Camera : public ISubject {
 private:
  glm::vec3 target = {0, 0, 0};
  glm::vec3 up = {0, 1, 0};
  glm::vec2 oldMousePos = {400, 300};
  float theta = glm::radians(178.0f);
  float phi = 0;
  float radius = 1;
  const float MOVEMENT_SPEED = 0.1f;
  const float MOUSE_SENSITIVITY = 0.02f;
  
  void calculateSphereCord();

 public:
  glm::vec3 eye = {0, 10, 0};
  glm::mat4 viewMatrix;
  glm::mat4 projectionMatrix;
  Camera();
  ~Camera();
  glm::mat4 getCameraLookAt();
  void adjustTarget(glm::vec2 newMousePos);
  void toFront();
  void toLeft();
  void toRight();
  void toBack();
  void resetCameraPosition();
  void resize(int width, int height);
};
#endif