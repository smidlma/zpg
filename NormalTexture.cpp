#include "NormalTexture.hpp"

void NormalTexture::useTexture(AbstractShader *shader) {
  // shader->setInt("normalUnitID", textureUnitID);
}

NormalTexture::NormalTexture(std::string texturePath) {
  // glActiveTexture(textureUnitID);
  // textureID = SOIL_load_OGL_texture(
  //     texturePath.c_str(), SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID,
  //     SOIL_FLAG_INVERT_Y | SOIL_FLAG_TEXTURE_REPEATS);

  // glBindTexture(GL_TEXTURE_2D, textureID);
  printf("Normal Texture ID: %d \n", textureID);
}

NormalTexture::~NormalTexture() {}