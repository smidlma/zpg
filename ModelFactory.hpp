#ifndef MODELFACTORY_H
#define MODELFACTORY_H
#pragma once

#include "ModelStruct.hpp"
#include "TriangleModel.hpp"
#include "models/SuziModel.hpp"


class ModelFactory {
 private:
  ModelFactory();

 public:
  // static TriangleModel *makeCube() {}
  static TriangleModel *makeTriangel() {
    std::vector<ModelStruct> data = {

        {{0.1f, 0.5f, 0.0f, 1}, {1, 0, 0, 1}},
        {{0.8f, 0.5f, 0.0f, 1}, {0, 1, 0, 1}},
        {{0.1f, 1.0f, 0.0f, 1}, {0, 0, 1, 1}},
    };

    return new TriangleModel(data);
  }
  static SuziModel *makeSuzi(){
    const float as[] = {1.0f,1.0f};
    return new SuziModel(as);
  }

  ~ModelFactory();
};
#endif