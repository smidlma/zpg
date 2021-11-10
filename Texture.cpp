#include "Texture.hpp"

void Texture::useTexture(AbstractShader *shader) {
  // Bind the first texture to the first texture unit.
  glActiveTexture(GL_TEXTURE0);

  glBindTexture(GL_TEXTURE_2D, textureID);

  // Set texture unit to fragment shader
  GLint uniformID =
      glGetUniformLocation(shader->getShaderProgram(), "textureUnitID");
  glUniform1i(uniformID, 0);
}

Texture::Texture(const char *texturePath) {
  textureID = SOIL_load_OGL_texture(
      texturePath, SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

  printf("ID: %d \n", textureID);
}

Texture::~Texture() {}