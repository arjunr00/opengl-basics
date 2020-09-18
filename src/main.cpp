#include <iostream>
#include <fstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <renderer/Renderer.hpp>

int main() {
  Renderer renderer("OpenGL Tutorial", 800, 600);
  float vertices[] = {
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f
  };
  unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
  };
  std::ifstream vertShader("./src/shaders/basic.vert");
  std::ifstream fragShader("./src/shaders/basic.frag");

  Shape shapes[] = {
    Shape(vertices, 4, indices, 2, &vertShader, &fragShader)
  };

  try {
      renderer.render(shapes, 1);
  } catch(const std::exception& e) {
      std::cerr << e.what() << std::endl;
      return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
