// // #include <GL/glew.h>
// // // Include GLFW
// // #include <GLFW/glfw3.h>

// // Include GLM
// #include <glm/gtc/matrix_transform.hpp>  // glm::translate, glm::rotate, glm::scale, glm::perspective
// #include <glm/gtc/type_ptr.hpp>  // glm::value_ptr
// #include <glm/mat4x4.hpp>        // glm::mat4
// #include <glm/vec3.hpp>          // glm::vec3
// #include <glm/vec4.hpp>          // glm::vec4

// // Include the standard C++ headers
// #include <stdio.h>
// #include <stdlib.h>

#include "Engine.hpp"
float points[] = {0.0f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f};
float points2[] = {0.0f, 0.2f, 0.0f, 0.2f, -0.8f, 0.0f, -0.2f, -0.8f, 0.0f};

// const char* vertex_shader =
//     "#version 330\n"
//     "layout(location=0) in vec4 vp;"
//     "layout(location = 1) in vec4 color;"
//     "out vec4 vColor;"
//     "void main () {"
//     "     gl_Position = vp;"
//     "     vColor = color;"
//     "}";

// const char* fragment_shader =
//     "#version 330\n"
//     "in vec4 vColor;"
//     "out vec4 fColor;"
//     "void main () {"
//     "fColor = vColor;"
//     "}";

static void error_callback(int error, const char* description) {
  fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action,
                         int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
  printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

static void window_focus_callback(GLFWwindow* window, int focused) {
  printf("window_focus_callback \n");
}

static void window_iconify_callback(GLFWwindow* window, int iconified) {
  printf("window_iconify_callback \n");
}

static void window_size_callback(GLFWwindow* window, int width, int height) {
  printf("resize %d, %d \n", width, height);
  glViewport(0, 0, width, height);
}

static void cursor_callback(GLFWwindow* window, double x, double y) {
  printf("cursor_callback \n");
}

static void button_callback(GLFWwindow* window, int button, int action,
                            int mode) {
  if (action == GLFW_PRESS)
    printf("button_callback [%d,%d,%d]\n", button, action, mode);
}

// GLM test

// Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit
// <-> 100 units
// glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.01f, 100.0f);

// // Camera matrix
// glm::mat4 View = glm::lookAt(
//     glm::vec3(10, 10, 10),  // Camera is at (4,3,-3), in World Space
//     glm::vec3(0, 0, 0),     // and looks at the origin
//     glm::vec3(0, 1, 0)      // Head is up (set to 0,-1,0 to look upside-down)
// );
// // Model matrix : an identity matrix (model will be at the origin)
// glm::mat4 Model = glm::mat4(1.0f);

// struct ModelStruct {
//   float pos[4];
//   float rgba[4];
// };
// const ModelStruct b[] = {
//     {{-.5f, -.5f, .5f, 1}, {1, 0, 0, 1}},
//     {{-.5f, .5f, .5f, 1}, {0, 1, 0, 1}},
//     {{.5f, .5f, .5f, 1}, {0, 0, 1, 1}},
// };

int main(void) {
  // GLFWwindow* window;

  // glfwSetErrorCallback(error_callback);
  // if (!glfwInit()) {
  //   fprintf(stderr, "ERROR: could not start GLFW3\n");
  //   exit(EXIT_FAILURE);
  // }

  // /* //inicializace konkretni verze
  // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  // glfwWindowHint(GLFW_OPENGL_PROFILE,
  // GLFW_OPENGL_CORE_PROFILE);  //*/

  // window = glfwCreateWindow(800, 600, "ZPG", NULL, NULL);
  // if (!window) {
  //   glfwTerminate();
  //   exit(EXIT_FAILURE);
  // }

  // glfwMakeContextCurrent(window);
  // glfwSwapInterval(1);

  // // start GLEW extension handler
  // glewExperimental = GL_TRUE;
  // glewInit();

  // // get version info
  // printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
  // printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
  // printf("Vendor %s\n", glGetString(GL_VENDOR));
  // printf("Renderer %s\n", glGetString(GL_RENDERER));
  // printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
  // int major, minor, revision;
  // glfwGetVersion(&major, &minor, &revision);
  // printf("Using GLFW %i.%i.%i\n", major, minor, revision);

  // int width, height;
  // glfwGetFramebufferSize(window, &width, &height);
  // float ratio = width / (float)height;
  // glViewport(0, 0, width, height);

  // // Sets the key callback
  // //   glfwSetKeyCallback(window, key_callback);

  // //   glfwSetCursorPosCallback(window, cursor_callback);

  // //   glfwSetMouseButtonCallback(window, button_callback);

  // //   glfwSetWindowFocusCallback(window, window_focus_callback);

  // //   glfwSetWindowIconifyCallback(window, window_iconify_callback);

  // //   glfwSetWindowSizeCallback(window, window_size_callback);

  // // vertex buffer object (VBO)
  // GLuint VBO = 0;
  // glGenBuffers(1, &VBO);  // generate the VBO
  // glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // glBufferData(GL_ARRAY_BUFFER, sizeof(b), b, GL_STATIC_DRAW);

  // // 0, 3, GL_Float, 6*sizeof(GL_FLOAT), NULL
  // // 1,3,GL_FLOAT, 6 * sizeof(GL_Float),(GLvoid*)(3* sizeof (FL_FLOAT))
  // // Vertex Array Object (VAO)
  // GLuint VAO = 0;
  // glGenVertexArrays(1, &VAO);    // generate the VAO
  // glBindVertexArray(VAO);        // bind the VAO
  // glEnableVertexAttribArray(0);  // enable vertex attributes
  // glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // glEnableVertexAttribArray(0);
  // glEnableVertexAttribArray(1);
  // // glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(b[0]),
  // (GLvoid*)0);
  // // glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(b[0]),
  // (GLvoid*)5);

  // glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(b[0]), (GLvoid*)0);

  // glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(b[0]),
  //                       (GLvoid*)(4 * sizeof(GL_FLOAT)));

  // // create and compile shaders
  // GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  // glShaderSource(vertexShader, 1, &vertex_shader, NULL);
  // glCompileShader(vertexShader);
  // GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  // glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
  // glCompileShader(fragmentShader);
  // GLuint shaderProgram = glCreateProgram();
  // glAttachShader(shaderProgram, fragmentShader);
  // glAttachShader(shaderProgram, vertexShader);
  // glLinkProgram(shaderProgram);

  // GLint status;
  // glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
  // if (status == GL_FALSE) {
  //   GLint infoLogLength;
  //   glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
  //   GLchar* strInfoLog = new GLchar[infoLogLength + 1];
  //   glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, strInfoLog);
  //   fprintf(stderr, "Linker failure: %s\n", strInfoLog);
  //   delete[] strInfoLog;
  //   exit(EXIT_FAILURE);
  // }

  // while (!glfwWindowShouldClose(window)) {
  //   // clear color and depth buffer
  //   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //   glUseProgram(shaderProgram);
  //   glBindVertexArray(VAO);
  //   // draw triangles
  //   glDrawArrays(GL_TRIANGLES, 0, 3);  // mode,first,count
  //   // update other events like input handling
  //   glfwPollEvents();
  //   // put the stuff we’ve been drawing onto the display
  //   glfwSwapBuffers(window);
  // }
  // glfwDestroyWindow(window);

  // glfwTerminate();
  // exit(EXIT_SUCCESS);
  Engine* engine = Engine::getEngine();
  engine->run();
}