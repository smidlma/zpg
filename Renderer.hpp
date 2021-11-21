#ifndef RENDERER_H
#define RENDERER_H
#pragma once

#include <Scene.hpp>

class Renderer {
 private:
 public:
  Renderer();
  ~Renderer();
  static void renderScene(Scene *scene) {
    for (DrawableObject *o : scene->objects) {
      o->draw();
    }
    }
};
#endif