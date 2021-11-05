#ifndef MODELFACTORY_H
#define MODELFACTORY_H
#pragma once

#include <PlainModel.hpp>
#include <SphereModel.hpp>
#include <SuziModel.hpp>
#include <TreeModel.hpp>

class ModelFactory {
 private:
  ModelFactory();

 public:
  static SuziModel *makeSuzi() { return new SuziModel(); }
  static SphereModel *makeSphere() { return new SphereModel(); }
  static PlainModel *makePlain() { return new PlainModel(); }
  static TreeModel *makeTree() { return new TreeModel(); }

  ~ModelFactory();
};
#endif