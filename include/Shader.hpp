#pragma once

#include <memory>

class Shader
{
	int m_shaderId,
		m_vertexId,
		m_pixelId ,
		m_geometryId = -1;

	static void dumpShaderErrorLog(int);

public:
	Shader(const char *, const char *, const char * = nullptr);
	~Shader();
	int getProgramid() { return m_shaderId; }
	static std::shared_ptr<Shader> BasicShader();
};
