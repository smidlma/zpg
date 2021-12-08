#version 400
layout(location = 0)in vec3 position;
layout(location = 1)in vec3 normal;
layout(location = 2) in vec2 uv;

out vec3 fragmentPos;
out vec3 fragmentNormal;
out vec2 texCoords;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main(void)
{
    gl_Position = projectionMatrix*viewMatrix*modelMatrix*vec4(position, 1.0);
    fragmentNormal = normalize(transpose(inverse(mat3(modelMatrix))) * normal);
    fragmentPos = vec3(modelMatrix*vec4(position,1));
    texCoords = uv;
}