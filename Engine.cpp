#include <Engine.hpp>
#include <CallbackController.hpp>

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

  glEnable(GL_DEPTH_TEST);


  sceneManager = new SceneManager();
}

void Engine::setCallbacks() {
  glfwSetWindowSizeCallback(
      window, [](GLFWwindow *window, int width, int height) -> void {
        CallbackController::getInstance()->windowSizeChangeCallback(
            window, width, height);
      });

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

void Engine::run() {
  // init libs
  init();

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
  while (!glfwWindowShouldClose(window)) {
    // clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Renderer::renderScene(sceneManager->getCurrentScene());

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