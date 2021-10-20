#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H
#pragma once

#include "Shader.hpp"
#include "Transform.hpp"

class AbstractModel {
 protected:
  GLuint VAO = 0;

 public:
  virtual void draw(Shader *shader, Transform *transform) = 0;
};
#endif