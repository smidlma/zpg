#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H
#pragma once
#include <DrawableObject.hpp>
class MovableObject : public DrawableObject {
 private:
  glm::mat4 M = glm::mat4(1.0f);
  glm::mat4 A =
      glm::mat4(glm::vec4(-1.0, 3.0, -3.0, 1.0), glm::vec4(3.0, -6.0, 3.0, 0),
                glm::vec4(-3.0, 3.0, 0, 0), glm::vec4(1, 0, 0, 0));
  glm::mat4x3 B = glm::mat4x3(glm::vec3(0, 0, 0), glm::vec3(20, 0, 0),
                              glm::vec3(20, 0, 20), glm::vec3(0, 0, 20));
  float t = 0.5f;
  float delta = 0.005;

 public:
  MovableObject(AbstractModel *model, Transform *transform,
                AbstractShader *shader, Material *material);

  void setControlPoints(glm::mat4x3 controlPoints);
  void setSpeed(float speed);
  ~MovableObject();
  void draw();
};
#endif