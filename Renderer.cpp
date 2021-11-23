#include <Renderer.hpp>

void Renderer::renderScene(Scene *scene) {
  if (!scene->objects.empty()) {
    for (auto *o : scene->objects) {
      o->draw();
    }
    int posLights = 0;
    for (auto *l : scene->lights) {
      printf("\n %s \n", typeid(*l).name());
      // if(typeid( *l ).name())
      // l->useLight();
    }
    exit(0);
  }
}
Renderer::Renderer() {}

Renderer::~Renderer() {}