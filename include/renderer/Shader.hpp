#ifndef SHADER_H
#define SHADER_H

#include <fstream>
#include <vector>

#include <glm/glm.hpp>

class Shader {
  public:
    Shader(std::ifstream &vertShaderFile, std::ifstream &fragShaderFile);

    void setModel(glm::mat4 model);
    void setView(glm::mat4 view);
    void setProjection(glm::mat4 projection);

    void setUniform(std::string name, float value);
    void setUniform(std::string name, int value);
    void setUniform(std::string name, bool value);

    void setUniform(std::string name, std::vector<float> &values);
    void setUniform(std::string name, std::vector<int> &values);
    void setUniform(std::string name, std::vector<bool> &values);

    unsigned int getShaderProgramObjId();

  private:
    unsigned int shaderProgram;

    void compileShaders(const char *vertShaderSrc, const char *fragShaderSrc);
};

#endif /* #ifndef SHADER */
