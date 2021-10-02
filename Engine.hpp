#ifndef ENGINE_H
#define ENGINE_H
#pragma once

class Engine {
 private:
  static Engine *engine;
  Engine();

 public:
	static Engine* getEngine();
  ~Engine();
  void run();
};
#endif