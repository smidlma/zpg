#include "Engine.hpp"
Engine *Engine::engine = nullptr;

Engine *Engine::getEngine() {
  if (engine) {
    engine = new Engine();
  }
  return engine;
}

Engine::Engine() {}

Engine::~Engine() {}