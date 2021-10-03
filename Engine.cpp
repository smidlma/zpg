#include "Engine.hpp"
Engine *Engine::engine = nullptr;

void Engine::run() {
  if (!glfwInit()) {
    fprintf(stderr, "ERROR: could not start GLFW3\n");
    exit(EXIT_FAILURE);
  }

  this->window = glfwCreateWindow(800, 600, "ZPG", NULL, NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);
  // start GLEW extension handler
  glewExperimental = GL_TRUE;
  glewInit();

  // get version info
  printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
  printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
  printf("Vendor %s\n", glGetString(GL_VENDOR));
  printf("Renderer %s\n", glGetString(GL_RENDERER));
  printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
  int major, minor, revision;
  glfwGetVersion(&major, &minor, &revision);
  printf("Using GLFW %i.%i.%i\n", major, minor, revision);

  int width, height;
  glfwGetFramebufferSize(window, &width, &height);
  float ratio = width / (float)height;
  glViewport(0, 0, width, height);

  // draw
  draw();

  glfwDestroyWindow(window);

  glfwTerminate();

  exit(EXIT_SUCCESS);
}
void Engine::draw() {
  std::vector<ModelStruct> model1 = {
      {{0.1f, 0.5f, 0.0f, 1}, {1, 0, 0, 1}},
      {{0.8f, -0.5f, 0.0f, 1}, {0, 1, 0, 1}},
      {{0.1f, -0.5f, 0.0f, 1}, {0, 0, 1, 1}},
  };

  Model *model = new Model(model1);
  Model *m2 = new Model({
      {{-0.1f, 0.5f, 0.0f, 1}, {1, 0, 0, 1}},
      {{-0.8f, -0.5f, 0.0f, 1}, {0, 1, 0, 1}},
      {{-0.1f, -0.5f, 0.0f, 1}, {0, 0, 1, 1}},
  });
  shader = new Shader();
  while (!glfwWindowShouldClose(window)) {
    // clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(shader->getShaderProgram());
    glBindVertexArray(model->getVAO());
    // draw triangles
    glDrawArrays(GL_TRIANGLES, 0, 3);  // mode,first,count
    // update other events like input handling

    // glUseProgram(shader->getShaderProgram());
    glBindVertexArray(m2->getVAO());
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwPollEvents();
    // put the stuff we’ve been drawing onto the display
    glfwSwapBuffers(window);
  }
}

Engine *Engine::getEngine() {
  if (!engine) {
    engine = new Engine();
  }
  return engine;
}

Engine::Engine() {}

Engine::~Engine() {}