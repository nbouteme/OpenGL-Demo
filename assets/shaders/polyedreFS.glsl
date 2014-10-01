#version 330 core

out vec4 outColor;

in	vec3 Normal;
in	vec3 Position; // Coordonnees espace-monde

uniform  vec3 viewPos;
uniform  samplerCube cubeMap;

void main()
{
	vec3 ambientComponent = vec3(0.2, 0.2, 0.8);
	vec3 diffuseComponent = vec3(0.5);
	vec3 specularComponent = vec3(0.5);

	vec3 lPos = vec3(2.0, 3.0, 1.0);// position lumiere espace local (?)

	vec3 norm       = normalize(Normal);

    vec3 lightDir   = normalize(lPos    - Position);// direction de la lumiere relative au point
    vec3 viewDir    = normalize(viewPos - Position);// direction de la vue relative a la camera

    vec3 reflectDir = reflect(-lightDir, norm);
    
    float diffuse = max(dot(norm, lightDir), 0.0); // varie entre 1 et 0 (1 = direction lumiere perpendiculaire a la face, 0 = nop)
    diffuseComponent = diffuse * diffuseComponent;

	float specular = pow(max(dot(viewDir, reflectDir), 0.0), 128); // au plus l'angle entre le rayon de lumiere emit et le rayon du fragment sont proche, plus le fragment est illumine
    specularComponent = specular * specularComponent;
    
    vec3 result = (ambientComponent + diffuseComponent + specularComponent);

	vec3 reflection = reflect(viewDir, normalize(Normal));
	vec3 refraction = refract(viewDir, normalize(Normal), 1.0 / 1.33); // 1.33 =  indice de refraction de l'eau

    outColor = vec4(result, 1.0);
	outColor *= texture(cubeMap, refraction) * 0.9;
	outColor +=	texture(cubeMap, reflection) * 0.1;
}
