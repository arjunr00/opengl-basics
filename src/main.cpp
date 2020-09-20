#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <renderer/Renderer.hpp>
#include <renderer/Mesh.hpp>

class RotatingMesh : public Mesh {
  public:
    RotatingMesh(std::vector<float> vertices, std::vector<unsigned int> indices,
              std::ifstream &vertShader, std::ifstream &fragShader,
              std::vector<std::string> const &textureFilepaths)
      : Mesh(vertices, indices, vertShader, fragShader, textureFilepaths) {};

    void update() override {
      this->rotate(glm::radians(1.0f), glm::vec3(0.5f, 1.0f, 0.0f));
    }
};

int main() {
  try {
    Renderer renderer("OpenGL Basics", 800, 600);

    /*         ===[ CUBE ]===
     *
     *        (7)------------(4)
     *        /|             /|
     *       / |            / |
     *      /  |           /  |
     *    (3)------------(1)  |
     *     |   |          |   |
     *     |  (6)---------|--(5)
     *     |  /           |  /
     *     | /            | /
     *     |/             |/
     *    (2)------------(0)
     *
     */
    std::vector<float> vertices = {
      // positions           // colors             // textures
       0.5f,  0.5f,  0.5f,    1.00f, 1.00f, 1.00f,   1.0f, 1.0f,  // front top right
       0.5f, -0.5f,  0.5f,    1.00f, 1.00f, 1.00f,   1.0f, 0.0f,  // front bottom right
      -0.5f, -0.5f,  0.5f,    1.00f, 1.00f, 1.00f,   0.0f, 0.0f,  // front bottom left
      -0.5f,  0.5f,  0.5f,    1.00f, 1.00f, 1.00f,   0.0f, 1.0f,  // front top left
       0.5f,  0.5f, -0.5f,    1.00f, 1.00f, 1.00f,   0.0f, 1.0f,  // back top right
       0.5f, -0.5f, -0.5f,    1.00f, 1.00f, 1.00f,   0.0f, 0.0f,  // back bottom right
      -0.5f, -0.5f, -0.5f,    1.00f, 1.00f, 1.00f,   1.0f, 0.0f,  // back bottom left
      -0.5f,  0.5f, -0.5f,    1.00f, 1.00f, 1.00f,   1.0f, 1.0f   // back top left
    };
    std::vector<unsigned int> indices = {
      0, 1, 3,   1, 2, 3, // front face
      0, 1, 4,   1, 4, 5, // right face
      0, 3, 4,   3, 4, 7, // top face
      2, 3, 6,   3, 6, 7, // left face
      1, 2, 6,   1, 5, 6, // bottom face
      5, 6, 7,   4, 5, 7  // back face
    };

    std::ifstream vertShader("./assets/shaders/basic.vert");
    std::ifstream fragShader("./assets/shaders/basic.frag");
    std::vector<std::string> textureFilepaths = {
      "./assets/textures/metal.jpg",
      "./assets/textures/laugh.png",
    };

    RotatingMesh cube1(vertices, indices, vertShader, fragShader, textureFilepaths);
    cube1.scale(glm::vec3(0.7f, 0.7f, 0.7f));
    cube1.rotate(30, glm::vec3(1.0f, 0.0f, 0.0f));
    cube1.translate(glm::vec3(-2.0f, 0.3f, -1.0f));
    RotatingMesh cube2(vertices, indices, vertShader, fragShader, textureFilepaths);
    cube2.translate(glm::vec3(0.0f, -0.2f, 1.0f));
    cube2.rotate(60, glm::vec3(0.0f, 1.0f, 0.0f));
    RotatingMesh cube3(vertices, indices, vertShader, fragShader, textureFilepaths);
    cube2.scale(glm::vec3(0.3f, 0.3f, 0.3f));
    cube3.translate(glm::vec3(1.0f, 0.5f, 0.0f));

    std::vector<Mesh *> meshes = {
      &cube1, &cube2, &cube3
    };

    renderer.render(meshes);
  } catch(std::exception const &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
