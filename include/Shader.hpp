#pragma once

class Shader
{
	int m_shaderId,
		m_vertexId,
		m_pixelId ,
		m_geometryId = -1;

	static void dumpShaderErrorLog(int shaderId);

public:
	Shader(const char *vs, const char *ps, const char *gs = nullptr);
	~Shader();
	int getProgramid() { return m_shaderId; }

};
