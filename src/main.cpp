#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <renderer/Renderer.hpp>
#include <renderer/Mesh.hpp>

class TexturedMesh : public Mesh {
  public:
    TexturedMesh(std::vector<float> vertices, std::vector<unsigned int> indices,
              std::ifstream const &vertShader, std::ifstream const &fragShader,
              std::vector<std::string> const &textureFilepaths)
      : Mesh(vertices, indices, vertShader, fragShader, textureFilepaths) {};

    void configureShader() override {
      float time = glfwGetTime();
      std::vector<float> multipliers = { ((float) sin(2 * time)) * 0.25f + 0.75f };
      this->shader.setUniform("multiplier", multipliers);
    }
};

int main() {
  try {
    Renderer renderer("OpenGL Basics", 800, 600);
    std::vector<float> vertices = {
      // positions           // colors             // textures
       0.5f,  0.5f,  0.0f,    1.00f, 0.00f, 0.00f,   1.0f, 1.0f,  // top right
       0.5f, -0.5f,  0.0f,    0.00f, 0.70f, 0.00f,   1.0f, 0.0f,  // bottom right
      -0.5f, -0.5f,  0.0f,    0.00f, 0.70f, 0.00f,   0.0f, 0.0f,  // bottom left
      -0.5f,  0.5f,  0.0f,    1.00f, 0.00f, 0.00f,   0.0f, 1.0f   // top left
    };
    std::vector<unsigned int> indices = {
      0, 1, 3,
      1, 2, 3
    };
    std::ifstream vertShader("./assets/shaders/basic.vert");
    std::ifstream fragShader("./assets/shaders/basic.frag");
    std::vector<std::string> textureFilepaths = {
      "./assets/textures/metal.jpg",
      "./assets/textures/laugh.png",
    };

    TexturedMesh rect(vertices, indices, vertShader, fragShader, textureFilepaths);
    std::vector<Mesh *> meshes = { &rect };

    renderer.render(meshes);
  } catch(std::exception const &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
