#ifndef SHADER_H
#define SHADER_H

#include <fstream>

class Shader {
  public:
    Shader(std::ifstream *vertShaderFile, std::ifstream *fragShaderFile);

    void use();

  private:
    unsigned int shaderProgram;

    void compileShaders(const char *vertShaderSrc, const char *fragShaderSrc);
};

#endif /* #ifndef SHADER */
