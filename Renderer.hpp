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
    if (!scene->objects.empty()) {
      for (DrawableObject *o : scene->objects) {
        o->draw();
      }
    }
  }
};
#endif