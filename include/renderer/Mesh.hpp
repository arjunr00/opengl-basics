#ifndef SHAPE_H
#define SHAPE_H

#include <renderer/Shader.hpp>

#include <cstddef>
#include <fstream>

class Mesh {
  public:
    Mesh(float *vertices, std::size_t numVertices,
          unsigned int *indices, std::size_t numTriangles, 
          std::ifstream *vertShaderFile, std::ifstream *fragShaderFile);

    void draw();

  private:
    Shader shader;
    unsigned int vertArrObj;
    unsigned int vertBufObj;
    unsigned int elementBufObj;

    std::size_t numTriangles;
};

#endif /* #ifndef SHAPE */
