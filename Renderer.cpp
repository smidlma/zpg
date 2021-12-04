#include <Renderer.hpp>

void Renderer::renderScene(Scene *scene) {
  if (!scene->objects.empty()) {
    glEnable(GL_STENCIL_TEST);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    for (auto *o : scene->objects) {
      glStencilFunc(GL_ALWAYS, o->getId(), 0xFF);
      for (int i = 0; i < scene->lights.size(); i++) {
        scene->lights[i]->useLight(i, o->getShader());
      }
      o->draw();
    }
  }
}
Renderer::Renderer() {}

Renderer::~Renderer() {}