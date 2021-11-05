#include <stdio.h>
#include <stdlib.h>

#include <Engine.hpp>

int main(void) {
  Engine* engine = Engine::getEngine();
  engine->run();
}