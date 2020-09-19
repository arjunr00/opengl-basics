#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include <renderer/Texture.hpp>

/**
 * CONSTRUCTOR
 */
Texture::Texture(std::string const &filename) {
  // Load image data from file
  int width, height, numChannels;
  unsigned char *data = stbi_load(filename.c_str(), &width, &height, &numChannels, 0);

  if (!data) {
    std::cerr << "Could not load texture." << std::endl;
    return;
  }

  // Generate and bind texture object
  glGenTextures(1, &this->texture);
  glBindTexture(GL_TEXTURE_2D, this->texture);

  // Specify texture wrapping (using defaults)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  // Specify texture filtering (use nearest neighbor for both)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  // Generate actual texture from data
  glTexImage2D(
    GL_TEXTURE_2D /* Texture target */,
    0 /* Level of detail (for mipmapping) */,
    GL_RGB /* Number of color components in texture */,
    width /* Width of texture */,
    height /* Height of texture */,
    0 /* Border, unimportant (for legacy reasons?) */,
    GL_RGB /* Format of pixel data */,
    GL_UNSIGNED_BYTE /* Data type of pixel data */,
    data /* Pointer to image data in memory */
  );
  // Generate mipmap for texture automatically
  glGenerateMipmap(GL_TEXTURE_2D);

  // Free image memory
  stbi_image_free(data);
}

/**
 * PUBLIC METHODS
 */

unsigned int Texture::getTextureObjId() {
  return this->texture;
}
