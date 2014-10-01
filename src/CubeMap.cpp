#include <CubeMap.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>

#include <Assets.hpp>

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
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_tID);
	glActiveTexture(GL_TEXTURE0);
	struct imgData { unsigned char *data; long unsigned size; };

	vector<imgData> images =
	{
		{  right_png,  right_png_len },
		{   left_png,   left_png_len },
		{    top_png,    top_png_len },
		{    bot_png,    bot_png_len },
		{ middle_png, middle_png_len },
		{   back_png,   back_png_len }
	};

	int i = 0, w, h;
	for(auto image : images)
	{
		texData = SOIL_load_image_from_memory(image.data, image.size, &w, &h, nullptr, SOIL_LOAD_RGB);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i++, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);
		SOIL_free_image_data(texData);
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	m_uniModel = glGetUniformLocation(m_shader->getProgramid(),      "model");
	m_uniView  = glGetUniformLocation(m_shader->getProgramid(),       "view");
	m_uniProj  = glGetUniformLocation(m_shader->getProgramid(), "projection");

}
#include<iostream>
void CubeMap::draw(const Camera &cam)
{
	glDepthMask(false);
	glBindVertexArray(m_vao);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_tID);
	glUseProgram(m_shader->getProgramid());

	glUniformMatrix4fv(m_uniModel, 1, GL_FALSE, value_ptr(m_modelMatrix));
	glUniformMatrix4fv(m_uniView,  1, GL_FALSE, value_ptr(mat4(mat3(cam.getView())))); // pour enlever la composante de translation
	glUniformMatrix4fv(m_uniProj,  1, GL_FALSE, value_ptr(cam.getProjection()));

	glDrawArrays(GL_TRIANGLES, 0, vertNum);

	glBindVertexArray(0);
	glDepthMask(true);
}