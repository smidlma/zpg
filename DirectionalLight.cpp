#include "DirectionalLight.hpp"

DirectionalLight::DirectionalLight(glm::vec3 ambient, glm::vec3 diffuse,
                                   glm::vec3 specular)
    : AbstractLight(ambient, diffuse, specular) {}

DirectionalLight::~DirectionalLight() {}