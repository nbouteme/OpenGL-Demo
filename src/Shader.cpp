#include <Shader.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>

#include <Assets.hpp>
#include <Application.hpp>

using namespace std;

Shader::Shader(const char *vs, const char *ps, const char *gs)
{
	int status;

	// Crée des shader
	m_vertexId = glCreateShader(GL_VERTEX_SHADER);
	m_pixelId  = glCreateShader(GL_FRAGMENT_SHADER);

	// Fournis leur code source
	glShaderSource(m_vertexId, 1, &vs, nullptr);
	glShaderSource(m_pixelId , 1, &ps, nullptr);

	Application::Log("Compiling Shaders", Logger::Debug);
	// Compile le vertex shader
	glCompileShader(m_vertexId);
	// Recupere le status de la compilation
	glGetShaderiv(m_vertexId, GL_COMPILE_STATUS, &status);
	if(!status) // En cas d'erreur on affiche la liste d'erreurs et on génère un coredump
	{
		Application::Log("Vertex Shader failed to compile", Logger::Critical);
		dumpShaderErrorLog(m_vertexId);
	}

	glCompileShader(m_pixelId);
	glGetShaderiv(m_pixelId, GL_COMPILE_STATUS, &status);

	if(!status)
	{
		Application::Log("Fragment Shader failed to compile", Logger::Critical);
		dumpShaderErrorLog(m_pixelId);
	}

	m_shaderId = glCreateProgram();

	if(gs) // si un geometry shader a été fourni
	{
		m_geometryId = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(m_geometryId, 1, &ps, nullptr);
		glCompileShader(m_geometryId);
		glGetShaderiv(m_geometryId, GL_COMPILE_STATUS, &status);
		if(!status)	
		{
			Application::Log("Geometry Shader failed to compile", Logger::Debug);
			dumpShaderErrorLog(m_geometryId);
		}
		glAttachShader(m_shaderId, m_geometryId);
	}

	glAttachShader(m_shaderId, m_vertexId);
	glAttachShader(m_shaderId, m_pixelId);

	// Donne le nom de la variable de sortie de la pipeline
	glBindFragDataLocation(m_shaderId, 0, "outColor");

	// Lie le programme
	glLinkProgram(m_shaderId);

	glGetProgramiv(m_shaderId, GL_LINK_STATUS, &status);
	if(!status)
		Application::Log("Shader failed to link", Logger::Critical);
	assert(status); // Génère un coredump en cas de probleme.
}

void Shader::dumpShaderErrorLog(int shaderId)
{
	char buff[512] = { 0 };
	int lastSize;
	do
	{
		glGetShaderInfoLog(shaderId, 511, &lastSize, buff);
		printf("%s", buff); // Pas vraiment sur si le decoupage est correcte, 
		                    //j'ai jamais eu d'erreur de plus de 512 caracteres.
	} while(lastSize == 511);
	putchar(10);

	abort();
}

Shader::~Shader()
{
	glDeleteShader(m_vertexId);
	glDeleteShader(m_pixelId);
	//Supprime les shader
	if(m_geometryId != -1) // Eventuellement le geometry shader
		glDeleteShader(m_geometryId);

	glDeleteProgram(m_shaderId);//Suprime le programme
	Application::Log("Deleted Shader", Logger::Debug);
}

shared_ptr<Shader> Shader::BasicShader()
{
	return make_shared<Shader>(ShaderRes->getString("baseVS.glsl").c_str(),
							   ShaderRes->getString("baseFS.glsl").c_str());
}
