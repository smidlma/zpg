#include "NormalTexture.hpp"

void NormalTexture::useTexture(AbstractShader *shader) {
  // printf("%d\n", textureUnitID);
  glActiveTexture(textureUnitID);

  glBindTexture(GL_TEXTURE_2D, textureID);

  GLint uniformID =
      glGetUniformLocation(shader->getShaderProgram(), "normalUnitID");
  if (uniformID == -1) {
    fprintf(stderr, "Texture unit Normal not found \n");
    // exit(1);
  }

  // glUseProgram(shader->getShaderProgram());
  glUniform1i(uniformID, textureUnitID);
  // glUseProgram(0);
}

NormalTexture::NormalTexture(std::string texturePath) {
  textureID = SOIL_load_OGL_texture(
      texturePath.c_str(), SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID,
      SOIL_FLAG_INVERT_Y | SOIL_FLAG_TEXTURE_REPEATS);

  printf("Normal Texture ID: %d \n", textureID);
}

NormalTexture::~NormalTexture() {}