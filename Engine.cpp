#include "Engine.hpp"
Engine *Engine::engine = nullptr;

void Engine::init() {
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
  glewExperimental = GL_TRUE;  // Ensure it get all pointers
  if (GLEW_OK != glewInit()) {
    // glewInit failed, something is seriously wrong.
    fprintf(stderr, "Error to init glew\n");
    exit(1);  // or any handling here
  }

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
}

void Engine::setCallbacks() {
  glfwSetCursorPosCallback(
      window,
      [](GLFWwindow *window, double mouseXPos, double mouseYPos) -> void {
        CallbackController::getInstance()->cursorPosCallback(window, mouseXPos,
                                                             mouseYPos);
      });
  glfwSetKeyCallback(window,
                     [](GLFWwindow *window, int key, int scancode, int action,
                        int mods) -> void {
                       CallbackController::getInstance()->keyCallback(
                           window, key, scancode, action, mods);
                     });
}
void Engine::initScene() {
  scene = new Scene();
  AbstractModel *model = ModelFactory::makeTriangel();
  Transform *tr1 = new Transform();
  Transform *tr = new Transform();
  tr->scale(2);
  tr->translate({0, 2, 0});
  Shader *s = new Shader();

   // for (int i = 0; i < 10; i++) {
  scene->addObject(new DrawableObject(model, tr, s));
  scene->addObject(new DrawableObject(model, tr1,s));

  // }
}

void Engine::run() {
  // init libs
  init();
  initScene();

  // set callbacks
  setCallbacks();

  // draw
  draw();

  // terminate
  glfwDestroyWindow(window);
  glfwTerminate();
  exit(EXIT_SUCCESS);
}
void Engine::draw() {
  // shader = new Shader();

  // std::vector<ModelStruct> model1 = {

  //     {{0.1f, 0.5f, 0.0f, 1}, {1, 0, 0, 1}},
  //     {{0.8f, 0.5f, 0.0f, 1}, {0, 1, 0, 1}},
  //     {{0.1f, 1.0f, 0.0f, 1}, {0, 0, 1, 1}},
  // };

  // Model *model = new Model(model1, shader);
  // Model *m2 = new Model(
  //     {
  //         {{0.1f, 0.5f, 0.0f, 1}, {1, 0, 0, 1}},
  //         {{0.8f, -0.5f, 0.0f, 1}, {0, 1, 0, 1}},
  //         {{0.1f, -0.5f, 0.0f, 1}, {0, 0, 1, 1}},
  //         {{-0.1f, 0.5f, 0.5f, 1}, {1, 0, 0, 1}},
  //         {{-0.8f, -0.5f, 0.5f, 1}, {0, 1, 0, 1}},
  //         {{-0.1f, -0.5f, 0.5f, 1}, {0, 0, 1, 1}},
  //     },
  //     shader);
  // float angle = 0;
  // float myView = 0;
  while (!glfwWindowShouldClose(window)) {
    // clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // model->rotate(angle);
    // model->scale(angle / 100);
    // model->setForRender();

    // m2->setForRender();

    // model->transalte(0.8);
    // model->setForRender();

    scene->render();

    glfwPollEvents();
    // put the stuff we’ve been drawing onto the display
    glfwSwapBuffers(window);
    // angle += 0.1;
  }
}

Engine *Engine::getEngine() {
  if (!engine) {
    engine = new Engine();
  }
  return engine;
}

Scene *Engine::getScene() { return scene; }

Engine::Engine() {}

Engine::~Engine() {}