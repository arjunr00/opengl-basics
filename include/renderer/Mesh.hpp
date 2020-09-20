#ifndef SHAPE_H
#define SHAPE_H

#include <cstddef>
#include <fstream>
#include <string>
#include <vector>

#include <glm/glm.hpp>

#include <renderer/Shader.hpp>
#include <renderer/Texture.hpp>

class Mesh {
  public:
    Mesh(std::vector<float> &vertices, std::vector<unsigned int> &indices,
          std::ifstream &vertShaderFile, std::ifstream &fragShaderFile,
          std::vector<std::string> const &textureFilenames);

    void preDraw();
    void draw();

    void translate(glm::vec3 vector);
    void rotate(float angle, glm::vec3 axis);
    void scale(glm::vec3 vector);

    virtual void update() {};

  protected:
    Shader shader;
    Texture texture;

  private:
    unsigned int vertArrObj;
    unsigned int vertBufObj;
    unsigned int elementBufObj;

    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;

    std::size_t numTriangles;
};

#endif /* #ifndef SHAPE */
