#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <vector>

class Texture {
  public:
    Texture(std::vector<std::string> const &filepaths);

    size_t getNumTextures();
    unsigned int getTextureObjId(size_t index);

  private:
    std::vector<unsigned int> textures;

    void loadTexture(std::string filepath, size_t textureIndex);
};

#endif /* #ifndef TEXTURE */
