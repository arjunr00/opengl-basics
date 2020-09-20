#include <cstdarg>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <renderer/Mesh.hpp>
#include <renderer/Texture.hpp>

/**
 * CONSTRUCTOR
 */
Mesh::Mesh(std::vector<float> &vertices, std::vector<unsigned int> &indices,
             std::ifstream &vertShaderFile, std::ifstream &fragShaderFile,
             std::vector<std::string> const &textureFilepaths)
    : shader(vertShaderFile, fragShaderFile),
      texture(textureFilepaths),
      model(1.0f),
      // TODO: parametrize these
      view(glm::translate(glm::mat4(10.f), glm::vec3(0.0f, 0.0f, -3.0f))),
      projection(glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f)),
      numTriangles(indices.size() / 3) {

  // Create vertex array object
  glGenVertexArrays(1, &(this->vertArrObj));
  // Create vertex buffer object
  glGenBuffers(1, &(this->vertBufObj));
  // Create element buffer object
  glGenBuffers(1, &(this->elementBufObj));

  // Bind vertex array
  glBindVertexArray(this->vertArrObj);

  // Copy vertex array into vertex buffer memory
  glBindBuffer(GL_ARRAY_BUFFER, this->vertBufObj);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

  // Copy vertex array into element buffer memory
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->elementBufObj);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

  // Define vertex data interpretation
  glVertexAttribPointer(
    0 /* Location of vertex attribute in shader */,
    3 /* Number of components in each attribute */,
    GL_FLOAT /* Data type of each component */,
    GL_FALSE /* Whether data should be normalized */,
    8 * sizeof(float) /* Byte offset between consecutive attributes */,
    (void *) 0 /* Offset of first component of first attribute in array */
  );
  glEnableVertexAttribArray(0);

  // Define vertex data interpretation
  glVertexAttribPointer(
    1 /* Location of vertex attribute in shader */,
    3 /* Number of components in each attribute */,
    GL_FLOAT /* Data type of each component */,
    GL_FALSE /* Whether data should be normalized */,
    8 * sizeof(float) /* Byte offset between consecutive attributes */,
    (void *)(3 * sizeof(float)) /* Offset of first component of first attribute in array */
  );
  glEnableVertexAttribArray(1);

  // Define vertex data interpretation
  glVertexAttribPointer(
    2 /* Location of vertex attribute in shader */,
    2 /* Number of components in each attribute */,
    GL_FLOAT /* Data type of each component */,
    GL_FALSE /* Whether data should be normalized */,
    8 * sizeof(float) /* Byte offset between consecutive attributes */,
    (void *)(6 * sizeof(float)) /* Offset of first component of first attribute in array */
  );
  glEnableVertexAttribArray(2);
}

/**
 * PUBLIC METHODS
 */

void Mesh::preDraw() {
  glUseProgram(this->shader.getShaderProgramObjId());
  for (size_t i = 0; i < this->texture.getNumTextures(); ++i) {
    std::string const texName = "tex" + std::to_string(i);
    this->shader.setUniform(texName, (int) i /* TODO: don't cast */);
  }
  this->shader.setView(this->view);
  this->shader.setProjection(this->projection);
}

void Mesh::draw() {
  glUseProgram(this->shader.getShaderProgramObjId());
  this->update();
  for (size_t i = 0; i < this->texture.getNumTextures(); ++i) {
    glActiveTexture(GL_TEXTURE0 + i);
    glBindTexture(GL_TEXTURE_2D, this->texture.getTextureObjId(i));
  }
  this->shader.setModel(this->model);
  glBindVertexArray(this->vertArrObj);
  glDrawElements(GL_TRIANGLES, this->numTriangles * 3, GL_UNSIGNED_INT, 0);
}

void Mesh::translate(glm::vec3 vector) {
  this->model = glm::translate(this->model, vector);
}

void Mesh::rotate(float angle, glm::vec3 axis) {
  this->model = glm::rotate(this->model, angle, axis);
}

void Mesh::scale(glm::vec3 vector) {
  this->model = glm::scale(this->model, vector);
}
