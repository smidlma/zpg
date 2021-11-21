#version 400
layout(location = 0)in vec3 position;
layout(location = 1)in vec3 normal;
out vec4 ex_worldPosition;
out vec4 ex_worldNormal;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main(void)
{
gl_Position = projectionMatrix*viewMatrix*modelMatrix*vec4(position, 1.0);
ex_worldNormal = vec4(normalize(transpose(inverse(mat3(modelMatrix))) * normal), 1);
ex_worldPosition = modelMatrix*vec4(position, 1.0);
}