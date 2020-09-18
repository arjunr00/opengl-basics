#ifndef SHAPE_H
#define SHAPE_H

#include <cstddef>
#include <fstream>
#include <vector>

#include <renderer/Shader.hpp>

class Mesh {
  public:
    Mesh(std::vector<float> &vertices, std::vector<unsigned int> &indices,
          std::ifstream const &vertShaderFile, std::ifstream const &fragShaderFile);

    void draw();

  private:
    Shader shader;
    unsigned int vertArrObj;
    unsigned int vertBufObj;
    unsigned int elementBufObj;

    std::size_t numTriangles;
};

#endif /* #ifndef SHAPE */
