#ifndef CUBEMAP_H
#define CUBEMAP_H
#pragma once
#include <SOIL/SOIL.h>
#include <AbstractShader.hpp>
#include <AbstractTexture.hpp>
class CubeMap : public AbstractTexture {
 private:
 public:
  CubeMap(const char* posXFilename, const char* negXFilename,
          const char* posYFilename, const char* negYFilename,
          const char* posZFilename, const char* negZFilename);

  void load(const char* posXFilename, const char* negXFilename,
            const char* posYFilename, const char* negYFilename,
            const char* posZFilename, const char* negZFilename);

  void useTexture(AbstractShader* shader);

  CubeMap();
  ~CubeMap();
};
#endif