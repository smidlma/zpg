#include "AbstractTexture.hpp"
unsigned int AbstractTexture::texturesCount = 0;
AbstractTexture::AbstractTexture() {
  textureUnitID = texturesCount;
  texturesCount++;
}

AbstractTexture::~AbstractTexture() {}