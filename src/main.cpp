#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <renderer/Renderer.hpp>

int main() {
  Renderer renderer("OpenGL Tutorial", 800, 600);

  try {
      renderer.render();
  } catch(const std::exception& e) {
      std::cerr << e.what() << std::endl;
      return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
