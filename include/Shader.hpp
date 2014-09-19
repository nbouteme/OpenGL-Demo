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

	int getVSid     () { return m_vertexId; }
	int getPSid     () { return m_pixelId; }
	int getGSid     () { return m_geometryId; }
	int getProgramid() { return m_shaderId; }

};
