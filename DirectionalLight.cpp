#include "DirectionalLight.hpp"
void DirectionalLight::useLight(int index) {}

DirectionalLight::DirectionalLight(glm::vec3 ambient, glm::vec3 diffuse,
                                   glm::vec3 specular, AbstractShader *shader)
    : AbstractLight(ambient, diffuse, specular, shader) {}

DirectionalLight::~DirectionalLight() {}
