#include <Light.hpp> 
	
Light::Light(glm::vec3 pos, glm::vec3 col)
{
	position = pos;
    color = col;
}
	
Light::~Light()
{
	
}