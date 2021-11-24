#ifndef MODEL_H
#define MODEL_H
#pragma once
#include <GL/glew.h>

#include <glm/vec4.hpp>
#include <assimp/postprocess.h>  // Post processingflags
#include <assimp/scene.h>        // aiSceneoutputdata structure
#include <assimp/Importer.hpp>  // C++ importerinterface

#include <AbstractModel.hpp>

class Model : public AbstractModel {
 private:
 public:
  Model(GLuint VAO, GLsizei indicesCount);
  ~Model();
  void draw(AbstractShader *shader, Transform *transform) override;
};
#endif