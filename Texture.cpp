#include "Texture.hpp"

void Texture::useTexture(AbstractShader *shader) {
  shader->setInt("textureUnitID", textureUnitID);
  // printf("########## %d ########### \n", textureUnitID);
}

Texture::Texture(std::string texturePath) {
  glActiveTexture(GL_TEXTURE0 + textureUnitID);
  textureID = SOIL_load_OGL_texture(
      texturePath.c_str(), SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y | SOIL_FLAG_TEXTURE_REPEATS);
  glBindTexture(GL_TEXTURE_2D, textureID);
  printf("Texture ID: %d Unit id: %d\n", textureID, textureUnitID);
}

Texture::~Texture() {}