#version 330 core

in vec3 TexCoords;

out vec4 outColor;

uniform samplerCube map;

void main()
{    
    outColor = texture(map, TexCoords);
}
