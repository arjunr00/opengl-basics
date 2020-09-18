#ifndef SHAPE_H
#define SHAPE_H

#include <cstddef>
#include <fstream>
#include <string>
#include <vector>

#include <renderer/Shader.hpp>

class Mesh {
  public:
    Mesh(std::vector<float> &vertices, std::vector<unsigned int> &indices,
          std::ifstream const &vertShaderFile, std::ifstream const &fragShaderFile);

    void draw();
    virtual void configureShader() {};

  protected:
    Shader shader;

  private:
    unsigned int vertArrObj;
    unsigned int vertBufObj;
    unsigned int elementBufObj;

    std::size_t numTriangles;
};

#endif /* #ifndef SHAPE */
