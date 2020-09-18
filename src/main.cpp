#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <renderer/Renderer.hpp>
#include <renderer/Mesh.hpp>

class ColorChangingMesh : public Mesh {
  public:
    ColorChangingMesh(std::vector<float> vertices, std::vector<unsigned int> indices,
              std::ifstream &vertShader, std::ifstream &fragShader)
      : Mesh(vertices, indices, vertShader, fragShader) {};

    void configureShader() override {
      float time = glfwGetTime();
      std::vector<float> multipliers = { ((float) sin(2 * time)) * 0.25f + 0.75f };
      this->shader.setUniform("multiplier", multipliers);
    }
};

int main() {
  Renderer renderer("OpenGL Basics", 800, 600);
  std::vector<float> vertices = {
     0.5f,  0.5f, 0.0f,    0.75f, 0.75f, 0.5f,
     0.5f, -0.5f, 0.0f,    0.75f, 0.25f, 0.5f,
    -0.5f, -0.5f, 0.0f,    0.25f, 0.25f, 0.5f,
    -0.5f,  0.5f, 0.0f,    0.25f, 0.75f, 0.5f,
  };
  std::vector<unsigned int> indices = {
    0, 1, 3,
    1, 2, 3
  };
  std::ifstream vertShader("./src/shaders/basic.vert");
  std::ifstream fragShader("./src/shaders/basic.frag");

  ColorChangingMesh rect(vertices, indices, vertShader, fragShader);
  std::vector<Mesh *> meshes = { &rect };

  try {
      renderer.render(meshes);
  } catch(const std::exception& e) {
      std::cerr << e.what() << std::endl;
      return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
