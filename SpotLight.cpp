#include "SpotLight.hpp"

void SpotLight::useLight(int index) {}

SpotLight::SpotLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,
                     AbstractShader *shader)
    : AbstractLight(ambient, diffuse, specular, shader) {}

SpotLight::SpotLight() {}

SpotLight::~SpotLight() {}