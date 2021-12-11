#include "CubeMap.hpp"
void CubeMap::useTexture(AbstractShader* shader) {
  glActiveTexture(textureUnitID);

  glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

  // Set texture unit to fragment shader
  GLint uniformID =
      glGetUniformLocation(shader->getShaderProgram(), "textureUnitID");
  glUniform1i(uniformID, textureUnitID);
}

void CubeMap::load(const char* posXFilename, const char* negXFilename,
                   const char* posYFilename, const char* negYFilename,
                   const char* posZFilename, const char* negZFilename) {
  textureID = SOIL_load_OGL_cubemap(posXFilename, negXFilename, posYFilename,
                                    negYFilename, posZFilename, negZFilename, 0,
                                    0, SOIL_FLAG_POWER_OF_TWO);
  printf("Skybox texture ID: %d \n", textureID);
}

CubeMap::CubeMap(const char* posXFilename, const char* negXFilename,
                 const char* posYFilename, const char* negYFilename,
                 const char* posZFilename, const char* negZFilename) {
  load(posXFilename, negXFilename, posYFilename, negYFilename, posZFilename,
       negZFilename);
}

CubeMap::~CubeMap() {}