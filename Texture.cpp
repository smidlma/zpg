#include "Texture.hpp"

void Texture::useTexture(AbstractShader *shader) {
  // printf("%d\n", textureUnitID);
  glActiveTexture(textureUnitID);

  glBindTexture(GL_TEXTURE_2D, textureID);
  GLint uniformID =
      glGetUniformLocation(shader->getShaderProgram(), "textureUnitID");
  if (uniformID == -1) {
    fprintf(stderr, "Texture unit not found \n");
    // exit(1);
  }
  glUniform1i(uniformID, textureUnitID);
}

Texture::Texture(std::string texturePath) {
  textureID = SOIL_load_OGL_texture(texturePath.c_str(), SOIL_LOAD_RGBA,
                                    SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y | SOIL_FLAG_TEXTURE_REPEATS);

  printf("Texture ID: %d \n", textureID);
}

Texture::~Texture() {}