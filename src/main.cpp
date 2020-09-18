#include <iostream>
#include <fstream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <renderer/Renderer.hpp>
#include <renderer/Mesh.hpp>

int main() {
  Renderer renderer("OpenGL Tutorial", 800, 600);
  std::vector<float> vertices = {
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f
  };
  std::vector<unsigned int> indices = {
    0, 1, 3,
    1, 2, 3
  };
  std::ifstream vertShader("./src/shaders/basic.vert");
  std::ifstream fragShader("./src/shaders/basic.frag");

  Mesh meshes[] = {
    Mesh(vertices, indices, vertShader, fragShader)
  };

  try {
      renderer.render(meshes, 1);
  } catch(const std::exception& e) {
      std::cerr << e.what() << std::endl;
      return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
