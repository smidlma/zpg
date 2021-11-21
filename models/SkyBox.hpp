#ifndef SKYBOX_H
#define SKYBOX_H
#pragma once

#include <AbstractModel.hpp>


class SkyBox : public AbstractModel {
 private:
 public:
  SkyBox();
  void draw(AbstractShader *shader, Transform *transform) override;

  ~SkyBox();
};
#endif