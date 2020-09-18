#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <renderer/Mesh.hpp>
#include <renderer/Renderer.hpp>
#include <renderer/Shader.hpp>

/**
 * CONSTRUCTOR 
 */
Renderer::Renderer(const char *windowName, int width, int height) {
  // Initialize window
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  this->window = glfwCreateWindow(width, height, windowName, nullptr, nullptr);
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

/**
 * DESTRUCTOR
 */
Renderer::~Renderer() {
  glfwTerminate();
}

/**
 * PUBLIC METHODS
 */

/** Render loop */
void Renderer::render(Mesh *meshes, std::size_t numMeshes) {

  while (!glfwWindowShouldClose(window)) {
    this->processInput();

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for (std::size_t i = 0; i < numMeshes; ++i)
      meshes[i].draw();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}

/**
 * PRIVATE METHODS
 */

/** (static) Window resize callback */
void Renderer::framebufferSizeCallback(GLFWwindow *window, int width, int height) {
  (void) window; // To suppress the unused parameter warning

  glViewport(0, 0, width, height);
}

void Renderer::processInput() {
  if (glfwGetKey(this->window, GLFW_KEY_Q) == GLFW_PRESS)
    glfwSetWindowShouldClose(this->window, true);
  else if (glfwGetKey(this->window, GLFW_KEY_1) == GLFW_PRESS)
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  else if (glfwGetKey(this->window, GLFW_KEY_2) == GLFW_PRESS)
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}
