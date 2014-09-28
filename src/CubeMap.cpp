#include <CubeMap.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>

extern unsigned char right_png[];
extern unsigned int  right_png_len;

extern unsigned char left_png[];
extern unsigned int  left_png_len;

extern unsigned char top_png[];
extern unsigned int  top_png_len;

extern unsigned char bot_png[];
extern unsigned int  bot_png_len;

extern unsigned char back_png[];
extern unsigned int  back_png_len;

extern unsigned char middle_png[];
extern unsigned int  middle_png_len;

extern char cube_obj[];
extern unsigned int cube_obj_len;

extern char cubemapFS_glsl[];
extern char cubemapVS_glsl[];
extern unsigned int cubemapFS_glsl_len;
extern unsigned int cubemapVS_glsl_len;

using namespace std;
using namespace glm;

CubeMap::CubeMap() :
	Model(string(cube_obj, cube_obj_len)),
	m_shader(make_shared<Shader>(string(cubemapVS_glsl, cubemapVS_glsl_len).c_str(), 
								 string(cubemapFS_glsl, cubemapFS_glsl_len).c_str()))
{
	// Chargement de Texture //
	unsigned char *texData = nullptr;

	glGenTextures(1, &m_tID);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_tID);

	// En mode -funroll-loops :^)
	int i = 0, w, h;

	texData = SOIL_load_image_from_memory(right_png, right_png_len, &w, &h, nullptr, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i++, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);

	texData = SOIL_load_image_from_memory(left_png, left_png_len, &w, &h, nullptr, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i++, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);

	texData = SOIL_load_image_from_memory(top_png, top_png_len, &w, &h, nullptr, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i++, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);

	texData = SOIL_load_image_from_memory(bot_png, bot_png_len, &w, &h, nullptr, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i++, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);

	texData = SOIL_load_image_from_memory(middle_png, middle_png_len, &w, &h, nullptr, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i++, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);

	texData = SOIL_load_image_from_memory(back_png, back_png_len, &w, &h, nullptr, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i++, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	////////////////////////////
	// Recup des uniform
	m_uniModel = glGetUniformLocation(m_shader->getProgramid(),      "model");
	m_uniView  = glGetUniformLocation(m_shader->getProgramid(),       "view");
	m_uniProj  = glGetUniformLocation(m_shader->getProgramid(), "projection");

	// Je crois que j'ai foirer un gros truc dans le repere depuis tout le debut mais je vais juste faire tourner ce foutu cube
}

void CubeMap::draw(const Camera &cam)
{
	glDepthMask(false);
	glBindVertexArray(m_vao);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_tID);
	glUseProgram(m_shader->getProgramid());

	glUniformMatrix4fv(m_uniModel, 1, GL_FALSE, value_ptr(m_modelMatrix));
	glUniformMatrix4fv(m_uniView,  1, GL_FALSE, value_ptr(mat4(mat3(cam.getView())))); // pour enlever la composante de translation
	glUniformMatrix4fv(m_uniProj,  1, GL_FALSE, value_ptr(cam.getProjection()));

	glDrawArrays(GL_TRIANGLES, 0, vertNum);

	glBindVertexArray(0);
	glDepthMask(true);
}
