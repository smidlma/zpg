#include <Renderer.hpp>

void Renderer::renderScene(Scene *scene) {
  if (!scene->objects.empty()) {
    glEnable(GL_STENCIL_TEST);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    for (auto *o : scene->objects) {
      glStencilFunc(GL_ALWAYS, o->getId(), 0xFF);
      
      glUseProgram(o->getShader()->getShaderProgram());
      glUniform1i(glGetUniformLocation(o->getShader()->getShaderProgram(),
                                       "lightsCount"),
                  scene->lights.size());
      glUseProgram(0);

      for (int i = 0; i < scene->lights.size(); i++) {
        scene->lights[i]->useLight(i, o->getShader());
      }
      o->draw();
    }
  }
}
Renderer::Renderer() {}

Renderer::~Renderer() {}