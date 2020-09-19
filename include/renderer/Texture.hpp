#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

class Texture {
  public:
    Texture(std::string const &filename);

    unsigned int getTextureObjId();

  private:
    unsigned int texture;
};

#endif /* #ifndef TEXTURE */
