#include "Renderer.hpp"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

/** Construcor */
Renderer::Renderer() {
  // Initialize window
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  this->window = glfwCreateWindow(800, 600, "OpenGL Tutorial", nullptr, nullptr);
  if (this->window == nullptr) {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return;
  }
  glfwMakeContextCurrent(this->window);

  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
    std::cerr << "Failed to initialize GLAD" << std::endl;
    return;
  }

  glViewport(0, 0, 800, 600);
  
  glfwSetFramebufferSizeCallback(this->window, this->framebufferSizeCallback);
}

/** Destructor */
Renderer::~Renderer() {
  glfwTerminate();
}

/** Render loop */
void Renderer::render() {
  while (!glfwWindowShouldClose(window)) {
    this->processInput();

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}

/** (static) Window resize callback */
void Renderer::framebufferSizeCallback(GLFWwindow *window, int width, int height) {
  (void) window; // To suppress the unused parameter warning

  glViewport(0, 0, width, height);
}

void Renderer::processInput() {
  if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(this->window, true);
}
