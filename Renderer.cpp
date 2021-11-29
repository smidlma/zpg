#include <Renderer.hpp>

void Renderer::renderScene(Scene *scene) {
  if (!scene->objects.empty()) {
    glEnable(GL_STENCIL_TEST);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
    for (auto *o : scene->objects) {
      for (int i = 0; i < scene->lights.size(); i++) {
        scene->lights[i]->useLight(i);
      }
      glStencilFunc(GL_ALWAYS, o->getId(), 0xFF);
      o->draw();

      //  glStencilFunc(GL_ALWAYS, 0, 0xFF);
    }
  }
}
Renderer::Renderer() {}

Renderer::~Renderer() {}