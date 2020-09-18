#include <fstream>
#include <iostream>
#include <sstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <renderer/Shader.hpp>

/**
 * CONSTRUCTOR
 */
Shader::Shader(std::ifstream const &vertShaderFile, std::ifstream const &fragShaderFile) {
  std::stringstream vertShaderSrcBuf, fragShaderSrcBuf;
  vertShaderSrcBuf << vertShaderFile.rdbuf();
  fragShaderSrcBuf << fragShaderFile.rdbuf();
  this->compileShaders(vertShaderSrcBuf.str().c_str(), fragShaderSrcBuf.str().c_str());
}

/**
 * PUBLIC METHODS
 */

unsigned int Shader::getShaderProgramObjId() {
  return this->shaderProgram;
}

/**
 * PRIVATE METHODS
 */

void Shader::compileShaders(const char *vertShaderSrc, const char *fragShaderSrc) {
  int success;
  char infoLog[512];

  // Compile vertex shader
  unsigned int vertShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertShader, 1, &vertShaderSrc, nullptr);
  glCompileShader(vertShader);

  // Check if vertex shader compilation were successful
  glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertShader, 512, nullptr, infoLog);
    std::cerr << "E: Could not compile vertex shader." << std::endl << infoLog << std::endl;
    std::cerr << vertShaderSrc << std::endl;
  }

  // Compile fragment shader
  unsigned int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragShader, 1, &fragShaderSrc, nullptr);
  glCompileShader(fragShader);

  // Check if fragment shader compilation were successful
  glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragShader, 512, nullptr, infoLog);
    std::cerr << "E: Could not compile fragment shader." << std::endl << infoLog << std::endl;
    std::cerr << fragShaderSrc << std::endl;
  }

  // Create shader program and link compiled shaders
  this->shaderProgram = glCreateProgram();
  glAttachShader(this->shaderProgram, vertShader);
  glAttachShader(this->shaderProgram, fragShader);
  glLinkProgram(this->shaderProgram);

  // Check if shader program link failed
  glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(this->shaderProgram, 512, nullptr, infoLog);
    std::cerr << "E: Could not link shaders." << std::endl << infoLog << std::endl;
  }

  // Clean up shader objects
  glDeleteShader(vertShader);
  glDeleteShader(fragShader);
}
