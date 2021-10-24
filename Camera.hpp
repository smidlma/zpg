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

#include "Shader.hpp"

class Shader;
class Camera {
 private:
  glm::vec3 eye = {10, 10, 10};
  glm::vec3 target = {0, 0, 0};
  glm::vec3 up = {0, 1, 0};
  glm::vec2 oldMousePos = {400, 300};
  std::vector<Shader *> shaders;
  float theta = 8.55;
  float phi = -2.39;
  float radius = 1;
  const float MOVEMENT_SPEED = 0.5f;
  const float MOUSE_SENSITIVITY = 0.02f;

  float horizontalAngle = 3.14f;
  // vertical angle : 0, look at the horizon
  float verticalAngle = 0.0f;
  // Initial Field of View
  float initialFoV = 45.0f;

  float speed = 3.0f;  // 3 units / second
  float mouseSpeed = 0.005f;
  float lastTime = 0;

 public:
  glm::mat4 viewMatrix;
  glm::mat4 projectionMatrix;
  Camera();
  ~Camera();
  void registerShader(Shader *shader);
  glm::mat4 getCameraLookAt();
  void notifyShaders();
  void adjustTarget(glm::vec2 newMousePos);
  void toFront();
  void toLeft();
  void toRight();
  void toBack();
};
#endif