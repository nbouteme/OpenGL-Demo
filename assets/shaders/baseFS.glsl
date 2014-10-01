#version 330 core

out vec4 outColor;

in	vec3 Normal;
in	vec3 Position; // Coordonnees espace-monde

uniform  vec3 viewPos;  // 'Position' de la camera


void main()
{
	vec3 ambientComponent = vec3(0.2f);
	vec3 diffuseComponent = vec3(0.5f); 
	vec3 specularComponent = vec3(0.5f); 
	vec3 lPos = vec3(2.0f, 3.0f, 1.0f);

	vec3 norm       = normalize(Normal);
    vec3 lightDir   = normalize(lPos    - Position);
    vec3 viewDir    = normalize(viewPos - Position);

    vec3 reflectDir = reflect(-lightDir, norm);
    
    float diffuse = max(dot(norm, lightDir), 0.0);
    diffuseComponent = diffuse * diffuseComponent;

	float specular = pow(max(dot(viewDir, reflectDir), 0.0), 128);
    specularComponent = specular * specularComponent;
    
    vec3 result = (ambientComponent + diffuseComponent + specularComponent);
    outColor = vec4(result, 1.0f);
}
