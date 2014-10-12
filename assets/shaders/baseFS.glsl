#version 330 core

out vec4 outColor;

in	vec3 Normal;
in	vec3 Position; // Coordonnees espace-monde
in  mat4 Model;

uniform  vec3 viewPos;  // 'Position' de la camera

void main()
{
	vec3 ambientComponent = vec3(0.2f);
	vec3 diffuseComponent = vec3(0.5f); 
	vec3 specularComponent = vec3(0.5f); 

	vec3 lPos = vec3(2.0f, 3.0f, 1.0f);// Position de la lumiere

	vec3 norm       = normalize(Normal);
    vec3 lightDir   = normalize(lPos    - Position); // Direction du rayon de lumiere
    vec3 viewDir    = normalize(viewPos - Position); // Direction du rayon de vue

    vec3 reflectDir = reflect(-lightDir, norm); // direction lumiere reflechie
    
    float diffuse  =     max(dot(   norm,   lightDir), 0.0); // composante diffuse
	float specular = pow(max(dot(viewDir, reflectDir), 0.0), 128); // composante speculaire

    diffuseComponent = diffuse * diffuseComponent;
    specularComponent = specular * specularComponent;

    vec3 result = (ambientComponent + diffuseComponent + specularComponent);
    outColor = vec4(result, 1.0f);
}
