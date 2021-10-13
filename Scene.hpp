#ifndef SCENE_H
#define SCENE_H
#pragma once

#include <vector>

#include "Camera.hpp"
#include "Object.hpp"
#include "Shader.hpp"

class Scene {
 private:
  Camera *camera;
  std::vector<Object> objects;
  Shader *shader = new Shader();
  glm::mat4 projectionMatrix =
      glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
  glm::mat4 viewMatrix = glm::lookAt(
	glm::vec3(10, 10, 10), // Camera is at (4,3,-3), in World Space
	glm::vec3(0, 0, 0), // and looks at the origin
	glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);;

 public:
  Scene();
  ~Scene();
  void render();
};
#endif