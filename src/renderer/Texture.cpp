#include <iostream>
#include <string>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include <renderer/Texture.hpp>

/**
 * CONSTRUCTOR
 */
Texture::Texture(std::vector<std::string> const &filepaths)
  : textures(filepaths.size(), 0) {

  for (size_t i = 0; i < filepaths.size(); ++i) {
    glActiveTexture(GL_TEXTURE0 + i);
    this->loadTexture(filepaths[i], i);
  }
}

/**
 * PUBLIC METHODS
 */

size_t Texture::getNumTextures() {
  return this->textures.size();
}

unsigned int Texture::getTextureObjId(size_t index) {
  return this->textures[index];
}

void Texture::loadTexture(std::string filepath, size_t textureIndex) {
  // Load image data from file
  int width, height, numChannels;
  stbi_set_flip_vertically_on_load(true);
  unsigned char *data = stbi_load(filepath.c_str(), &width, &height, &numChannels, 0);

  if (!data) {
    std::cerr << "Could not load texture." << std::endl;
    return;
  }

  // Generate and bind texture object
  glGenTextures(1, &(this->textures[textureIndex]));
  glBindTexture(GL_TEXTURE_2D, this->textures[textureIndex]);

  // Specify texture wrapping (using defaults)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  // Specify texture filtering (use nearest neighbor for both)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  GLint pixelFormat;
  // Choose pixel format according to number of channels
  switch (numChannels) {
    case 3:
    default:
      pixelFormat = GL_RGB;
      break;
    case 4:
      pixelFormat = GL_RGBA;
      break;
  }

  // Generate actual texture from data
  glTexImage2D(
    GL_TEXTURE_2D /* Texture target */,
    0 /* Level of detail (for mipmapping) */,
    pixelFormat /* Number of color components in texture */,
    width /* Width of texture */,
    height /* Height of texture */,
    0 /* Border, unimportant (for legacy reasons?) */,
    pixelFormat /* Format of pixel data */,
    GL_UNSIGNED_BYTE /* Data type of pixel data */,
    data /* Pointer to image data in memory */
  );
  // Generate mipmap for texture automatically
  glGenerateMipmap(GL_TEXTURE_2D);

  // Free image memory
  stbi_image_free(data);
}
