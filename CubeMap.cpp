#include "CubeMap.hpp"
void CubeMap::useTexture(AbstractShader* shader) {
  // Set texture unit to fragment shader
  shader->setInt("textureUnitID", textureUnitID);
}

void CubeMap::load(const char* posXFilename, const char* negXFilename,
                   const char* posYFilename, const char* negYFilename,
                   const char* posZFilename, const char* negZFilename) {
  glActiveTexture(textureUnitID);

  textureID = SOIL_load_OGL_cubemap(posXFilename, negXFilename, posYFilename,
                                    negYFilename, posZFilename, negZFilename, 0,
                                    0, SOIL_FLAG_POWER_OF_TWO);
  glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
  printf("Skybox texture ID: %d Unit: %d \n", textureID, textureUnitID);
}

CubeMap::CubeMap(const char* posXFilename, const char* negXFilename,
                 const char* posYFilename, const char* negYFilename,
                 const char* posZFilename, const char* negZFilename) {
  load(posXFilename, negXFilename, posYFilename, negYFilename, posZFilename,
       negZFilename);
}

CubeMap::~CubeMap() {}