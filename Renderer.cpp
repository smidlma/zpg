#include <Renderer.hpp>

void Renderer::renderScene(Scene *scene) {
  if (!scene->objects.empty()) {
    int posLights = 0;
    for (auto *l : scene->lights) {
      // printf("\n %s \n", typeid(*l).name());
      // if(typeid( *l ).name())
      // l->useLight();
    }

    for (auto *o : scene->objects) {
      o->draw();
    }
  }
}
Renderer::Renderer() {}

Renderer::~Renderer() {}