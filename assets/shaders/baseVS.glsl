#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uv;
layout (location = 2) in vec3 normal;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

out vec3 Normal;
out vec3 Position; // Coordonnees espace-monde
out mat4 Model;

void main()
{
	Normal = transpose(inverse(mat3(model))) * normal;
	Model = model;
	Position = vec3(model * vec4(position, 1.0f));
	gl_Position = projection * view * model * vec4(position, 1.0);
}
