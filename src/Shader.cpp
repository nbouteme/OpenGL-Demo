#include <Shader.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cassert>
#include <cstdlib>
#include <cstdio>

Shader::Shader(const char *vs, const char *ps, const char *gs)
{
	assert(vs);
	assert(ps);

	int status;

	m_vertexId = glCreateShader(GL_VERTEX_SHADER);
	m_pixelId  = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(m_vertexId, 1, &vs, nullptr);
	glShaderSource(m_pixelId , 1, &ps, nullptr);

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
}

void Shader::dumpShaderErrorLog(int shaderId)
{
	char buff[512] = { 0 };
	int lastSize;
	do
	{
		glGetShaderInfoLog(shaderId, 512, &lastSize, buff);
		printf("%s\n", buff);
	} while(lastSize == 511);
	abort();
}
