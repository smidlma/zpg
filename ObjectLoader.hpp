#ifndef OBJECTLOADER_H
#define OBJECTLOADER_H
#pragma once

#include <GL/glew.h>
#include <assimp/postprocess.h>  // Post processingflags
#include <assimp/scene.h>        // aiSceneoutputdata structure

#include <DrawableObject.hpp>
#include <Material.hpp>
#include <Texture.hpp>
#include <Model.hpp>
#include <PhongShader.hpp>
#include <ConstantShader.hpp>
#include <assimp/Importer.hpp>  // C++ importerinterface
#include <glm/vec4.hpp>

class ObjectLoader {
 private:
 public:
  ObjectLoader();
  ~ObjectLoader();
  static DrawableObject* load(std::string fileName);
};
#endif