#version 400
#define MAX_POINT_LIGHTS 4


struct PointLight {    
    vec3 position;
    
    float constant;
    float linear;
    float quadratic;  

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct DirLight {
    vec3 direction;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};  


uniform DirLight dirLight;
uniform PointLight pointLights[MAX_POINT_LIGHTS];



in vec4 ex_worldPosition;
in vec4 ex_worldNormal;
out vec4 frag_colour;
uniform vec3 viewPos;
uniform vec3 lightPosition;
uniform vec3 lightColor;

vec3 calcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64);//material.shininess);
    // combine results
    vec3 ambient  = light.ambient;//  * vec3(texture(material.diffuse, TexCoords));
    vec3 diffuse  = light.diffuse  * diff;// * vec3(texture(material.diffuse, TexCoords));
    vec3 specular = light.specular * spec;// * vec3(texture(material.specular, TexCoords));
    return (ambient + diffuse + specular);
}  

vec3 calcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64);//material.shininess);
    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + 
  			     light.quadratic * (distance * distance));    
    // combine results
    vec3 ambient  = light.ambient  ;//* vec3(texture(material.diffuse, TexCoords));
    vec3 diffuse  = light.diffuse  * diff ;//* vec3(texture(material.diffuse, TexCoords));
    vec3 specular = light.specular * spec ;//* vec3(texture(material.specular, TexCoords));
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}

void main(void)
{
    float specularStrength = 1;
    //vec3 lightPosition = vec3(0.0,5.0,0.0);
    //vec3 lightColor = vec3( 0.385, 0.647, 0.812);

    //vec3 lightColor = vec3( 0.685, 0.647, 0.812);
    vec4 lightDir = normalize(vec4(lightPosition, 1) - ex_worldPosition);  
    float dot_product = max(dot(ex_worldNormal, lightDir ), 0.0);
    vec4 diffuse = dot_product * vec4(lightColor,1);
    vec4 ambient = vec4( 0.1, 0.1, 0.1, 1.0);

    vec4 viewDir = normalize(vec4(viewPos, 1) - ex_worldPosition);
    vec4 reflectDir = reflect(-lightDir, ex_worldNormal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128);
    vec4 specular = specularStrength * spec * vec4(1,1,1,1); 
    frag_colour = (ambient + diffuse + specular);
}

