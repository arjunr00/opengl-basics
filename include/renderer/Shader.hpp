#ifndef SHADER_H
#define SHADER_H

#include <fstream>
#include <vector>

class Shader {
  public:
    Shader(std::ifstream const &vertShaderFile, std::ifstream const &fragShaderFile);

    void setUniform(std::string name, std::vector<float> &values);
    void setUniform(std::string name, std::vector<int> &values);
    void setUniform(std::string name, std::vector<bool> &values);

    unsigned int getShaderProgramObjId();

  private:
    unsigned int shaderProgram;

    void compileShaders(const char *vertShaderSrc, const char *fragShaderSrc);
};

#endif /* #ifndef SHADER */
