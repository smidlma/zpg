#version 400
#define MAX_LIGHTS 10

struct Material {
  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
  float shininess;
};

struct Light {
  int isOn;
  int type;  // 1-point 2-spot 3-directional
  vec3 position;
  vec3 direction;
  float cutOff;
  float outerCutOff;
  float constant;
  float linear;
  float quadratic;

  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
};

uniform Material material;
uniform int lightsCount;
uniform Light lights[MAX_LIGHTS];
uniform vec3 viewPos;
uniform sampler2D textureUnitID;
uniform int isTexture;

in vec3 fragmentPos;
in vec3 fragmentNormal;
in vec2 texCoords;

out vec4 frag_colour;

vec3 calcLight(Light light, vec3 normal, vec3 fragPos, vec3 viewDir,
               Material material) {
 
  if (light.type == 1) {
    // Point l
    vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance +
                               light.quadratic * (distance * distance));
    // combine results
    vec3 ambient = light.ambient * material.ambient;
    vec3 diffuse = light.diffuse * diff * material.diffuse;
    vec3 specular = light.specular * spec * material.specular;
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
  } else if (light.type == 2) {
     if (light.isOn == 1) {
        return vec3(0, 0, 0);
      }
    // Spot l
    // Ambient
    vec3 ambient =
        light.ambient *
        material.ambient; 

    // Diffuse
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(light.position - fragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse =
        light.diffuse * diff *
        material.diffuse;  

    // Specular
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular =
        light.specular * spec *
        material.specular; 

    // Spotlight (soft edges)
    float theta = dot(lightDir, normalize(-light.direction));
    float epsilon = (light.cutOff - light.outerCutOff);
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
    diffuse *= intensity;
    specular *= intensity;
    specular *= intensity;

    // Attenuation
    float delta = length(light.position - fragPos);
    float attenuation = 1.0 / (1.0 + 0.09 * delta + 0.032 * (delta * delta));

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    return (ambient + diffuse + specular);

  } else if (light.type == 3) {
    // Directional
    vec3 lightDir = normalize(-light.direction);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // combine results
    vec3 ambient = light.ambient * material.ambient;
    vec3 diffuse = light.diffuse * diff * material.diffuse;
    vec3 specular = light.specular * spec * material.specular;
    return (ambient + diffuse + specular);
  }
}

void main(void) {
  // float specularStrength = 1;
  // vec3 lightPosition = vec3(0.0,5.0,0.0);
  // vec3 lightColor = vec3( 0.385, 0.647, 0.812);

  // vec3 lightColor = vec3( 0.685, 0.647, 0.812);
  // vec4 lightDir = normalize(vec4(lightPosition, 1) - fragmentPos);
  // float dot_product = max(dot(fragmentNormal, lightDir ), 0.0);
  // vec4 diffuse = dot_product * vec4(lightColor,1);
  // vec4 ambient = vec4( 0.1, 0.1, 0.1, 1.0);

  vec4 viewDir = normalize(vec4(viewPos, 1) - fragmentPos);
  // vec4 reflectDir = reflect(-lightDir, fragmentNormal);
  // float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128);
  // vec4 specular = specularStrength * spec * vec4(1,1,1,1);

  // vec3 result = lights[0].position;

  vec3 result = vec3(0, 0, 0);
  for (int i = 0; i < lightsCount; i++) {
    result += calcLight(lights[i], vec3(fragmentNormal.xyz),
                        vec3(fragmentPos.xyz), vec3(viewDir.xyz), material);
  }

  if (!all(equal(texCoords, vec2(0, 0)))) {
    frag_colour = texture(textureUnitID, texCoords) * vec4(result, 1);
  } else {
    frag_colour = vec4(result, 1);
  }
}
