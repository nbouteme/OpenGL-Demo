#version 330 core

in vec2 TexCoords;
out vec4 color;

uniform sampler2D screenTexture;

const float offset = 1.0 / 400.0;

void main() {
	vec2 offsets[9] = vec2[](
        vec2(-offset, offset),  // top-left
        vec2(0.0f,    offset),  // top-center
        vec2(offset,  offset),  // top-right
        vec2(-offset, 0.0f),    // center-left
        vec2(0.0f,    0.0f),    // center-center
        vec2(offset,  0.0f),    // center-right
        vec2(-offset, -offset), // bottom-left
        vec2(0.0f,    -offset), // bottom-center
        vec2(offset,  -offset)  // bottom-right    
    );

	float kernel[9] = float[](
		1.0 / 16, 2.0 / 16, 1.0 / 16,
		2.0 / 16, 4.0 / 16, 2.0 / 16,
		1.0 / 16, 2.0 / 16, 1.0 / 16);

	vec3 sample[9];
    for(int i = 0; i < 9; i++)
        sample[i] = vec3(texture(screenTexture, TexCoords + offsets[i]));

    vec3 col = vec3(0.0);
    for(int i = 0; i < 9; i++)
        col += sample[i] * kernel[i];
	col = mix(col, vec3(texture(screenTexture, TexCoords)), 0.7 - length(TexCoords - vec2(0.5)));
    color = vec4(col, 1.0);
}
