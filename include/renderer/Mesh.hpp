#ifndef SHAPE_H
#define SHAPE_H

#include <cstddef>
#include <fstream>
#include <string>
#include <vector>

#include <renderer/Shader.hpp>
#include <renderer/Texture.hpp>

class Mesh {
  public:
    Mesh(std::vector<float> &vertices, std::vector<unsigned int> &indices,
          std::ifstream const &vertShaderFile, std::ifstream const &fragShaderFile,
          std::vector<std::string> const &textureFilenames);

    void preDraw();
    void draw();
    virtual void configureShader() {};
    virtual void configureTexture() {};

  protected:
    Shader shader;
    Texture texture;

  private:
    unsigned int vertArrObj;
    unsigned int vertBufObj;
    unsigned int elementBufObj;

    std::size_t numTriangles;
};

#endif /* #ifndef SHAPE */
