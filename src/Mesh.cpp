#include <cstddef>
#include <fstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <renderer/Mesh.hpp>

/**
 * CONSTRUCTOR
 */
Mesh::Mesh(float *vertices, std::size_t numVertices,
             unsigned int *indices, std::size_t numTriangles,
             std::ifstream *vertShaderFile, std::ifstream *fragShaderFile)
    : shader(vertShaderFile, fragShaderFile), numTriangles(numTriangles) {

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
  glBufferData(GL_ARRAY_BUFFER, numVertices * 3 * sizeof(float), vertices, GL_STATIC_DRAW);

  // Copy vertex array into element buffer memory
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->elementBufObj);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, numTriangles * 3 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

  // Define vertex data interpretation
  glVertexAttribPointer(
    0 /* Location of vertex attribute in shader */,
    3 /* Number of components in each attribute */,
    GL_FLOAT /* Data type of each component */,
    GL_FALSE /* Whether data should be normalized */,
    3 * sizeof(float) /* Byte offset between consecutive attributes */,
    (void *) 0 /* Offset of first component of first attribute in array */
  );
  glEnableVertexAttribArray(0);
}

/**
 * PUBLIC METHODS
 */

void Mesh::draw() {
  glUseProgram(this->shader.getShaderProgramObjId());
  glBindVertexArray(this->vertArrObj);
  glDrawElements(GL_TRIANGLES, this->numTriangles * 3, GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
}
