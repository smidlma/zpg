#version 400
#define MAX_LIGHTS 2


struct Light{
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

uniform Light lights[MAX_LIGHTS];
// uniform int lightsCount;
uniform vec3 viewPos;

in vec4 fragmentPos;
in vec4 fragmentNormal;

out vec4 frag_colour;


vec3 calcLight(Light light, vec3 normal, vec3 fragPos, vec3 viewDir){
  
    if(!all(equal(light.position, vec3(0,0,0)))){
       
        // Is spot or point
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
        if(!all(equal(light.direction,vec3(0,0,0)))){
            
            // IS SPOT
            // spotlight intensity
            float theta = dot(lightDir, normalize(-light.direction)); 
            float epsilon = light.cutOff - light.outerCutOff;
            float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
            // combine results
            vec3 ambient = light.ambient ;//* vec3(texture(material.diffuse, TexCoords));
            vec3 diffuse = light.diffuse * diff;// * vec3(texture(material.diffuse, TexCoords));
            vec3 specular = light.specular * spec;// * vec3(texture(material.specular, TexCoords));
            ambient *= attenuation * intensity;
            diffuse *= attenuation * intensity;
            specular *= attenuation * intensity;
            return (ambient + diffuse + specular);
        }else{
            // IS POINT
            // combine results
            vec3 ambient  = light.ambient;//* vec3(texture(material.diffuse, TexCoords));
            vec3 diffuse  = light.diffuse  * diff ;//* vec3(texture(material.diffuse, TexCoords));
            vec3 specular = light.specular * spec ;//* vec3(texture(material.specular, TexCoords));
            ambient  *= attenuation;
            diffuse  *= attenuation;
            specular *= attenuation;
            return (ambient + diffuse + specular);
        }
                   
    }else{
         
        // Is dir
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
}

void main(void)
{
    // float specularStrength = 1;
    //vec3 lightPosition = vec3(0.0,5.0,0.0);
    //vec3 lightColor = vec3( 0.385, 0.647, 0.812);

    //vec3 lightColor = vec3( 0.685, 0.647, 0.812);
    // vec4 lightDir = normalize(vec4(lightPosition, 1) - fragmentPos);  
    // float dot_product = max(dot(fragmentNormal, lightDir ), 0.0);
    // vec4 diffuse = dot_product * vec4(lightColor,1);
    // vec4 ambient = vec4( 0.1, 0.1, 0.1, 1.0);

    vec4 viewDir = normalize(vec4(viewPos, 1) - fragmentPos);
    // vec4 reflectDir = reflect(-lightDir, fragmentNormal);
    // float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128);
    // vec4 specular = specularStrength * spec * vec4(1,1,1,1); 

    // vec3 result = lights[0].position;
    
    vec3 result = vec3(0,0,0);
    for(int i = 0; i < MAX_LIGHTS; i++){
        result+=calcLight(lights[i], vec3(fragmentNormal.xyz), vec3(fragmentPos.xyz), vec3(viewDir.xyz) );
    }

    frag_colour = vec4(result,1);
}

