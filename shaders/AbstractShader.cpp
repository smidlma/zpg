#include <AbstractShader.hpp>

AbstractShader::AbstractShader(std::vector<AbstractLight*> lights) {
  this->lights = lights;
}
AbstractShader::AbstractShader() {}

AbstractShader::~AbstractShader() {}