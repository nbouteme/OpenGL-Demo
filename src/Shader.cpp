#include <Shader.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>

extern char baseFS_glsl[]; // Code source des shader
extern char baseVS_glsl[];

extern unsigned int baseFS_glsl_len; // leurs tailles
extern unsigned int baseVS_glsl_len;

using namespace std;

Shader::Shader(const char *vs, const char *ps, const char *gs)
{
	int status;

	m_vertexId = glCreateShader(GL_VERTEX_SHADER);
	m_pixelId  = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(m_vertexId, 1, &vs, nullptr);
	glShaderSource(m_pixelId , 1, &ps, nullptr);

	/*
	 * Le pilote libre d'intel a l'air de leaker 5 octets a
	 * chaque appel de glCompileShader...
	 */
	glCompileShader(m_vertexId);
	glGetShaderiv(m_vertexId, GL_COMPILE_STATUS, &status);
	if(!status)
		dumpShaderErrorLog(m_vertexId);

	glCompileShader(m_pixelId);
	glGetShaderiv(m_pixelId, GL_COMPILE_STATUS, &status);
	if(!status)
		dumpShaderErrorLog(m_pixelId);

	m_shaderId = glCreateProgram();

	if(gs)
	{
		m_geometryId = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(m_geometryId, 1, &ps, nullptr);
		glCompileShader(m_geometryId);
		glGetShaderiv(m_geometryId, GL_COMPILE_STATUS, &status);
		if(!status)
			dumpShaderErrorLog(m_geometryId);
		glAttachShader(m_shaderId, m_geometryId);
	}

	glAttachShader(m_shaderId, m_vertexId);
	glAttachShader(m_shaderId, m_pixelId);

	glBindFragDataLocation(m_shaderId, 0, "outColor");
	glLinkProgram(m_shaderId);

	glGetProgramiv(m_shaderId, GL_LINK_STATUS, &status);
	if(!status)
		assert(false);
}

void Shader::dumpShaderErrorLog(int shaderId)
{
	char buff[512] = { 0 };
	int lastSize;
	do
	{
		glGetShaderInfoLog(shaderId, 512, &lastSize, buff);
		printf("%s", buff); // Pas vraiment sur si le decoupage est correcte, 
		                    //j'ai jamais eu d'erreur de plus de 512 caracteres.
	} while(lastSize == 511);
	puts("");

	abort();
}

Shader::~Shader()
{
	glDeleteShader(m_vertexId);
	glDeleteShader(m_pixelId);

	if(m_geometryId != -1)
		glDeleteShader(m_geometryId);

	glDeleteShader(m_vertexId);
	glDeleteShader(m_pixelId);

	glDeleteProgram(m_shaderId);
}

shared_ptr<Shader> Shader::BasicShader()
{
	return make_shared<Shader>(string(baseVS_glsl, baseVS_glsl_len).c_str(),
							   string(baseFS_glsl, baseFS_glsl_len).c_str());
}
