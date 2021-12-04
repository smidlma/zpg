#version 400
layout(location = 0)in vec3 position;
layout(location = 1)in vec3 normal;
layout(location = 2) in vec2 uv;

out vec4 fragmentPos;
out vec4 fragmentNormal;
out vec2 texCoords;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main(void)
{
    gl_Position = projectionMatrix*viewMatrix*modelMatrix*vec4(position, 1.0);
    fragmentNormal = vec4(normalize(transpose(inverse(mat3(modelMatrix))) * normal), 1);
    fragmentPos = modelMatrix*vec4(position, 1.0);
    texCoords = uv;
}